### 解题思路

下面这段代码并非我本人原创，是在题解中看到同志写的，通过审核，而且执行用时和内存消耗性能都很好，大家也可以跑一下试试

![925.png](https://pic.leetcode-cn.com/b5646f11ce02393a5f74c140be2539a1b5ceeb03f82c5bf2dbaf4ca47c98de6f-925.png)

但其实，深入理解这段代码，其实里面是有漏洞的，比如：
* 这段代码 没有检测 typed 字符串最后的字符是否都是等同于 name 的最后一个字符


针对这个问题，我给出了一下测试用例：

name = "alex"
typed = "aaleexabddkdhkdsb"

经过测试，返回 true，显然不符合题意

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
    int j=0;
    for(int i=0;i<typed.length();i++){
        if(name.charAt(j)==typed.charAt(i)){
            j++;
        }
        if(j==name.length())
            break;
        
    }
    return j==name.length()?true:false;   
    } 
}
```