<h1><b>Smart Key - Vehicle Detection</b></h1>

<b>Overview</b>
<p>A system hich helps to identify two wheeler vehicles in hargw parking space or in a group of vehicles. The system function by pressing a button on the key and the vehicle reacts by activating it horn and turn lights (indicators) to pin point the vehiccle by the user.</p>

<b>Explanation</b>
<p>To implement the Smart Key - Vehicle Detection System as a basic prototype model we are using ESP8266 microcontroller (Node MCU), push button, buzzer, LED (optional).</p>
<p>Here we require two ESP8266 microcontroller's (Node MCU) to complete the circuit. where, one Node MCU act as master device and the other as slave device.</p>
<p>We have to establish the WiFi connection between two Node MCU so that data can be transmitted. Make sure that the both microcontrollers are connected to same WiFi network device. The one Node MCU which act as master will be integrated with a push button and the other Node MCU which act as slave be connected to the buzzer and LED.</p>
<p>When the user presses the butten connected with master device,It will send the command to the slave device through WiFi data transmission. The slave device receives the command and react to the command received from the master device by activating the buzzzer and LED by which user can detect the vehicle. </p>
<p>The master device circuit will be introduced to the vehicle key and the slave device circuit will be integrated in the vehicle. </p>
<p><b>Note:- </b> We can use any microcontroller which can support WiFi network communication or design your own system with any signalling method to establish communication between master and slave devices.</p>
