### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        Stack <Character> st=new Stack <Character>();
        char[] s=S.toCharArray();
        for(int i=0;i<s.length;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(st.peek()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        String aa=new String();
        while(!st.empty())
        {
            aa=String.valueOf(st.pop())+aa;
        }
        return aa;
    }
}
```