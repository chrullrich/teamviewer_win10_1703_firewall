# README #

This is a workaround for a bug that occurs when running TeamViewer on
Windows 10 1703 or later. It is independent of the TeamViewer version.
I have tested it only with version 12, but if earlier versions are
affected by the same issue, it will be effective for them as well.
Conversely, if using this program does not resolve your issue, you are
not affected by the same bug this program is designed to work around.

Since Windows 10 1703, TeamViewer is (in many cases) unable to contact
its servers unless a user is logged on locally. This makes it
difficult or impossible to use it for remote access, particularly when
combined with Wake-on-LAN.

The underlying reason for this behavior is [a bug in the TeamViewer
service](https://community.teamviewer.com/t5/TeamViewer-12/Windows-10-does-not-look-to-start-service-until-logon/td-p/6120/page/4#U7725)
that causes the Windows firewall to erroneously block its outgoing
connections. Unfortunately, it is not possible to create a rule using
the firewall GUI (`wf.msc`) that will override this block.

This program creates this rule. Similarly to the built-in rule that
apparently causes the problem, *this rule is not visible in the GUI*.

I am not in any way affiliated with TeamViewer; if this program makes
your system unusable, blame me, not them.

## WARNING ##

This program modifies your firewall rule set in a way that is not
detectable through the GUI or PowerShell interfaces. I wrote it, but I
very seriously recommend not using it. The security implications of
the firewall change may be more significant than I am currently aware
of.

There is a compiled binary under "Releases", but if you have any sense
at all, you will not run it. Instead:

* read the code to make sure it does not do nefarious things
* compile it yourself, e.g. with the free Visual Studio Community
  IDE (it should work for this)

On second thought, if this program makes your system unusable, blame
yourself, not me.

## System Requirements ##

* The correct [Microsoft Visual C++ 2015-2019 Redistributable
  package](https://support.microsoft.com/en-us/help/2977003/)
  for your system and the version of the program you are using.

## Usage ##

* `tvfw.exe create PATH` – Create exception rule for PATH
* `tvfw.exe delete` – Delete exception rule

For PATH, specify the path to `teamviewer_service.exe`, this is
normally `"C:\Program Files (x86)\TeamViewer\teamviewer_service.exe"`
on a 64-bit OS, and `"C:\Program
Files\TeamViewer\teamviewer_service.exe"` on a 32-bit OS. Be sure to
include the quotes.

## License ##

CC0, https://creativecommons.org/publicdomain/zero/1.0/
