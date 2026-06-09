### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        char [] ch=s.toCharArray();
        List<String> ans=new ArrayList<>();
        for(int i=0;i<s.length()-1;i++){
            if(ch[i]=='+'&&ch[i+1]=='+'){
                ch[i]='-'; ch[i+1]='-';
                ans.add(new String(ch));
                ch[i]='+';ch[i+1]='+';
            }
        }
        return ans;
    }
}
```