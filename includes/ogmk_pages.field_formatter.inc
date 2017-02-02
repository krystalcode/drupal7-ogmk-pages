<?php

/**
 * @file
 * app_commons.field_formatter.inc
 */


/**
 * Hooks.
 */

/**
 * Implements hook_field_formatter_info().
 */
function ogmk_pages_field_formatter_info() {
  return [
    // Renders entity references in a Bootstrap grid.
    /**
     * @Issue(
     *   "Move the bootstrap grid field formatters to a bootstrap-related
     *   module or to ogmk_base"
     *   type="task"
     *   priority="low"
     *   labels="modularity"
     * )
     */
    'entityreference_bootstrap_grid' => array(
      'label' => t('Bootstrap Grid'),
      'field types' => ['entityreference'],
      'settings' => array(
        'view_mode'     => 'default',
        'links'         => TRUE,
        'cols_clear'    => TRUE,
        'cols_xs'       => 12,
        'cols_sm'       => 6,
        'cols_md'       => 4,
        'cols_lg'       => 3,
        'wrapper_class' => '',
      ),
    ),
    // Renders atom references in a Bootstrap grid.
    'atom_reference_bootstrap_grid' => array(
      'label' => t('Bootstrap Grid'),
      'field types' => ['atom_reference'],
      'settings' => array(
        'context'       => '',
        'link'          => FALSE,
        'override'      => FALSE,
        'cols_clear'    => TRUE,
        'cols_xs'       => 12,
        'cols_sm'       => 6,
        'cols_md'       => 4,
        'cols_lg'       => 3,
        'wrapper_class' => '',
      ),
    ),
    // Renders links as Bootstrap buttons.
    /**
     * @Issue(
     *   "Move the link_bootstrap_button field formatter to a bootstrap-related
     *   module"
     *   type="task"
     *   priority="low"
     *   labels="modularity"
     * )
     */
    'link_bootstrap_button' => array(
      'label' => t('Bootstrap button'),
      'field types' => ['link_field'],
      'multiple values' => FIELD_BEHAVIOR_DEFAULT,
      'settings' => array(
        'brand'        => 'default',
        'icon_classes' => '',
        'position'     => 'none',
        'size'         => 'default',
      ),
    ),
  ];
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function ogmk_pages_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $function = '_ogmk_pages_field_formatter_settings_form__' . $instance['display'][$view_mode]['type'];
  if (function_exists($function)) {
    return $function($field, $instance, $view_mode, $form, $form_state);
  }

  return array();
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function ogmk_pages_field_formatter_settings_summary($field, $instance, $view_mode) {
  $function = '_ogmk_pages_field_formatter_settings_summary__' . $instance['display'][$view_mode]['type'];
  if (function_exists($function)) {
    return $function($field, $instance, $view_mode);
  }

  return '';
}

/**
 * Implements hook_field_formatter_view().
 */
function ogmk_pages_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $function = '_ogmk_pages_field_formatter_view__' . $display['type'];
  if (function_exists($function)) {
    return $function($entity_type, $entity, $field, $instance, $langcode, $items, $display);
  }

  return array();
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function ogmk_pages_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  foreach ($displays as $display) {
    $function = '_ogmk_pages_field_formatter_prepare_view__' . $display['type'];
    if (function_exists($function)) {
      $function($entity_type, $entities, $field, $instances, $langcode, $items, $displays);
    }
  }
}


/**
 * Callbacks.
 */

/**
 * Implements hook_field_formatter_settings_form() via
 * ogmk_pages_field_formatter_settings_form().
 */
