### 解题思路
此处撰写解题思路

### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
cat file.txt  | grep -P "^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$|^[0-9]{3}-[0-9]{3}-[0-9]{4}$"
```