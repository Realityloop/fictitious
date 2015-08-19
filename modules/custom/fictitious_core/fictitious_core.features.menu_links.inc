<?php
/**
 * @file
 * fictitious_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function fictitious_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_contact:eform/submit/contact
  $menu_links['main-menu_contact:eform/submit/contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'eform/submit/contact',
    'router_path' => 'eform/submit/%',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'main-menu_contact:eform/submit/contact',
    ),
    'module' => 'entityform',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');

  return $menu_links;
}
