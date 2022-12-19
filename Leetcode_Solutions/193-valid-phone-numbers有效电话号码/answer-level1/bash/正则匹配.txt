### 解题思路
cat读取文件，然后利用管道符，正则匹配过滤输出结果，

### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.

    
cat file.txt | grep -E "^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$"


```