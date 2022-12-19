### 解题思路
此处撰写解题思路
分段法，从尾部到首部进行遍历，先做一个while循环，过滤掉尾部空格，
然后记录index作为end
再做一个while循环，遍历非空格字符，直到碰到一个空格，
然后end-i，整好等于长度。
### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int len=s.length()-1;
        int start=len;
        int end=len;
        
        int i=len;
        while(i>=0 && s.charAt(i)==' ')
        {
            i--;
        }
        if(i<0)
            return 0;
        end=i;
        while(i>=0 && s.charAt(i)!=' ')
        {

            i--;
        }
        return end-i;
    }
}
```