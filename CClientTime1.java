import java.io.*;
import java.util.Scanner;
import java.net.Socket;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.DateFormat;

public class ClientTime1
{
	public static void main(String args[])
{
	try
	{
	System.out.println("Client Connected");
	Socket sock = new Socket("192.168.73.135", 7778);

	Date d = new Date();
	String strDateFormat = "dd";
	DateFormat df = new SimpleDateFormat(strDateFormat);
	String formattedDate = df.format(d);
	
	PrintWriter out = new PrintWriter(sock.getOutputStream(),true);
	out.println(formattedDate);
	BufferedReader in = new 
BufferedReader(new InputStreamReader(sock.getInputStream()));
	String message = in.readLine();
	System.out.println(message);
	
	sock.close();
	}
	
	catch(Exception e)
	{
	e.printStackTrace();
	}
	}
}
