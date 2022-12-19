### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str){
        int i = 0;
        // 跳过空格
        while(i < str.length() && str.charAt(i) == ' '){
            i += 1;
        }
        // 筛除完空格后, 字符串为空, 没有数字, 转换失败
        if(i == str.length()) return 0;

        // 是否有符号
        int signed = 1;
        if(str.charAt(i) == '+'){
            signed = 1;
            i += 1;
        }
        else if(str.charAt(i) == '-'){
            signed = -1;
            i += 1;
        }

        // 第一个非空字符只能为'+/-', 或 直接数字开始, 否则转换失败
        // 提取所有数字, 注意溢出
        int rev = 0;
        while(i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9'){
            int tmp = str.charAt(i) - 48;
            // 正数的溢出情况
            if(signed == 1){
                if(rev > Integer.MAX_VALUE / 10 || (rev==Integer.MAX_VALUE / 10 && tmp > 7)){
                    return Integer.MAX_VALUE;
                }
            }
            if(signed == -1){
                if(-rev < Integer.MIN_VALUE / 10 || (-rev==Integer.MIN_VALUE / 10 && -tmp < -8)){
                    return Integer.MIN_VALUE;
                }
            }
            rev = rev * 10 + tmp;
            i += 1;
        }
        // 首字符非法, 匹配失败rev = 0
        return signed * rev;
    }

}
```