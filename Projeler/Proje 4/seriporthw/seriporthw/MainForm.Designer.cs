/*
 * Created by SharpDevelop.
 * User: abdul
 * Date: 9.12.2024
 * Time: 10:49
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace seriporthw
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Label labelCOM;
		private System.Windows.Forms.Label labelBaudrate;
		private System.Windows.Forms.Label labelDatabits;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label labelGelenVeri;
		private System.Windows.Forms.TextBox textcom;
		private System.Windows.Forms.TextBox textBaudrate;
		private System.Windows.Forms.TextBox textDatabits;
		private System.Windows.Forms.TextBox textGonderilecekVeri;
		private System.Windows.Forms.TextBox textGelenveri;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Button button3;
		private System.IO.Ports.SerialPort serialPort1;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox textADCVeri;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.labelCOM = new System.Windows.Forms.Label();
			this.labelBaudrate = new System.Windows.Forms.Label();
			this.labelDatabits = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.labelGelenVeri = new System.Windows.Forms.Label();
			this.textcom = new System.Windows.Forms.TextBox();
			this.textBaudrate = new System.Windows.Forms.TextBox();
			this.textDatabits = new System.Windows.Forms.TextBox();
			this.textGonderilecekVeri = new System.Windows.Forms.TextBox();
			this.textGelenveri = new System.Windows.Forms.TextBox();
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
			this.label1 = new System.Windows.Forms.Label();
			this.textADCVeri = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// labelCOM
			// 
			this.labelCOM.Location = new System.Drawing.Point(27, 32);
			this.labelCOM.Name = "labelCOM";
			this.labelCOM.Size = new System.Drawing.Size(100, 23);
			this.labelCOM.TabIndex = 0;
			this.labelCOM.Text = "COM No:";
			// 
			// labelBaudrate
			// 
			this.labelBaudrate.Location = new System.Drawing.Point(27, 81);
			this.labelBaudrate.Name = "labelBaudrate";
			this.labelBaudrate.Size = new System.Drawing.Size(100, 23);
			this.labelBaudrate.TabIndex = 1;
			this.labelBaudrate.Text = "Baudrate:";
			// 
			// labelDatabits
			// 
			this.labelDatabits.Location = new System.Drawing.Point(27, 125);
			this.labelDatabits.Name = "labelDatabits";
			this.labelDatabits.Size = new System.Drawing.Size(100, 23);
			this.labelDatabits.TabIndex = 2;
			this.labelDatabits.Text = "Databits:";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(27, 178);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(100, 23);
			this.label4.TabIndex = 3;
			this.label4.Text = "Gönderilecek Veri:";
			// 
			// labelGelenVeri
			// 
			this.labelGelenVeri.Location = new System.Drawing.Point(27, 300);
			this.labelGelenVeri.Name = "labelGelenVeri";
			this.labelGelenVeri.Size = new System.Drawing.Size(100, 23);
			this.labelGelenVeri.TabIndex = 4;
			this.labelGelenVeri.Text = "Gelen Veri:";
			this.labelGelenVeri.Click += new System.EventHandler(this.Label5Click);
			// 
			// textcom
			// 
			this.textcom.Location = new System.Drawing.Point(133, 29);
			this.textcom.Name = "textcom";
			this.textcom.Size = new System.Drawing.Size(100, 20);
			this.textcom.TabIndex = 5;
			this.textcom.Text = "COM10";
			// 
			// textBaudrate
			// 
			this.textBaudrate.Location = new System.Drawing.Point(133, 81);
			this.textBaudrate.Name = "textBaudrate";
			this.textBaudrate.Size = new System.Drawing.Size(100, 20);
			this.textBaudrate.TabIndex = 6;
			this.textBaudrate.Text = "115200";
			// 
			// textDatabits
			// 
			this.textDatabits.Location = new System.Drawing.Point(133, 128);
			this.textDatabits.Name = "textDatabits";
			this.textDatabits.Size = new System.Drawing.Size(100, 20);
			this.textDatabits.TabIndex = 7;
			this.textDatabits.Text = "8";
			// 
			// textGonderilecekVeri
			// 
			this.textGonderilecekVeri.Location = new System.Drawing.Point(133, 178);
			this.textGonderilecekVeri.Multiline = true;
			this.textGonderilecekVeri.Name = "textGonderilecekVeri";
			this.textGonderilecekVeri.Size = new System.Drawing.Size(167, 72);
			this.textGonderilecekVeri.TabIndex = 8;
			// 
			// textGelenveri
			// 
			this.textGelenveri.Location = new System.Drawing.Point(133, 297);
			this.textGelenveri.Multiline = true;
			this.textGelenveri.Name = "textGelenveri";
			this.textGelenveri.Size = new System.Drawing.Size(167, 72);
			this.textGelenveri.TabIndex = 9;
			this.textGelenveri.TextChanged += new System.EventHandler(this.TextGelenveriTextChanged);
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(291, 9);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(124, 58);
			this.button1.TabIndex = 10;
			this.button1.Text = "COM AÇ";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(291, 90);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(124, 58);
			this.button2.TabIndex = 11;
			this.button2.Text = "COM KAPAT";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// button3
			// 
			this.button3.Location = new System.Drawing.Point(349, 178);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(114, 58);
			this.button3.TabIndex = 12;
			this.button3.Text = "GÖNDER";
			this.button3.UseVisualStyleBackColor = true;
			this.button3.Click += new System.EventHandler(this.Button3Click);
			// 
			// serialPort1
			// 
			this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPort1DataReceived);
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(27, 426);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(62, 23);
			this.label1.TabIndex = 13;
			this.label1.Text = "ADC Verisi:";
			this.label1.Click += new System.EventHandler(this.Label1Click);
			// 
			// textADCVeri
			// 
			this.textADCVeri.Location = new System.Drawing.Point(133, 426);
			this.textADCVeri.Name = "textADCVeri";
			this.textADCVeri.Size = new System.Drawing.Size(100, 20);
			this.textADCVeri.TabIndex = 14;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(518, 559);
			this.Controls.Add(this.textADCVeri);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.textGelenveri);
			this.Controls.Add(this.textGonderilecekVeri);
			this.Controls.Add(this.textDatabits);
			this.Controls.Add(this.textBaudrate);
			this.Controls.Add(this.textcom);
			this.Controls.Add(this.labelGelenVeri);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.labelDatabits);
			this.Controls.Add(this.labelBaudrate);
			this.Controls.Add(this.labelCOM);
			this.Name = "MainForm";
			this.Text = "seriporthw";
			this.Load += new System.EventHandler(this.MainFormLoad);
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
