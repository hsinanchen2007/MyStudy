### 解题思路
由于没有重复元素，只需依次增加每一个数即可，比如：1,2,3,4,5  依次加入结果集的为：
[1],[1,2],[1,2,3],[1,2,3,4],[1,2,3,4,5],[1,2,3,5],[1,2,4,5],[1,3,4,5]...
需要说明一点是，递归的逻辑嵌套很复杂，不要绕进去，如果对逻辑没理清的话，建议debug把前几种情况仔细过一遍，后面的情况就可以依照规律找出来了
另外，如果数组里面有重复元素，只需先将数组排序，然后在递归函数的循环体里面，把单次循环中数值一样的情况continue掉即可

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {

        List<List<Integer>> list = new ArrayList<>();
        list.add(new ArrayList<>());
        helper(nums, list, 0, new ArrayList<Integer>());
        return list;
    }

    private void helper(int[] nums, List<List<Integer>> list, int i, List<Integer> temp){
        if(i == nums.length){
            return;
        }
        for(int j=i; j<nums.length; j++){
            temp.add(nums[j]);
            list.add(new ArrayList<>(temp));
            helper(nums, list, j+1, temp);
            temp.remove(temp.size() - 1);
        }
        
    }
}
```