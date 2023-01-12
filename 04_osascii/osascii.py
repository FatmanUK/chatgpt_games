import platform

distro = platform.linux_distribution()[0]

if distro == "Ubuntu":
    print("""
     _____
    (, /    )
       /---(
    ) / ____)
   (_____/""")
elif distro == "Fedora":
    print("""
     _____
    (, /    )
       /---(
    ) / ____)
   (_____/""")
else:
    print("""
    _  _
  -(.)(.)-
   |    |
   |_||_|""")

