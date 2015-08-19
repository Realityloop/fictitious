core = 7.x
api = 2



; Drupal core

projects[drupal][type] = core
projects[drupal][version] = 7.38
; Simpletest doesn't respect 'button' element - https://www.drupal.org/node/1481148#comment-7045568
projects[drupal][patch][] = https://www.drupal.org/files/1481148-4-simpletest-button-submit.patch



; Install profile

projects[fictitious][type] = profile
projects[fictitious][download][type] = git
projects[fictitious][download][url] = https://github.com/Realityloop/fictitious.git
projects[fictitious][download][branch] = 7.x-1.x
