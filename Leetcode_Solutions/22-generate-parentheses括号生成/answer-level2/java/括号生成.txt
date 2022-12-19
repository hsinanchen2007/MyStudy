### 解题思路
１.左括号还有剩余，产生左括号；
２.有多的右括号剩余，补上右括号
３.所有右括号添加完毕，生成

### 代码

```java
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        String str="";
        generate(str,n,n);
        return res;

    }
    public void generate(String valid,int left,int right){
        if(left>0)generate(valid+"(",left-1,right);
        if(right>left)generate(valid+")",left,right-1);
        if(right<=0){
            res.add(new String(valid));
        }
    }

}
```