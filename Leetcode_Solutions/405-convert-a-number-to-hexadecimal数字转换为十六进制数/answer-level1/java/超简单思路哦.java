### 解题思路
此处撰写解题思路
每次都取num二进制后四位，根据它对应的16进制添加到结果字符串中，然后num除以16，即向右移4位，是不是超级简单。
### 代码

```java
class Solution {
    public String toHex(int num) {
        char[]c={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if(num==0) return "0";
        String ret="";
        while(num!=0){
            ret=c[num&0b1111]+ret;
            num>>>=4;
        }
        return ret;
    }
}
```