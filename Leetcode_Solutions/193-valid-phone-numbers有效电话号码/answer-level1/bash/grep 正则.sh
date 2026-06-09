### 解题思路
题目本身有迷惑性,首尾都需要判断
### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
 grep -wE "(^\([0-9]{3}\) |^[0-9]{3}-)[0-9]{3}-[0-9]{4}" file.txt
```