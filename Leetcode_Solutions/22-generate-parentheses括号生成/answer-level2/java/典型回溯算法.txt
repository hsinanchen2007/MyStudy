### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        backTrace(res,"",0,0,n);//回溯
        return res;
    }
    
    private void backTrace(List<String> res,String tmp,int open,int close,int n){
        if(tmp.length()==n*2){
            res.add(tmp);
            return;//分支结束返回。
        }
        if(open<n&open>=close){//排除不符合的结果。
            backTrace(res,tmp+"(",open+1,close,n);
        }
        if(close<n){
            backTrace(res,tmp+")",open,close+1,n);
        }
    }
}
```