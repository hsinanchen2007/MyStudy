```
#!/bin/env bash

column=$(awk '{print NF}' file.txt | uniq)
for((i=1;i<=column;i++))
do
  cut -d' ' -f$i file.txt|xargs
done
```

或者

```
awk '{for(i=1;i<=NF;i++){if(NR==1){row[i]=$i} else{row[i]=row[i]" "$i}}};END{for(i=1;i<=NF;i++){print row[i]}}' content.txt
```

[LeetCode上稀缺的四道shell编程题解析](https://mp.weixin.qq.com/s/EI63RZZcPzJT4c0zl8XQSA)
