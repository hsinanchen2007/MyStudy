### 解题思路
刚学Java两个星期，渣渣写一下题解，主要是为了加深自己的影响，大神忽略。。。

先判断字符串数组是否为空，如果是空的话直接返回""

若不为空，先找到字符串数组中字符最少char的数目(类似于木桶效应？)

后面两层for循环，第一层用于控制检查的char位置，最大就是前面找到的最短的字符串的长度
用布尔变量判断是否所有字符串的i位置都相同，如果一个不同，两层break直接跳出循环，记录相同
的数目，直接返回数组第一个字符串的前court位

感觉还有不少缺陷，先这样做了。。。。有时间好好完善
后续
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
            return "";
        }
        
        int strsShortestStr = strs[0].length();
         for(int i = 0; i < strs.length; ++i)
        {          
            if(strs[i].length() <= strsShortestStr)
            strsShortestStr = strs[i].length();
        }
        
        int court = 0;
        
        for(int i = 0; i < strsShortestStr; ++i)
        {
            boolean equal = true;
            for(int j = 0; j < strs.length-1; ++j)
            {
                if(strs[j].charAt(i) == strs[j+1].charAt(i))
                {                   
                    
                } else {
                    equal = false;
                    break;
                }
            }
            if(equal){
                court++;
            }else {
                break;
            }
        }
        
        if(court != 0)
        {           
            return strs[0].substring(0,court);
        } else {
            return "";
        }
    }
}
```