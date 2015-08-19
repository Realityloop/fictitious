<?php
/**
 * @file
 * fictitious_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function fictitious_core_default_rules_configuration() {
  $items = array();
  $items['rules_entityform_contact_emails'] = entity_import('rules_config', '{ "rules_entityform_contact_emails" : {
      "LABEL" : "Entityform: Contact emails",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "entityform" : { "label" : "Entityform Submission", "type" : "entityform" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "entityform" ],
                  "type" : "entityform",
                  "bundle" : { "value" : { "contact" : "contact" } }
                }
              },
              { "data_is" : { "data" : [ "entityform:field-contact-type" ], "value" : "support" } }
            ],
            "DO" : [
              { "mail" : {
                  "to" : "support@fictitious.inc",
                  "subject" : "[[entityform:field-contact-type]] [entityform:field-contact-subject]",
                  "message" : "First name: [entityform:field-first-name]\\r\\nLast name: [entityform:field-last-name]\\r\\nMessage:\\r\\n\\r\\n[entityform:field-contact-message]",
                  "from" : [ "entityform:field-email" ],
                  "language" : [ "" ]
                }
              },
              { "mail" : {
                  "to" : [ "entityform:field-email" ],
                  "subject" : "Thank you for contacting Fictitious Inc.",
                  "message" : "Hi [entityform:field-first-name],\\r\\n\\r\\nYour support request has been received and a Fictitious employee will be in contact within 2 working days.\\r\\n\\r\\nThank you for your patience.\\r\\n\\r\\n--\\r\\nSupport @ Fictitious Inc.\\r\\nhttp:\\/\\/fictitious.inc",
                  "from" : "support@fictitious.inc",
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "Support"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "entityform" ],
                  "type" : "entityform",
                  "bundle" : { "value" : { "contact" : "contact" } }
                }
              },
              { "data_is" : { "data" : [ "entityform:field-contact-type" ], "value" : "sales" } }
            ],
            "DO" : [
              { "mail" : {
                  "to" : "sales@fictitious.inc",
                  "subject" : "[[entityform:field-contact-type]] [entityform:field-contact-subject]",
                  "message" : "First name: [entityform:field-first-name]\\r\\nLast name: [entityform:field-last-name]\\r\\nMessage:\\r\\n\\r\\n[entityform:field-contact-message]",
                  "from" : [ "entityform:field-email" ],
                  "language" : [ "" ]
                }
              },
              { "mail" : {
                  "to" : [ "entityform:field-email" ],
                  "subject" : "Thank you for contacting Fictitious Inc.",
                  "message" : "Hi [entityform:field-first-name],\\r\\n\\r\\nThank you for contacting the Fictitious sales department. Your business is important to us and a member of the sales team will get in contact with you as soon as possible.\\r\\n\\r\\n--\\r\\nSales @ Fictitious Inc.\\r\\nhttp:\\/\\/fictitious.inc",
                  "from" : "sales@fictitious.inc",
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "Sales"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "entityform" ],
                  "type" : "entityform",
                  "bundle" : { "value" : { "contact" : "contact" } }
                }
              },
              { "data_is" : { "data" : [ "entityform:field-contact-type" ], "value" : "general" } }
            ],
            "DO" : [
              { "mail" : {
                  "to" : "info@fictitious.inc",
                  "subject" : "[[entityform:field-contact-type]] [entityform:field-contact-subject]",
                  "message" : "First name: [entityform:field-first-name]\\r\\nLast name: [entityform:field-last-name]\\r\\nMessage:\\r\\n\\r\\n[entityform:field-contact-message]",
                  "from" : [ "entityform:field-email" ],
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "General enquiry"
          }
        }
      ]
    }
  }');
  $items['rules_entityform_new_contact'] = entity_import('rules_config', '{ "rules_entityform_new_contact" : {
      "LABEL" : "Entityform: New contact",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "entityform" ],
            "type" : "entityform",
            "bundle" : { "value" : { "contact" : "contact" } }
          }
        }
      ],
      "DO" : [
        { "component_rules_entityform_contact_emails" : { "entityform" : [ "entityform" ] } }
      ]
    }
  }');
  return $items;
}
