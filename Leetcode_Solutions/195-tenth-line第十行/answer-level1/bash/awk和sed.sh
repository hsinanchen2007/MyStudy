```
#使用awk
awk "{if (NR==10)print}" file.txt
#使用sed
sed -n '10p' file.txt
```
