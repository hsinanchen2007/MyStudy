```
# 第一种方法，使用awk
# awk '{if(NR==10) {print $0}}' file.txt

# 第二种方法，使用sed
# sed -n '10p' file.txt

# 第三种方法，使用tail+head
tail -n +10 file.txt | head -1
```
