### 解题思路
大佬的回溯法，我太菜了
### 代码

```java
class Solution {
     public List<List<Integer>> subsets(int[] nums) {
        //结果集合
        List<List<Integer>> list = new ArrayList();
        //回溯方法
        backtrack(list,new ArrayList<>(),nums,0);
        return list;
    }
    public void backtrack(List<List<Integer>>list,List<Integer>tempList,int []nums,int start){
        list.add(new ArrayList<>(tempList));
        for(int i = start;i<nums.length;i++) {
            tempList.add(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
}
```