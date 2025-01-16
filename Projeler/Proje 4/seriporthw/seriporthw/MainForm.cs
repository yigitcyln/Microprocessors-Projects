/*
 * Created by SharpDevelop.
 * User: abdul
 * Date: 9.12.2024
 * Time: 10:49
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace seriporthw
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		string gelenveri = string.Empty;
		
		private string tampon = "";
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		void Label5Click(object sender, EventArgs e)
		{
	
		}
		void Button1Click(object sender, EventArgs e)
		{
			if(!serialPort1.IsOpen)
			{
				serialPort1.PortName = textcom.Text;
				serialPort1.BaudRate = Convert.ToInt32(textBaudrate.Text);
				serialPort1.DataBits = Convert.ToInt32(textDatabits.Text);
				serialPort1.Open();
		}
	}
		void Button2Click(object sender, EventArgs e)
		{
			if(serialPort1.IsOpen)
			{
				serialPort1.Close();
			}
		}
		void Button3Click(object sender, EventArgs e)
		{
			serialPort1.Write(textGonderilecekVeri.Text);
		}
		void MainFormLoad(object sender, EventArgs e)
		{
	
		}
		void SerialPort1DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
		{
				gelenveri=serialPort1.ReadExisting();
				this.Invoke(new EventHandler(DisplayText));
		}
		private void DisplayText(object sender, EventArgs e)
		{
			 foreach (char c in gelenveri)
   			 {
      		 	 if (c == '*')
       			 {
					textGelenveri.Text = tampon;
         			tampon = ""; // Tamponu sıfır
            		return; 
       			 }

       			else
       				
       			{
       	 			tampon += c;
       			}
   			 }
		}
		void DatabitsClick(object sender, EventArgs e)
		{
	
		}
		void Label1Click(object sender, EventArgs e)
		{
	
		}
		void TextGelenveriTextChanged(object sender, EventArgs e)
		{
	
		}
	}
}

