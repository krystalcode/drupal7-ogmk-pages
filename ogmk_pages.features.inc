<?php
/**
 * @file
 * ogmk_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ogmk_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ogmk_pages_node_info() {
  $items = array(
    'ogmk_page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function ogmk_pages_paragraphs_info() {
  $items = array(
    'basic' => array(
      'name' => 'Basic',
      'bundle' => 'basic',
      'locked' => '1',
    ),
    'node_list' => array(
      'name' => 'Content List',
      'bundle' => 'node_list',
      'locked' => '1',
    ),
  );
  return $items;
}
