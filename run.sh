#!/bin/bash
./s2b "$@"|sed 's/<>//g;s/><//g'

