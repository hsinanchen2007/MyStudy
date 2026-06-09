## 分析
首先仔细分析一下单词正确的几种情况：
1. 首字母大写：
    1. 余下字母全部小写即为正确。
    2. 余下字母全部为大写即为正确。
2. 首字母小写：
    1. 字母需全部小写才为正确。
3. 特殊情况：单词只有一个字母无论大小写都为正确。
那么根据以上分析，设计算法如下：
1. 首先获取首字母判断大小写。
2. 然后循环遍历，获取第二个字母。
3. 判断后续字母的大小是否和第二个字母大小写相同。
4. 进行最终判断，当首字母大写时后续字母大小写全部一致即为 ``true``。
   当首字母小写时，第二个字母需为小写且后续字母要全部为小写即为 ``true``。

## 代码
```
public boolean detectCapitalUse(String word) {
        if(word.length() == 1){
            return true;
        }
        boolean result = true;
        // 判断开头字母大写小,true 为大写
        boolean frist = false;
        char fristBat = word.charAt(0);
        if(fristBat >= 65 && fristBat <= 90){
            frist = true;
        }
        // 后续字母的大小小，true 为大
        boolean next = false;
        for(int i = 1;i < word.length();i++ ){
            char tem = word.charAt(i);
            if(i == 1){
                if(tem >= 65 && tem <= 90){
                    next = true;
                } else {
                    next = false;
                }
            } else {
                if(next){
                    if(tem >= 65 && tem <= 90){
                        result = true;
                    } else {
                        result = false;
                        break;
                    }
                } else {
                    if(tem >= 97 && tem <= 122){
                        result = true;
                    } else {
                        result = false;
                        break;
                    }
                }
            }
        }

        if(frist && result){
            return true;
        }
        if(!frist && !next && result){
            return true;
        }
        return false;
    }
```