<?php
/**
 * @file
 * fictitious_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fictitious_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
