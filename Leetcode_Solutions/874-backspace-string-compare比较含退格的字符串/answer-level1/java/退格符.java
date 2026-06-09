### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        Deque<Character> s1 = new LinkedList<>();
        Deque<Character> s2 = new LinkedList<>();
        for(char c : S.toCharArray()){
            if(c=='#'){
                if(!s1.isEmpty()){
                    s1.pop();
                }
            }
            else{
                s1.push(c);
            }
        }
        for(char c : T.toCharArray()){
            if(c=='#'){
                if(!s2.isEmpty()){
                    s2.pop();
                }
            }
            else{
                s2.push(c);
            }
        }
        while(!s1.isEmpty() && !s2.isEmpty()){
            if(s1.pop() != s2.pop()){
                return false;
            }
        }
        if(!s1.isEmpty() || !s2.isEmpty()){
            return false;
        }
        else{
            return true;
        }
    }
}
```