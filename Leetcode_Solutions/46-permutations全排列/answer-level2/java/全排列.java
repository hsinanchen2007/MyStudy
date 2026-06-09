回溯算法（注意画图理解）
```
    private List<Integer> path = new ArrayList();
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ansList = new ArrayList<>();
        if(nums.length == 0) return ansList;

        solve(0, nums, ansList);
        return ansList;
    }

    private void solve(int index, int[] arr, List<List<Integer>> ansList){
        if(index == arr.length) ansList.add(new ArrayList(path)); // 注意在 java 中 path 传递的是地址，

        for(int i=0; i<arr.length; i++){
            if(path.contains(arr[i]))  continue;
            path.add(arr[i]);
            solve(index+1, arr, ansList);
            path.remove(path.size()-1);
        }

    }
```
