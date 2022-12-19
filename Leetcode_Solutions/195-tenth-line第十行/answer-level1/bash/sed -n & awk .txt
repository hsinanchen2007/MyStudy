### 解题思路
此处撰写解题思路

### 代码

```bash
# Read from the file file.txt and output the tenth line to stdout.

sed -n '10p' file.txt

awk 'NR==10{print $0}' file.txt

```