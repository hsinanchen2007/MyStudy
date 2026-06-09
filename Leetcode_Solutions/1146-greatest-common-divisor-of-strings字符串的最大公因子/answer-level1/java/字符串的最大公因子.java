### 解题思路
    本题属于Java语言的语法题。通过这个题应该掌握判断一个串是不是另一个串子串的因子的函数写法。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        for(int i=Math.min(str1.length(),str2.length());i>=1;i--)
        {
            if(judge(str1.substring(0,i),str1)&&judge(str1.substring(0,i),str2))
                return str1.substring(0,i);
        }
        return "";    
    }

    public boolean judge(String sub,String s)  //判断s是否能够被sub整除
    {
        if(s.length()%sub.length()!=0)
            return false;   //如果长度都不是整数倍，那肯定不行。
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)!=sub.charAt(i%sub.length()))
                return false;
        }
        return true;
    }
}
```