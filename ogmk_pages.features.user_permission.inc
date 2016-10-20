<?php
/**
 * @file
 * ogmk_pages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ogmk_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ogmk_page content'.
  $permissions['create ogmk_page content'] = array(
    'name' => 'create ogmk_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ogmk_page content'.
  $permissions['delete any ogmk_page content'] = array(
    'name' => 'delete any ogmk_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ogmk_page content'.
  $permissions['delete own ogmk_page content'] = array(
    'name' => 'delete own ogmk_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ogmk_page content'.
  $permissions['edit any ogmk_page content'] = array(
    'name' => 'edit any ogmk_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ogmk_page content'.
  $permissions['edit own ogmk_page content'] = array(
    'name' => 'edit own ogmk_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'set ogmk_page published on date'.
  $permissions['set ogmk_page published on date'] = array(
    'name' => 'set ogmk_page published on date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publication_date',
  );

  return $permissions;
}
