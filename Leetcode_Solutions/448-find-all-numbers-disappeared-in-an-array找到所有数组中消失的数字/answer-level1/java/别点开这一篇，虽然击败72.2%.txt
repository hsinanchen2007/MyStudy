### 解题思路

1. 将每个元素当做数组的下标，例如nums中的4，就将nums的第4个元素转变为-nums[4]
2. 这里要注意的是绝对值问题。
3. 例如for循环时，你先将后面的元素变成负，等你循环到的时候，就需要将负abs()转成正的index
4. 最后，将正数所在的索引+1保存到新建的ans数组中

### 代码
方法一：
```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int len = nums.length;
        List<Integer> ans = new ArrayList<Integer>();

        for(int i = 0; i < len; i++){
            nums[Math.abs(nums[i]) - 1] = - Math.abs(nums[Math.abs(nums[i]) - 1]);
        }

        for(int i = 0; i < len; i++){
            if(nums[i] > 0){
                ans.add(i+1);
            }
        }

        return ans;
    }
}
```