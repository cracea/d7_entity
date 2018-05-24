<?php


function best_authors_admin_list_page($type){
  $name = best_authors_entity_list($type);

  // return 404 if entity type is not found
  if(empty($name)){drupal_not_found();}

  $field_ui = module_exists('field_ui');
  $header = array(t('Name'), array(
    'data' => t('Operations'),
    'colspan' => $field_ui ? '2' : '0',
  ));

  $rows = array();

  // $path = str_replace('_', '-', str_replace('renv_', 'renv/', $type));
  $row = array($name);
  $path = str_replace('_', '-', $type);

  if ($field_ui) {
    // Manage fields.
    $row[] = array('data' => l(t('manage fields'), 'admin/structure/' . $path . '/fields'));
    // Display fields.
    $row[] = array('data' => l(t('manage display'), 'admin/structure/' . $path . '/display'));
  }

  $rows[] = $row;

  $output = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $output;
}