### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //回溯法的经典问题：
    List <String> ans=new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        char [] cs=new char[n*2];
        dfs(cs,0,n,n);
        return ans;
    }

    public void dfs(char [] cs,int k, int leftCnt, int rightCnt){
        if(leftCnt==0&&rightCnt==0)
        {
            ans.add(new String(cs));
            return ;
        }
        if(leftCnt>0){
            cs[k]='(';
            dfs(cs,k+1,leftCnt-1,rightCnt);
        }

        if(rightCnt>0&&rightCnt>leftCnt){
            cs[k]=')';
            dfs(cs,k+1,leftCnt,rightCnt-1);
        }
    }
}
```