### 解题思路
常规思路

### 代码

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>() ;
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null || nums.length == 0) return ans ;
        int n = nums.length ;
        helper(nums,n,new ArrayList<>(),new boolean[n]) ;
        return ans ;
    }
    public void helper(int[] nums,int n,List<Integer> temp,boolean[] visited){
        if(temp.size() == n){
            ans.add(new ArrayList<>(temp)) ;
            return ;
        }else{
            for(int i = 0 ; i < n ; i++){
                if(visited[i]) continue ;
                temp.add(nums[i]) ;
                visited[i] = true ;
                helper(nums,n,temp,visited) ;
                temp.remove(temp.size()-1) ;
                visited[i] = false ;
            }
        }
    }
}
```