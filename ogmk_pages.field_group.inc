<?php
/**
 * @file
 * ogmk_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ogmk_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r1c1|node|ogmk_page|form';
  $field_group->group_name = 'group_r1c1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ogmk_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_r1';
  $field_group->data = array(
    'label' => 'Row 1 Col 1',
    'weight' => '9',
    'children' => array(
      0 => 'title_field',
      1 => 'ogmk_text_with_summary',
    ),
    'format_type' => 'bootstrap_grid_col',
    'format_settings' => array(
      'label' => 'Row 1 Col 1',
      'instance_settings' => array(
        'panelize' => '1',
        'show_heading' => '0',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '9',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r1c1 field-group-bootstrap_grid_col',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_r1c1|node|ogmk_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r1|node|ogmk_page|form';
  $field_group->group_name = 'group_r1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ogmk_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Details',
    'weight' => '0',
    'children' => array(
      0 => 'group_r1c1',
    ),
    'format_type' => 'bootstrap_grid_row',
    'format_settings' => array(
      'label' => 'Basic Details',
      'instance_settings' => array(
        'show_heading' => '1',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panelize' => '0',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '3',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r1 field-group-bootstrap_grid_row',
        'description' => 'Enter the title, the summary and the main content of the page. The main content might be not necessary if Paragraphs are used. The summary will be used as the page\'s description metatag and when the page is shared in Social Media.',
      ),
    ),
  );
  $field_groups['group_r1|node|ogmk_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r2c1|node|ogmk_page|form';
  $field_group->group_name = 'group_r2c1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ogmk_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_r2';
  $field_group->data = array(
    'label' => 'Row 2 Col 1',
    'weight' => '9',
    'children' => array(
      0 => 'ogmk_paragraphs',
    ),
    'format_type' => 'bootstrap_grid_col',
    'format_settings' => array(
      'label' => 'Row 2 Col 1',
      'instance_settings' => array(
        'panelize' => '1',
        'show_heading' => '0',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '9',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r2c1 field-group-bootstrap_grid_col',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_r2c1|node|ogmk_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r2|node|ogmk_page|form';
  $field_group->group_name = 'group_r2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ogmk_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Paragraphs',
    'weight' => '2',
    'children' => array(
      0 => 'group_r2c1',
    ),
    'format_type' => 'bootstrap_grid_row',
    'format_settings' => array(
      'label' => 'Paragraphs',
      'instance_settings' => array(
        'show_heading' => '1',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panelize' => '0',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '3',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r2 field-group-bootstrap_grid_row',
        'description' => 'You may add Paragraphs to create rich pages that contain additional text blocks, content lists, references to other blocks, or even newsletter subscription blocks.',
      ),
    ),
  );
  $field_groups['group_r2|node|ogmk_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Details');
  t('Paragraphs');
  t('Row 1 Col 1');
  t('Row 2 Col 1');

  return $field_groups;
}
