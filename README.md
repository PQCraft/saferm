# saferm
An rm wrapper that defeats the casual troll

## Compiling
```
gcc saferm.c -o saferm && alias rm="$(pwd)/saferm"
```
or if someone uses `/bin/rm` you can run this:
```
sudo mv /bin/rm /bin/real-rm && sudo gcc saferm.c -o /bin/rm
```
