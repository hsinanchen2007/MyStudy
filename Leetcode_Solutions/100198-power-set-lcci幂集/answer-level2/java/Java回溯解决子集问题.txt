### 解题思路

![大致思路.png](https://pic.leetcode-cn.com/168d8441147d723053a3694b8d39ed8f2b8fc26309bcbfe1cec586992f59b81d-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)


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