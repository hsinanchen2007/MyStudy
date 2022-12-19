在 bash 中，字符串变量里面默认**不**接受换行符，换行符会被替换为**空格**，因此可以利用这个特性来不使用数组解题。

此方法在 zsh 中无效。

Talk is cheap, show you the code.

```bash
# Read from the file file.txt and print its transposed content to stdout.

for ((i=1; i>0; i++)); do
    raw=$(awk -F ' ' "{print \$$i}" < file.txt)
    if [[ -z $raw ]]; then 
        break
    fi
    echo $raw
done
```
