```sh
#sed 可以解决少行的问题
sed --quiet {10p} file.txt
#如果先用head取前10行，再用tail取最后一行，不能解决少行问题
head --lines=10 file.txt | tail --lines=1
#如果先用tail去取第十行以后的尾部，再用head去取第一行可以解决少行的问题
tail --lines=+10 file.txt | head --lines=1
#awk
awk 'NR==10' file.txt
#if-then-else-fi
lines=`head --lines=10 file.txt | wc -l`
if [[ $lines -lt 10 ]]
then
        exit
else
        head --lines=10 file.txt | tail --lines=1
fi
```