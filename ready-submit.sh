#!/bin/bash
#
# This script prepares the project directory for submission
# All it does is set the permissions to insure everyone can read 
# the files.
#

# Set owner and group to project
echo "Setting owner and group..."
sudo chown -R project:project ../project/

# Set permissions for group members
echo "Setting permissions..."
sudo chmod -R 775 ../project/
