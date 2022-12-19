### 解题思路
PCRE 匹配电话号码，正则为：
“(行首(数字重复3次-)或者(\(数字重复3次\)▢)数字重复3次-数字重复4次行尾”。

### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
grep -P '^((\d{3}-)|(\(\d{3}\) ))\d{3}-\d{4}$' file.txt
```