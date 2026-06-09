### 解题思路
跟全排列Ⅰ相比，只是加了一个boolean[]做标记

### 代码

```java
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    int[] nums;
    int nums_len;
    boolean[] flag;
    public List<List<Integer>> permuteUnique(int[] nums) {
        this.nums = nums;
        this.nums_len = nums.length;
        for(int i=0;i<nums_len;i++){
            flag = new boolean[nums_len];
            List<Integer> list = new ArrayList<>();
            list.add(nums[i]);
            flag[i] = true;
            helper(list);
        }
        return lists;
    }

    private void helper(List<Integer> list) {
        if(list.size()==nums_len){
            if(lists.contains(list)){
                return;
            }else {
                lists.add(new ArrayList<>(list));
                return;
            }
        }
        for (int i=0;i<nums_len;i++){
            if(!flag[i]){
                list.add(nums[i]);
                flag[i] = true;
                helper(list);
                list.remove(list.size()-1);
                flag[i] = false;
            }else {
                continue;
            }
        }
    }
}
```