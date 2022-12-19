### 解题思路
本题的重点首先是审题，审清题目自然问题就迎刃而解。
1.回文子序列和回文子串不一样，回文子序列不需要连续，只要求回文。而回文子串需要连续。
2.本串中只有a,b。那么共分为三种情况：
    2.1 如果为空串，0次
    2.2 如果本串为回文串，1次
    2.3 如果本串不为回文，由于所有的a都回文，所有的b都回文。因此最多删除两次，先删除a，再删除b就行。

本题的重点在于判断该串是否回文。

### 代码

```java
class Solution {
    public int removePalindromeSub(String s) {
        //本题的第一个重点就是正确理解子序列的定义，子序列不一定连续。子序列不是子串。
        if(s.length()==0)
            return 0;
        boolean flag=true; //这个flag判断是否是回文串，如果是返回true，初始值是true
        char[] S=s.toCharArray();
        for(int i=0;i<s.length()/2;i++)
        {
            if(S[i]!=S[S.length-1-i])
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
            return 1;
        else
            return 2;   
    }
}
```