```
基本思路就是先判断字符串类型
1.1如果长度小于等于1肯定符合题目要求的
1.2.1如果前两个字母都是大写那么该字符串后边不允许出现小写，如果出现小写返回false
1.2.2如果前两个字母一大一小或者两小，则该字符串后边不允许出现大写字母，如果出现大写字母返回false
1.2.3如果前两个字母一小一大，不符合要求直接返回false

```
```
func detectCapitalUse(word string) bool {
    lenWord := len(word)
    if lenWord <= 1{
        return true
    }
    types := 0
    if word[0] >= 'A' && word[0] <= 'Z' && word[1] >= 'A' && word[1] <= 'Z'{
        types = 1
    }else  if word[0] >= 'A' && word[0] <= 'Z' && word[1] >= 'a' && word[1] <= 'z'{
        types = 2
    }else  if word[0] >= 'a' && word[0] <= 'z' && word[1] >= 'a' && word[1] <= 'z'{
        types = 3
    }else{
        return false
    }
    for i := 2 ; i < lenWord; i++{
        switch types{
            case 1:
            if word[i]>='a' && word[i]<='z'{
                return false
            }
            case 2,3:
            if word[i]>='A'&&word[i]<='Z'{
                return false
            }
        }
    }
    return true

```

![image.png](https://pic.leetcode-cn.com/845122df1a8ac452023fb65a5ea061caa55e66e509786909dc2a1be6d90ac15b-image.png)