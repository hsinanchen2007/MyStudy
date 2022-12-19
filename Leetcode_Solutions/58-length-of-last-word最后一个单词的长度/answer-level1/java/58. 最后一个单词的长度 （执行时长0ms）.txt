我想到从字符串尾部往前查找空格字符，然后做相应处理。

 1. 如果字符串不含空格，则直接返回字符串长度
 2. 初始化尾指针`end`，如果最后一个字符为空格，则`end`初始化为`s.length()-1`，否则为`s.length()`
 3. 如果只有一个字符，则返回`end`
 4. 从字符串的倒数第二个字符往前开始判断，如果当前字符(`i`)为空格，并且下一个字符(`i+1`)也为空格，则更新`end`为当前位置`i`；如果当前位置是空格，但是下一个字符不是空格，则直接返回最后一个单词的长度`end - i - 1`

![image.png](https://pic.leetcode-cn.com/d60cd1fa6886e939a7ee9fb2ab28c8ae86f67a063ffa87d62aff9c4d5cbfe809-image.png)
``` java []
class Solution {
    public int lengthOfLastWord(String s) {
        if(!s.contains(" ")) return s.length(); // 不包含空格，则返回原字符串长度
        // 如果最后一个字符为空格，则 end 初始化为 s.length()-1 ，否则为 s.length()
        int end = s.charAt(s.length()-1) == ' ' ?  s.length() - 1 : s.length();
        for(int i = s.length() - 2; i >= 0; i--){
            if(s.charAt(i) == ' '){	// 如果当前是空格
                if(s.charAt(i+1) == ' ')	// 且上一个也为空格
                    end = i;	// end指向当前位置
                else	// 否则直接返回最后结果
                    return end - i - 1;
            }
        }
        return end;
    }
}
```
