**执行用时 :1 ms, 在所有 Java 提交中击败了99.89%的用户
内存消耗 :36.4 MB, 在所有 Java 提交中击败了52.42%的用户**

```
List<List<Integer>> result_problem78 = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        result_problem78.clear();
        int index = 0;
        List<Integer> temp = new ArrayList<>();
        result_problem78.add(temp);   //将空List添加
        solve_problem_78(nums,index,temp);
        return result_problem78;
    }

    private void solve_problem_78(int[] nums, int index, List<Integer> temp) {
        for (int j= index; j<nums.length; j++){  //相当于将所有情况列举出来， 且不会有多余的情况算进来
            List<Integer> cur = new ArrayList<>();
            cur.addAll(temp);
            cur.add(nums[j]);
            result_problem78.add(cur);
            solve_problem_78(nums,j+1,cur);
        }
    }
```
