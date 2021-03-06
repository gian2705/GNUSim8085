/*
  Copyright (C) 2003  Sridhar Ratnakumar <srid@srid.ca>
        
  This file is part of GNUSim8085.

  GNUSim8085 is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  GNUSim8085 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with GNUSim8085; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
  02110-1301, USA.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>

GtkWidget* create_window_main (void);
void create_dialog_about (void);
GtkWidget* create_window_listing (void);
GtkWidget* create_window_start (GtkWindow *);
GtkWidget* create_window_tutorial (void);
GtkWidget* create_dialog_isymbol (void);
GtkWidget* create_dialog_ireg (void);

#define HBOX(spacing) \
gtk_box_new (GTK_ORIENTATION_HORIZONTAL, spacing)
#define VBOX(spacing) \
gtk_box_new (GTK_ORIENTATION_VERTICAL, spacing)
#define HBUTTONBOX() \
gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL)

#define TABLE_ATTACH(table, widget, left, right, top, bottom, xoptions, yoptions, xpadding, ypadding) \
gtk_grid_attach (GTK_GRID (table), widget, left, top, right - left, bottom - top)
#define TABLE_ATTACH_DEFAULTS(table, widget, left, right, top, bottom) \
gtk_grid_attach (GTK_GRID (table), widget, left, top, right - left, bottom - top)
#define TABLE_SET_ROW_SPACING(table, spacing) \
gtk_grid_set_row_spacing (GTK_GRID (table), spacing)
#define TABLE_SET_COLUMN_SPACING(table, spacing) \
gtk_grid_set_column_spacing (GTK_GRID (table), spacing)

#define IMAGE_FROM_STOCK(name, size) \
	gtk_image_new_from_icon_name (name, size)
#define LABEL_STOCK_CLOSE GTK_("_Close")
#define LABEL_STOCK_OK GTK_("_OK")
#define LABEL_STOCK_PRINT GTK_("_Print")
#define IMG_STOCK_CLOSE "window-close"
#define IMG_STOCK_DIALOG_INFO "dialog-information"
#define IMG_STOCK_EXECUTE "system-run"
#define IMG_STOCK_GO_BACK "go-previous"
#define IMG_STOCK_GO_FORWARD "go-next"
#define IMG_STOCK_HELP "help-browser"
#define IMG_STOCK_JUSTIFY_FILL "format-justify-fill"
#define IMG_STOCK_KEYPAD "insert-text"
#define IMG_STOCK_MEDIA_RECORD "media-record"
#define IMG_STOCK_OK "action-ok"
#define IMG_STOCK_OPEN "document-open"
#define IMG_STOCK_PRINT "document-print"
#define IMG_STOCK_REFRESH "view-refresh"
#define IMG_STOCK_SAVE_AS "document-save-as"
