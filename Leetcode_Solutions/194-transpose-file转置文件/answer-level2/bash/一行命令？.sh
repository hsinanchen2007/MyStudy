[root@S500082 ~]# cat file.txt 
name age
alice 21
ryan 30
[root@S500082 ~]# line=`cat file.txt|wc -l`;for i in `seq 2`;do awk "{print \$$i}" file.txt|xargs -n$line;done
name alice ryan
age 21 30
[root@S500082 ~]# echo "godan 32" >> file.txt 
[root@S500082 ~]# cat file.txt 
name age
alice 21
ryan 30
godan 32
[root@S500082 ~]# line=`cat file.txt|wc -l`;for i in `seq 2`;do awk "{print \$$i}" file.txt|xargs -n$line;done
name alice ryan godan
age 21 30 32
[root@S500082 ~]# 哼