import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
 
public class Cube {
    private final static int ROWS = 5;
    private final static int COLS = 5;

    private static char[][] nums = new char[ROWS][COLS];
    private static JButton[][] button = new JButton[ROWS][COLS];
    private static JFrame frame;
    
    // Initialize:
    private static void init() {
	// Initialize the nums:
	for (int i = 0; i < ROWS; i++) {
	    for (int j = 0; j < COLS; j++) {
		nums[i][j] = '1';
	    }
	}
	// Initialize the buttons:
	
    }
    
    // Render:
    


    // Main program:
    public static void main(String[] args) {
	init();
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
		public void run() {
		    frame = GUI.createAndShowGUI();
		}
	    });
    }
}

