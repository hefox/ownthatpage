<?php
/*
 * Form defination 
 */
function ownthatpage_settings() {
  $form = array();
  $form['ownthatpage'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths'),
    '#default_value' => variable_get('ownthatpage', "node,administer nodes\nnode/add,administer nodes"),
    '#description' => t('One per line additional, system path (ie "node"). If changing permission, add a comma followed by the permission. Otherwise the path itself will be removed; CAREFUL MAN.'),
  );
  
  return system_settings_form($form); 
}