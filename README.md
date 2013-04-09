# Packetyzer
https://github.com/AnwarMohamed/Packetyzer
Anwar Mohamed < anwarelmakrahy@gmail.com >
-------------------------------------------

## Abstract
----------
> Packetyzer is a high level library for C++ designed to make easier the forging and 
decoding of network packets. It has the ability to decode packets of most common network 
protocols, capture them and send them on the wire. This capability allows construction of 
tools that can probe, scan or attack networks.

> It enables the creation of networking tools in a few lines. A packet is described by its 
protocol layer type where fields of each layer have useful default values that you can overload. 
It has the ability to analyze pcap files or captured packets using Wireshark. 

> Packetyzer has the ability to capture packets, analyze them and send them over the 
wire. It analyzes the packets and the connection streams ... from the Ethernet header to the 
Application layer protocols. Packetyzer is in the form of Dynamic Link Library (DLL) that will 
help to be included in many tools and projects.


## Previous work
--------------
Scapy :  Scapy is a packet manipulation tool for computer networks, written in Python 
by Philippe Biondi. It can forge or decode packets, send them on the wire, capture them, and 
match requests and replies. It can also handle tasks like scanning, tracerouting, probing, unit 
tests, attacks, and network discovery.

Scapy provides a Python interface into libpcap, (Winpcap on Windows), in a similar way 
to that in which Wireshark provides a view and capture GUI. It can interface with a number of 
other programs to provide visualization including Wireshark for decoding packets, GnuPlot for 
providing graphs, graphviz or VPython for visualization, etc.



## Namespaces
-------------
namespace Elements
	class cFile  class cString  class cHash

namespace Generators
	class cPacketGen

namespace Analyzers
	class cPacket    class cPcapFile 

namespace Traffic
	namespace Connections
		class cTraffic    class cConnection  class cTCPReassembler
	namespace Streams
		class cUDPStream  class cConStream  class cARPStream
		class cDNSStream  class cTCPStream  class cHTTPStream
		class cICMPStream

namespace Capture
	class cWinpcapCapture
namespace Send
	class cWinpcapSend
	
	
## What's New?
--------------

![What's New?](https://dl.dropbox.com/u/71875886/Untitled.png)

## Features
-----------
> 	It has the ability to decode:
	Ethernet, ARP, IP, IP options, IGMP, ICMP, TCP, TCP options, UDP, DNS and HTTP
	The cPacket class is an abstract class designed to manage the data structure of any 
	packet, which is the base of all protocols implemented in Packetyzer. All the classes 
	derived from the cPacket class have a set of common methods as following:
	
		[*] Each packet is decoded according its own protocol type.
		[*] Packet checksum and TTL are checked to detect if the packet I forged.
		[*] Every packet is split into different headers according to its layered protocols 
			starting to Ethernet protocol until the application layer protocol.
		[*] Packetyzer it has the ability to recalculate the checksum and correct it in the 
			actual packet.
		[*] UDP & TCP data sizes are calculated and their data are parsed out into Character 
		pointers to be used later, Also TCP and IP options are parsed out.
		
> 	Extracting packets of the same session and storing them into stream structures. 
	Supported streams are: IP Streams, ARP Streams, ICMP Streams, TCP Streams, UDP 
	Streams, DNS Streams and HTTP Streams.

> 	 The ability to reassemble TCP Segments and get data buffer from the packets 
	reassembly.

> 	It can be used to extract files from capture files sent or received through HTTP protocol 
	for example.

> 	Packetyzer can capture packets using Winpcap library and sort each group according to 
	its type in a cTraffic structure.

>  	Sending raw packets on the wire that have been captured or generated by cPacketGen.

> 	A Packet Generator that can generate different types of packets. It has powerful options 
	to manipulate and craft specific packets.
	
# To-Do List
--------------
> 	Enhancing TCP Reassembler to be more intelligent.
> 	Implementing SSL , IPv6, IPv6 Options Decoders
> 	Adding Layered Service Provider class 