### 解题思路
NR 是 awk 内部变量，记录了从开始到现在处理的记录数，也就是行数；awk 执行的时候，只有 `NR == 10` 成立，才会执行 `{ print $0}` 这个 Action 打印当前处理的整行内容，如果文件不足 10 行则不执行 Action，就不会打印任何内容。

### 代码

```bash
# Read from the file file.txt and output the tenth line to stdout.
awk 'NR == 10 {print $0}' file.txt
```