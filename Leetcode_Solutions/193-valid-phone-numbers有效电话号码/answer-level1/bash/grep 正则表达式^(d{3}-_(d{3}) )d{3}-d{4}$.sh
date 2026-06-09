### 解题思路
grep 正则表达式^(\d{3}\-|\(\d{3}\) )\d{3}\-\d{4}$

### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.

cat file.txt|grep -P '^(\d{3}\-|\(\d{3}\) )\d{3}\-\d{4}$'
```