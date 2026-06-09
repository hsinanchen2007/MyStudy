

### 代码

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>() ;
    public List<List<Integer>> subsets(int[] nums) {
        if(nums == null || nums.length == 0) return ans ;
        dfs(new ArrayList<>(),nums,0,nums.length) ;
        return ans ;
    }
    public void dfs(List<Integer> temp,int[] nums,int index,int n){
        if(index == n){
            ans.add(new ArrayList<>(temp)) ;
            return ;
        }else{
            temp.add(nums[index]) ;
            dfs(temp,nums,index+1,n) ;
            temp.remove(temp.size()-1) ;
            dfs(temp,nums,index+1,n) ;
        }
    }
}
```