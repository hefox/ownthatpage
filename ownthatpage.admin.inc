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
    '#description' => t('One per line additional, system path (ie "node"). If changing permission, add a comma followed by the permission, ie. :path:,:permission::line break::path::line break::path::permmission:. If left blank, path itself will be removed; CAREFUL MAN.<br>For example, to change the permission of this page to "administer own that page" use "admin/settings/ownthatpage,administer own that page. You may use (single line still) pattern matching like in block visibility settings.'),
  );
  $form['ownthatpage_perm'] = array(
    '#type' => 'textarea',
    '#title' => t('Permissions'),
    '#default_value' => variable_get('ownthatpage_perm', ""),
    '#description' => t('One per line, add additional permissions that will appear in the permission tab and anywhere else that permissions appear. Do not use "do not own that page", that may be used above to exclude a path from being changed, which you may want to do if for example you wanted to get rid of admin/settings but keep admin/settings/ownthapage. IE. admin/settings/ownthatpage,do not own that page<br/>admin/settings/*.'),
  );
  $form['#submit'] = array();
  $form = system_settings_form($form); 
  $form['#submit'][] = 'ownthatpage_submit'; // rebuild
  return $form;
}

function ownthatpage_submit($form,&$form_state) {
 //FIXME why is this repeating?
 variable_set('menu_rebuild_needed', TRUE);
}