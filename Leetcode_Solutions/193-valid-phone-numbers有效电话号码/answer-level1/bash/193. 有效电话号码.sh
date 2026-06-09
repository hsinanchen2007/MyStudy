### 解题思路
1) bash regrex没有\d
2) (|)或是用这种表达方式

### 代码

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
input='file.txt'

while IFS= read -r line
do
    [[  $line =~ (^[0-9]{3}-|^\([0-9]{3}\)\ )[0-9]{3}-[0-9]{4}$ ]] && echo $line 
done < $input
```