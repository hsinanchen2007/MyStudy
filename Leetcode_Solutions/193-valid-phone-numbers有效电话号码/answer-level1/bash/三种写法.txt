```
grep -P '^(\(\d{3}\) |\d{3}-)\d{3}-\d{4}$' file.txt
grep -P '^([(]\d{3}[)] |\d{3}-)\d{3}-\d{4}$' file.txt
grep -E '^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$' file.txt
```
[LeetCode上稀缺的四道shell编程题解析](https://mp.weixin.qq.com/s/EI63RZZcPzJT4c0zl8XQSA)