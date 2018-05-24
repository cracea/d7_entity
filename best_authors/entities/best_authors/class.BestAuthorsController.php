<?php
/**
 * @file
 * BestAuthors entity
 */

/**
 * RenvChildController class
 */
class BestAuthorsController extends EntityAPIController {

  public function create(array $values = array()) {
    global $user;
    $values += array(
      'created'   => REQUEST_TIME,
      'changed'   => 0,
      'uid'       => $user->uid,
    );
    return parent::create($values);
  }

  /**
   * Saves entity.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;

    $entity->is_new = empty($entity->id);

    if ($entity->is_new) {
      $entity->created = REQUEST_TIME;
    }
    else {
      $entity->changed = REQUEST_TIME;
    }

    $entity->is_new_revision  = TRUE;
    $entity->default_revision = TRUE;

    return parent::save($entity, $transaction);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

  }
}
