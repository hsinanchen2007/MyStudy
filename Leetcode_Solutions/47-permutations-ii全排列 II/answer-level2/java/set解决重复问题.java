### 解题思路
在排数中，在同一位置中  不允许出现相同的数字

### 代码

```java
class Solution {
     public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length==0){
            return res;
        }
        Arrays.sort(nums);
        boolean[] used=new boolean[nums.length];
        ArrayList<Integer> list = new ArrayList<>();

        dfs(nums,0,used,list,res );
        return res;
    }

    public void dfs(int[] nums, int cur, boolean[] used, ArrayList<Integer> list, List<List<Integer>> res ){
        if (cur==nums.length){
            res.add(new ArrayList(list));
            return;
        }

        HashSet<Integer> set = new HashSet<>();
        for (int i=0;i<nums.length;i++){
            if (used[i]){
                continue;
            }
            if (set.contains(nums[i])){
                continue;
            }
            list.add(nums[i]);
            set.add(nums[i]);
            used[i]=true;
            dfs(nums,cur+1 ,used,list,res);

            list.remove(list.size()-1);
            used[i]=false;
        }


    }
}
```