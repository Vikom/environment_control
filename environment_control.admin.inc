<?php
// $Id$

/**
 * @file
 * Administrative page callbacks for the environment_control module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function environment_control_admin_settings_form($form_state) {
  $form['notice'] = array(
    '#type' => 'item',
    '#description' => t('The Environment Control will be displayed seperate ways for each environment. It will never be visible to anonymous users on production sites, but you should configure permissions for which roles it will be availible to. Current server ip is !current', array('!current' => ENVIRONMENT_CONTROL_CURRENT_IP)),
  );

  $form['environment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Environments IP'),
  );

  $form['environment']['environment_control_local'] = array(
    '#title' => t('Local environments IP adress'),
    '#type' => 'textfield',
    '#default_value' => variable_get('environment_control_local', '127.0.0.1'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => FALSE,
    '#description' => t('Set the IP adress of your local environment. Probably 127.0.0.1'),
  );

  $form['environment']['environment_control_development'] = array(
    '#title' => t('Development servers IP adress'),
    '#type' => 'textfield',
    '#default_value' => variable_get('environment_control_development'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => FALSE,
    '#description' => t('Set the IP adress of your development server'),
  );

  $form['environment']['environment_control_production'] = array(
    '#title' => t('Production servers IP adress'),
    '#type' => 'textfield',
    '#default_value' => variable_get('environment_controll_production'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => FALSE,
    '#description' => t('Set the IP adress of your production server'),
  );

  return system_settings_form($form);
}
