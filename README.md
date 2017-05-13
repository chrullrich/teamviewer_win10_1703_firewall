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

## Usage ##

    tvfw.exe create PATH: Create exception rule for PATH
    tvfw.exe delete: Delete exception rule

For PATH, specify the path to `teamviewer_service.exe`, this is normally `"C:\Program Files (x86)\TeamViewer\teamviewer_service.exe"` on a 64-bit OS. Be sure to include the quotes.