### 解题思路
此处撰写解题思路
直接grep 正则表达式

### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.


egrep -E "^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$" file.txt
```