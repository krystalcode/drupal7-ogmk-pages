<?php
/**
 * @file
 * ogmk_pages.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ogmk_pages_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ogmk_page-ogmk_paragraphs'.
  $field_instances['node-ogmk_page-ogmk_paragraphs'] = array(
    'bundle' => 'ogmk_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'view_mode_selector',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'ogmk_paragraphs',
    'label' => 'Paragraphs',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'basic' => -1,
        'block' => -1,
        'mailing_list_subscription' => -1,
        'node_list' => -1,
      ),
      'bundle_weights' => array(
        'basic' => -6,
        'block' => -5,
        'mailing_list_subscription' => 4,
        'node_list' => -4,
      ),
      'default_edit_mode' => 'closed',
      'entity_translation_sync' => FALSE,
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-ogmk_page-ogmk_text_with_summary'.
  $field_instances['node-ogmk_page-ogmk_text_with_summary'] = array(
    'bundle' => 'ogmk_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'ogmk_text_with_summary',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'bonsai_html' => 0,
          'ogmk_basic_html' => 'ogmk_basic_html',
          'ogmk_html' => 0,
          'ogmk_plain_html' => 'ogmk_plain_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'bonsai_html' => array(
              'weight' => 0,
            ),
            'ogmk_basic_html' => array(
              'weight' => 0,
            ),
            'ogmk_html' => array(
              'weight' => 0,
            ),
            'ogmk_plain_html' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'context' => 'title',
      'context_default' => 'sdl_editor_representation',
      'display_summary' => 1,
      'dnd_enabled' => 1,
      'entity_translation_sync' => FALSE,
      'mee_enabled' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-ogmk_page-title_field'.
  $field_instances['node-ogmk_page-title_field'] = array(
    'bundle' => 'ogmk_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => TRUE,
    'settings' => array(
      'context' => '',
      'dnd_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Paragraphs');
  t('Title');

  return $field_instances;
}
