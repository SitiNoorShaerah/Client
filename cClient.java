import java.net.Socket;
import java.io.*;

public class Client
{
	public static void main(String args[])
	{
	try
	{
		System.out.println("Client Started");
		Socket sock = new Socket("192.168.92.128",36772);
		BufferedReader input = new BufferedReader(new 
			InputStreamReader(System.in));
		System.out.println("Enter your message\n");
		String str = input.readLine();
		PrintWriter out = new 
PrintWriter(sock.getOutputStream(), true);
		out.println(str);
		BufferedReader in = new BufferedReader(new 
			InputStreamReader(sock.getInputStream()));
		System.out.println(in.readLine());
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
