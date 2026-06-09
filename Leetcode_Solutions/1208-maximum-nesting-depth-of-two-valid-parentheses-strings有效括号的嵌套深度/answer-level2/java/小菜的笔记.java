### 解题思路
此处撰写解题思路
奇数用0标记，偶数用1标记
### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if(seq==null||seq=="")return new int[0];
        Stack<Character> stack=new Stack<>();
        int [] res=new int [seq.length()];
        for(int i=0;i<seq.length();i++){
            char s=seq.charAt(i);
            if(s=='('){
                res[i]=stack.size()%2;
                stack.push(s);
            }
            else{
                stack.pop();
                res[i]=stack.size()%2;
            }
        }
        return res;


    }
}
```