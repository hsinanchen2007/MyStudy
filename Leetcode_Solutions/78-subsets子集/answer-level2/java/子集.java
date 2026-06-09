DFS 经典问题

```
    private List<List<Integer>> ans = new ArrayList();;
    private List<Integer> path = new ArrayList();
    public List<List<Integer>> subsets(int[] nums) {
        int len = nums.length;
        if(len == 0) return ans;
        
        ans.add(new ArrayList());
        solve(0, nums);
        return ans;
    }
    
    private void solve(int index, int[] arr){
        if(index == arr.length) return;
    
        for(int i=index; i<arr.length; i++){
            path.add(arr[i]);
            ans.add(new ArrayList(path));
            solve(i+1, arr);
            path.remove(path.size()-1);
        }
    }
```
