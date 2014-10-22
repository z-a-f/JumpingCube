import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * Create the GUI and show it.  For thread safety,
 * this method should be invoked from the
 * event-dispatching thread.
 */
public class GUI {
    public static JFrame createAndShowGUI() {
	//Create and set up the window.
	JFrame frame = new JFrame("Cool Squares");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
	JLabel emptyLabel = new JLabel("");
	emptyLabel.setPreferredSize(new Dimension(300, 300));
	frame.getContentPane().add(emptyLabel, BorderLayout.CENTER);
 
	//Display the window.
	frame.pack();
	frame.setVisible(true);

	return frame;
    }
}

