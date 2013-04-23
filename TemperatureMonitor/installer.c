/*
 * Compile using:
 * gcc -o installer installer.c -lgmp `pkg-config --cflags --libs gtk+-2.0`
 */

#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <string.h>

    GtkWidget *window;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *box;
    GtkWidget *button;
    
/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */
static void install( GtkWidget *widget, gpointer data)
{
    char path[200];

   // FILE *fp = fopen(gtk_entry_get_text(GTK_ENTRY(entry1)), "w+");
   // g_fprintf(fp, "%s", gtk_entry_get_text(GTK_ENTRY(entry2)));

    strcpy(path,"/usr/local/bin/bash ./StartApp.sh ");
    strcat(path,gtk_entry_get_text(GTK_ENTRY(entry1)));
    strcat(path," ");
    strcat(path,gtk_entry_get_text(GTK_ENTRY(entry2)));

    g_print("%s",path);
    system(path);

   // fclose(fp);
}

// Delete Event processing, returning FALSE allows the window to be destroyed, TRUE would stop further processing and window remains.
gboolean delete1 (GtkWidget *widget, GdkEvent  *event, gpointer   user_data)
{
   g_print("Hasta la vista, baby\n");
   return FALSE;
}

// Destroy signal processing (comes after delete-event=FALSE)
void destroy1 (GtkObject *object, gpointer user_data)
{
   gtk_main_quit();
}

int main( int   argc,
          char *argv[] )
{    
    gtk_init (&argc, &argv);
    
    // Create the top-level window
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    gtk_window_set_urgency_hint (GTK_WINDOW(window), TRUE);
    gtk_widget_show  (window);
    
    // Catch the window deletion to effect a clean shutdown, delete_event is where "Are You Sure?" processing goes,
    // destroy just deals with the clean-up, by this point the window has already been destroyed.
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete1), NULL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy1), NULL);
    
	// Create a vbox and attach it to the window
    box = gtk_vbox_new (FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box); 
    gtk_widget_show(box);

    // Create a label and add it to the box
    label1 = gtk_label_new ("Installation path :");
    gtk_box_pack_start (GTK_BOX (box), label1, TRUE, TRUE, 5);
    gtk_widget_show(label1);
    
    // Create an entry field and add it to the box
    entry1 = gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (box), entry1, TRUE, TRUE, 5);
    gtk_widget_show(entry1);
    gtk_widget_grab_focus(entry1);
    
    // Create a label and add it to the box
    label1 = gtk_label_new ("Threshold(°C) :");
    gtk_box_pack_start (GTK_BOX (box), label1, TRUE, TRUE, 5);
    gtk_widget_show(label1);
    
    // Create an entry field and add it to the box
    entry2 = gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (box), entry2, TRUE, TRUE, 5);
    gtk_widget_show(entry2);
    
    // Create a button and add it to the box
    button = gtk_button_new_with_label ("Install");
    gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 5);
    gtk_widget_show(button);
    
    /* When the button receives the "clicked" signal, it will call the
     * function install() passing it NULL as its argument.  The hello()
     * function is defined above. */
    g_signal_connect (button, "clicked", G_CALLBACK (install), NULL);

    gtk_main ();
    
    return 0;
}
