### 解题思路
调用java内置函数split或indexOf

# 方法一：split
split(str,limit)
1.limit<0 尽可能多的匹配 如"PALLL"，匹配"L"，结果数组长度为4
2.limit=0 同1，此外还将末尾的空格清除
3.limit>0 则模式将被最多应用 n - 1 次，数组的长度将不会大于 n，而且数组的最后一项将包含所有超出最后匹配的定界符的输入，简单理解就是，结果数组的长度不超过limit
 
```java
class Solution {
    public boolean checkRecord(String s) {
        if(s==null||s.length()==0) return true;
        return s.split("A",-1).length<=2&&s.split("LLL",-1).length<=1;
    }
}
```
效率不高6ms,也占内存！

# 方法二：indexOf和split混用
将s.split("LLL",-1).length<=1替换为s.indexOf("LLL")==-1
```java
class Solution {
    public boolean checkRecord(String s) {
        if(s==null||s.length()==0) return true;
        return s.split("A",-1).length<=2&&s.indexOf("LLL")==-1;
    }
}
```
1ms，有优化

# 方法三：单用indexOf
indexOf(str)  从0开始匹配子字符串第一个下标，不存在返回-1
indexOf(str,fromIndex) 从fromIndex开始匹配子字符串第一个下标，不存在返回-1
```java
class Solution {
    public boolean checkRecord(String s) {
        if(s==null||s.length()==0) return true;
        int tmp=s.indexOf("A");
        return (tmp==-1||s.indexOf("A",tmp+1)==-1)&&s.indexOf("LLL")==-1;
    }
}
```