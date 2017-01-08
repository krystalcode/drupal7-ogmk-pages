<?php
/**
 * @file
 * ogmk_pages.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ogmk_pages_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'ogmk_paragraphs'.
  $field_bases['ogmk_paragraphs'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'ogmk_paragraphs',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
