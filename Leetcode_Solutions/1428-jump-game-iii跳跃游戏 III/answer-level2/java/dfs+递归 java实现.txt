
```
class Solution {
    public boolean canReach(int[] arr, int start) {
        return dfs(arr,start,0);
    }
    
    public boolean dfs(int[] arr,int start,int count){
        if(count>arr.length||start<0||start>=arr.length){
            return false;
        }
        if(arr[start]==0){
            return true;
        }
        return dfs(arr,start+arr[start],count+1)||dfs(arr,start-arr[start],count+1);
    }
}
```
