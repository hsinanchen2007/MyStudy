

### 代码

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>() ;
    public List<List<Integer>> combine(int n, int k) {
        dfs(new ArrayList<>(),n,k,1) ;
        return ans ;
    }
    public void dfs(List<Integer> temp,int n,int k,int index){
        if(temp.size() == k){
            ans.add(new ArrayList<>(temp)) ;
            return ;
        }else{
            for(int i = index ; i <= n ; i++){
                temp.add(i) ;
                dfs(temp,n,k,i+1) ;
                temp.remove(temp.size()-1) ;
            }
        }
    }
}
```