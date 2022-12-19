### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> st = new Stack<>();
        StringBuilder ans = new StringBuilder();
        for(int i = 0;i < S.length();i++){
            if(!st.isEmpty()){
                if(S.charAt(i) == st.peek()){
                    st.pop();
                    continue;
                }
            }
            st.push(S.charAt(i));
        }
        while(!st.isEmpty()){
            ans.insert(0,st.peek());
            st.pop();
        }
        return ans.toString();
    }
}
```