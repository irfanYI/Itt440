import java.io.*;
import java.net.*;

public class clientJ
{
	public static void main(String[] args)
	{
		try
		{
			Socket s = new Socket("192.168.24.128", 1201); //server ip and port
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String msgin="",msgout="";
			
			while(!msgin.equals("end"))
			{
				msgout = br.readLine();
				dout.writeUTF(msgout);
				msgin = din.readUTF();
				System.out.println(msgin); //print server msg
			}
		}
		catch(Exception e)
		{
			//handle exceptions
		}

	}
}
