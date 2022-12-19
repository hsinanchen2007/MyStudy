### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<String> res=new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        aget(n,"",0,0);
        return res;
    }

    private void aget(int n, String c, int open, int close) {//open为左括号，close为右括号
         if(open > n || close > n) return;//如果左括号或者右括号数超出，则返回
        if(open==n&&close==n){
            res.add(c);
            return;
        }else{
            if(open==close){
                 aget(n,c+"(",open+1,close);//如果左右括号相等，则下一个添加的必然是左括号
            }else{
                aget(n,c+"(",open+1,close);//如果左右括号不相等，下一个添加的可能是左括号或者右括号
                aget(n,c+")",open,close+1);
            }
            }
        }
}
```