### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void backtrack(int i,int []nums,List<Integer>item,List<List<Integer>> result)
    {
        if(i>=nums.length)
        return;
        item.add(nums[i]);
        result.add(new ArrayList(item));
        backtrack(i+1,nums,item,result);
        item.remove(Integer.valueOf(nums[i]));
        backtrack(i+1,nums,item,result);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result=new ArrayList<>();
        List<Integer>item=new ArrayList<>();
        result.add(new ArrayList<Integer>());
        backtrack(0,nums,item,result);
        return result;
        

    }
}
```