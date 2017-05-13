# README #

This is a (terrible) workaround for a bug that occurs when running TeamViewer on Windows 10 1703, the "Creators 
Update".

Since 1703, TeamViewer is (in many cases) unable to contact its servers unless a user is logged on locally.
This makes it difficult or impossible to use it for remote access, particularly when combined with Wake-on-LAN.

The underlying reason for this behavior is unclear, but some evidence points to a bug in the TeamViewer service
that causes the Windows firewall to erroneously block its outgoing connections. Unfortunately, it is not possible
to create a rule using the firewall GUI (`wf.msc`) that will override this block.

This program creates this rule. Similarly to the built-in rule that apparently causes the problem, this rule is
not visible in the GUI.

I am not in any way affiliated with TeamViewer; if this program makes your system unusable, blame me, not them.

## WARNING ##

This program modifies your firewall rule set in a way that is not detectable through the GUI or PowerShell
interfaces. I wrote it, but I very seriously recommend not using it. The security implications of the firewall
change may be more significant than I am currently aware of.

There is a compiled binary under "Downloads", but if you have any sense at all, you will not run it. Instead:

* read the code to make sure it does not do nefarious things
* compile it yourself, e.g. with the free Visual Studio Community IDE (it should work for this)

On second thought, if this program makes your system unusable, blame yourself, not me.

## System Requirements ##

* [Microsoft Visual C++ 2017 Redistributable package (x86)](https://download.microsoft.com/download/1/f/e/1febbdb2-aded-4e14-9063-39fb17e88444/vc_redist.x86.exe)

## Usage ##

    tvfw.exe create PATH: Create exception rule for PATH
    tvfw.exe delete: Delete exception rule

For PATH, specify the path to `teamviewer_service.exe`, this is normally `"C:\Program Files (x86)\TeamViewer\teamviewer_service.exe"` on a 64-bit OS. Be sure to include the quotes.