function _ogmk_pages_field_formatter_settings_form__entityreference_bootstrap_grid(
  $field,
  $instance,
  $view_mode,
  $form,
  &$form_state
) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();

  // View mode to render.
  $entity_info = entity_get_info($field['settings']['target_type']);
  $view_mode_options = array('default' => t('Default'));
  if (!empty($entity_info['view modes'])) {
    foreach ($entity_info['view modes'] as $view_mode => $view_mode_settings) {
      $view_mode_options[$view_mode] = $view_mode_settings['label'];
    }
  }
  $element['view_mode'] = array(
    '#type'          => 'select',
    '#title'         => t('View mode'),
    '#description'   => t('The view mode that will be rendered within the Bootstrap Grid items.'),
    '#options'       => $view_mode_options,
    '#default_value' => $settings['view_mode'],
    '#required'      => TRUE,
    '#access'        => count($view_mode_options) > 1,
  );

  // Display links.
  $element['links'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show links'),
    '#description'   => t('Whether to display the content links such as links to view, edit or delete a node.'),
    '#default_value' => $settings['links'],
  );

  // Clear columns per device size.
  $element['cols_clear'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clear columns per device size'),
    '#description' => t(
      'When this option is selected, clearfix divs will be used to "clear" the columns as needed per device size (see related !documentation_link. This option applies only when "Single row" is selected for the "Number of columns per view row" option',
      array(
        '!documentation_link' => l(
          'Bootstrap documentation',
          'http://getbootstrap.com/css/#grid-example-mixed-complete'
        ),
      )
    ),
    '#default_value' => $settings['cols_clear'],
  );

  $column_options = _ogmk_pages_bootstrap_columns_options();
  $sizes = _ogmk_pages_bootstrap_device_sizes();
  foreach ($sizes as $size_key => $size_name) {
    $element['cols_' . $size_key] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for !size devices', array('!size' => $size_name)),
      '#description' => t('See the description on the number of columns for extra small devices.'),
      '#options' => $column_options,
      '#default_value' => $settings['cols_' . $size_key],
      '#required' => FALSE,
    );

    if ($size_key === 'xs') {
      $element['cols_' . $size_key]['#description'] = t('Choose the number of columns for a particular device size and up. Not defining the number of columns for a device size will result in inheriting the number of columns from one size below.');
      $element['cols' . $size_key]['#required'] = TRUE;
      unset($element['cols_' . $size_key]['#options'][0]);
    }
  }

  // Wrapper class.
  $element['wrapper_class'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Wrapper class'),
    '#description'   => t('If a value is defined, a wrapper div element will be created with the given class with the rendered item as its content.'),
    '#default_value' => $settings['wrapper_class'],
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_form() via
 * ogmk_pages_field_formatter_settings_form().
 */
function _ogmk_pages_field_formatter_settings_form__atom_reference_bootstrap_grid(
  $field,
  $instance,
  $view_mode,
  $form,
  &$form_state
) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();

  // Context to render.
  $contexts = scald_contexts_public();
  $context_options = array();
  foreach ($contexts as $name => $context) {
    $context_options[$name] = $context['title'];
  }
  $element['context'] = array(
    '#type'          => 'select',
    '#title'         => t('Context'),
    '#description'   => t('The context that will be rendered within the Bootstrap Grid items.'),
    '#options'       => $context_options,
    '#default_value' => $settings['context'],
    '#required'      => TRUE,
  );

  // Link to content.
  $element['link'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Link to content'),
    '#description'   => t('Whether the rendered atom should be linking to the atom view page.'),
    '#default_value' => $settings['link'],
  );

  // Allow context override.
  if (isset($instance['settings']['allow_override']) && $instance['settings']['allow_override']) {
    $element['override'] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Allow context override'),
      '#description'   => t('Allow overriding the context for each individual atom.'),
      '#default_value' => $settings['override'],
     );
  }

  // Clear columns per device size.
  $element['cols_clear'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clear columns per device size'),
    '#description' => t(
      'When this option is selected, clearfix divs will be used to "clear" the columns as needed per device size (see related !documentation_link. This option applies only when "Single row" is selected for the "Number of columns per view row" option',
      array(
        '!documentation_link' => l(
          'Bootstrap documentation',
          'http://getbootstrap.com/css/#grid-example-mixed-complete'
        ),
      )
    ),
    '#default_value' => $settings['cols_clear'],
  );

  $column_options = _ogmk_pages_bootstrap_columns_options();
  $sizes = _ogmk_pages_bootstrap_device_sizes();
  foreach ($sizes as $size_key => $size_name) {
    $element['cols_' . $size_key] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for !size devices', array('!size' => $size_name)),
      '#description' => t('See the description on the number of columns for extra small devices.'),
      '#options' => $column_options,
      '#default_value' => $settings['cols_' . $size_key],
      '#required' => FALSE,
    );

    if ($size_key === 'xs') {
      $element['cols_' . $size_key]['#description'] = t('Choose the number of columns for a particular device size and up. Not defining the number of columns for a device size will result in inheriting the number of columns from one size below.');
      $element['cols' . $size_key]['#required'] = TRUE;
      unset($element['cols_' . $size_key]['#options'][0]);
    }
  }

  // Wrapper class.
  $element['wrapper_class'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Wrapper class'),
    '#description'   => t('If a value is defined, a wrapper div element will be created with the given class with the rendered item as its content.'),
    '#default_value' => $settings['wrapper_class'],
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_form() via
 * ogmk_pages_field_formatter_settings_form().
 */
function _ogmk_pages_field_formatter_settings_form__link_bootstrap_button(
  $field,
  $instance,
  $view_mode,
  $form,
  &$form_state
) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();

  // Brand.
  $brand_options = _ogmk_pages_bootstrap_button_brands();
  $element['brand'] = array(
    '#type'          => 'select',
    '#title'         => t('Brand'),
    '#description'   => t('The brand color that will be used for styling the button.'),
    '#options'       => $brand_options,
    '#default_value' => $settings['brand'],
    '#required'      => TRUE,
  );

  // Size.
  $size_options = _ogmk_pages_bootstrap_button_sizes();
  $element['size'] = array(
    '#type'          => 'select',
    '#title'         => t('Size'),
    '#description'   => t('The size of the button.'),
    '#options'       => $size_options,
    '#default_value' => $settings['size'],
    '#required'      => TRUE,
  );

  // Icon.
  $element['icon_classes'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Icon classes'),
    '#description'   => t('Classes that will be used for adding an icon within the button at the right of the text.'),
    '#default_value' => $settings['icon_classes'],
  );

  // Position.
  $position_options = _ogmk_pages_bootstrap_button_positions();
  $element['position'] = array(
    '#type'          => 'select',
    '#title'         => t('Position'),
    '#description'   => t('Whether the button should be pulled left or right using the pull-left/pull-right bootstrap classes.'),
    '#options'       => $position_options,
    '#default_value' => $settings['position'],
    '#required'      => TRUE,
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary() via
 * ogmk_pages_field_formatter_settings_summary().
 */
function _ogmk_pages_field_formatter_settings_summary__entityreference_bootstrap_grid(
  $field,
  $instance,
  $view_mode
) {
  $settings = &$instance['display'][$view_mode]['settings'];
  $summary = array();

  $entity_info = entity_get_info($field['settings']['target_type']);
  $view_mode_label = $settings['view_mode'] == 'default' ? t('Default') : $settings['view_mode'];
  if (isset($entity_info['view modes'][$settings['view_mode']]['label'])) {
    $view_mode_label = $entity_info['view modes'][$settings['view_mode']]['label'];
  }
  $summary[] = t('Rendered as @mode', array('@mode' => $view_mode_label));

  $summary[] = !empty($settings['links']) ? t('Display links') : t('Do not display links');

  $cols_clear = $settings['cols_clear'];
  $summary[] = $cols_clear ? t('Clear columns per device size') : t('Do not clear columns per device size');

  $column_options = _ogmk_pages_bootstrap_columns_options();
  $sizes = _ogmk_pages_bootstrap_device_sizes();
  foreach ($sizes as $size_key => $size_name) {
    if ($settings['cols_' . $size_key]) {
      $summary[] = format_plural(
        $column_options[$settings['cols_' . $size_key]],
        '1 column for !size devices',
        '@count columns for !size devices',
        array(
          '!size' => $size_name,
        )
      );
    }
  }

  if (!empty($settings['wrapper_class'])) {
    $summary[] = t(
      'Wrapping items within a div element with class "@class"',
      array('@class' => $settings['wrapper_class'])
    );
  }

  if (empty($summary)) {
    return '';
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_settings_summary() via
 * ogmk_pages_field_formatter_settings_summary().
 */
function _ogmk_pages_field_formatter_settings_summary__atom_reference_bootstrap_grid(
  $field,
  $instance,
  $view_mode
) {
  $settings = &$instance['display'][$view_mode]['settings'];
  $summary = array();

  $contexts = scald_contexts_public();
  $context_label = $contexts[$settings['context']]['title'];
  $summary[] = t('Rendered as @context', array('@context' => $context_label));

  $summary[] = !empty($settings['link']) ? t('Link to content') : t('Do not link to content');

  $summary[] = !empty($settings['override']) ? t('Allow context override') : t('Do not allow context override');

  $cols_clear = $settings['cols_clear'];
  $summary[] = $cols_clear ? t('Clear columns per device size') : t('Do not clear columns per device size');

  $column_options = _ogmk_pages_bootstrap_columns_options();
  $sizes = _ogmk_pages_bootstrap_device_sizes();
  foreach ($sizes as $size_key => $size_name) {
    if ($settings['cols_' . $size_key]) {
      $summary[] = format_plural(
        $column_options[$settings['cols_' . $size_key]],
        '1 column for !size devices',
        '@count columns for !size devices',
        array(
          '!size' => $size_name,
        )
      );
    }
  }

  if (!empty($settings['wrapper_class'])) {
    $summary[] = t(
      'Wrapping items within a div element with class "@class"',
      array('@class' => $settings['wrapper_class'])
    );
  }

  if (empty($summary)) {
    return '';
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_settings_summary() via
 * ogmk_pages_field_formatter_settings_summary().
 */
function _ogmk_pages_field_formatter_settings_summary__link_bootstrap_button(
  $field,
  $instance,
  $view_mode
) {
  $settings = &$instance['display'][$view_mode]['settings'];
  $summary = array();

  $brand_options = _ogmk_pages_bootstrap_button_brands();
  $summary[] = t('Use !brand brand colors', array('!brand' => $brand_options[$settings['brand']]));

  $size_options = _ogmk_pages_bootstrap_button_sizes();
  $summary[] = t('Render in !size size', array('!size' => $size_options[$settings['size']]));

  if (!empty($settings['icon_classes'])) {
    $summary[] = t('Add an icon (!icon_classes)', array('!icon_classes' => $settings['icon_classes']));
  }

  if (!empty($settings['position']) && $settings['position'] !== 'none') {
    $summary[] = t('Pull the button to the !position', array('!position' => $settings['position']));
  }

  if (empty($summary)) {
    return '';
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view() via
 * ogmk_pages_field_formatter_view().
 *
 * Code mostly taken by the entityreference_entity_view field formatter. The
 * only difference is that we render the results using the bootstrap_grid theme.
 */
function _ogmk_pages_field_formatter_view__entityreference_bootstrap_grid(
  $entity_type,
  $entity,
  $field,
  $instance,
  $langcode,
  $items,
  $display
) {
  $result = array();
  $settings = $display['settings'];

  // Rebuild the items list to contain only those with access.
  foreach ($items as $key => $item) {
    if (empty($item['access'])) {
      unset($items[$key]);
    }
  }

  foreach ($items as $delta => $item) {
    // Protect ourselves from recursive rendering.
    static $depth = 0;
    $depth++;
    if ($depth > 20) {
      throw new EntityReferenceRecursiveRenderingException(t('Recursive rendering detected when rendering entity @entity_type(@entity_id). Aborting rendering.', array('@entity_type' => $entity_type, '@entity_id' => $item['target_id'])));
    }

    $entity = clone $item['entity'];
    unset($entity->content);
    $result[$delta] = entity_view($field['settings']['target_type'], array($item['target_id'] => $entity), $settings['view_mode'], $langcode, FALSE);

    if (empty($settings['links']) && isset($result[$delta][$field['settings']['target_type']][$item['target_id']]['links'])) {
      $result[$delta][$field['settings']['target_type']][$item['target_id']]['links']['#access'] = FALSE;
    }
    $depth = 0;
  }

  if (empty($result)) {
    return '';
  }

  $render_array = array(
    '#theme'         => 'bootstrap_grid',
    '#cols_clear'    => $settings['cols_clear'],
    '#items'         => $result,
    '#wrapper_class' => $settings['wrapper_class'],
  );

  $sizes = _ogmk_pages_bootstrap_device_sizes();
  foreach ($sizes as $size_key => $size_name) {
    $render_array['#cols_' . $size_key] = $settings['cols_' . $size_key];
  }

  return $render_array;
}

/**
 * Implements hook_field_formatter_view() via
 * ogmk_pages_field_formatter_view().
 *
 * Code mostly taken by the atom_reference context field formatters. The
 * only difference is that we render the results using the bootstrap_grid theme.
 *
 * @Issue(
 *   "Test whether the allow context override functionality works properly in
 *   the atom_reference_bootstrap_grid field formatter"
 *   type="bug"
 *   priority="low"
 *   labels="testing"
 * )
 */
function _ogmk_pages_field_formatter_view__atom_reference_bootstrap_grid(
  $entity_type,
  $entity,
  $field,
  $instance,
  $langcode,
  $items,
  $display
) {
  $contexts       = scald_contexts();
  $element        = array();
  $settings       = $display['settings'];
  $render_context = $settings['context'];

  $uri = false;

  // Check if the formatter involves a link.
  if ($settings['link']) {
    $uri = entity_uri($entity_type, $entity);
  }

  if (!empty($contexts[$render_context])) {
    foreach ($items as $delta => $item) {
      $options = array();
      if (!empty($item['options'])) {
        $options += unserialize($item['options']);
      }
      $context = $render_context;
      if (
        !empty($settings['override']) &&
        !empty($options['context'])   &&
        $options['context'] !== 'use_the_default'
      ) {
        $context = $options['context'];
      }
      $sid = $item['sid'];
      if ($uri) {
        $options['link'] = $uri['path'];
      }
      $element[$delta] = array('#markup' => scald_render($sid, $context, drupal_json_encode($options)));
    }
  }

  $render_array = array(
    '#theme'         => 'bootstrap_grid',
    '#cols_clear'    => $settings['cols_clear'],
    '#items'         => $element,
    '#wrapper_class' => $settings['wrapper_class'],
  );

  $sizes = _ogmk_pages_bootstrap_device_sizes();
  foreach ($sizes as $size_key => $size_name) {
    $render_array['#cols_' . $size_key] = $settings['cols_' . $size_key];
  }

  return $render_array;
}

/**
 * Implements hook_field_formatter_view() via
 * ogmk_pages_field_formatter_view().
 */
function _ogmk_pages_field_formatter_view__link_bootstrap_button(
  $entity_type,
  $entity,
  $field,
  $instance,
  $langcode,
  $items,
  $display
) {
  $settings = $display['settings'];

  $classes = array('btn');
  if (!empty($settings['brand'])) {
    $classes[] = 'btn-' . $settings['brand'];
  }
  if (!empty($settings['size']) && $settings['size'] !== 'default') {
    $classes[] = 'btn-' . $settings['size'];
  }
  if (!empty($settings['position']) && $settings['position'] !== 'none') {
    $classes[] = 'pull-' . $settings['position'];
  }

  $icon = '';
  if (!empty($settings['icon_classes'])) {
    $icon = '<span class="' . $settings['icon_classes'] . '"></span>';
  }

  $elements = array();
  foreach ($items as $delta => $item) {
    $item['attributes']['class'] = implode(' ', $classes);
    if ($icon) {
      $item['title'] .= ' &nbsp;' . $icon;
    }
    $elements[$delta] = array(
      '#theme'   => 'link_formatter_link_default',
      '#element' => $item,
      '#field'   => $instance,
      '#display' => $display,
    );
  }

  return $elements;
}

/**
 * Implements hook_field_formatter_prepare_view() via
 * ogmk_pages_field_formatter_prepare_view().
 */
function _ogmk_pages_field_formatter_prepare_view__entityreference_bootstrap_grid(
  $entity_type,
  $entities,
  $field,
  $instances,
  $langcode,
  &$items,
  $displays
) {
  entityreference_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, $items, $displays);
}


/**
 * Functions for internal use.
 *
 * @Issue(
 *   "Add docblocks functions for internal use"
 *   type="task"
 *   priority="low"
 *   labels="documentation"
 * )
 */

/**
 *
 */
function _ogmk_pages_bootstrap_columns_options() {
  static $options;

  if (!isset($options)) {
    $options = array(
      12 => 1,
      6 => 2,
      4 => 3,
      3 => 4,
      2 => 6,
      1 => 12,
      0 => t('Do not define'),
    );
  }

  return $options;
}

/**
 *
 */
function _ogmk_pages_bootstrap_device_sizes() {
  static $sizes;

  if (!isset($sizes)) {
    $sizes = array(
      'xs' => 'extra small',
      'sm' => 'small',
      'md' => 'medium',
      'lg' => 'large',
    );
  }

  return $sizes;
}

/**
 *
 */
function _ogmk_pages_bootstrap_button_brands() {
  static $brands;

  if (!isset($brands)) {
    $brands = array(
      'default' => t('Default'),
      'primary' => t('Primary'),
      'info'    => t('Info'),
      'success' => t('Success'),
      'warning' => t('Warning'),
      'danger'  => t('Danger'),
    );
  }

  return $brands;
}

/**
 *
 */
function _ogmk_pages_bootstrap_button_sizes() {
  static $sizes;

  if (!isset($sizes)) {
    $sizes = array(
      'xs'      => t('Extra Small'),
      'default' => t('Default'),
      'sm'      => t('Small'),
      'lg'      => t('Large'),
    );
  }

  return $sizes;
}

/**
 *
 */
function _ogmk_pages_bootstrap_button_positions() {
  static $positions;

  if (!isset($positions)) {
    $positions = array(
      'none'  => t('Do not define'),
      'left'  => t('Left'),
      'right' => t('Right'),
    );
  }

  return $positions;
}
