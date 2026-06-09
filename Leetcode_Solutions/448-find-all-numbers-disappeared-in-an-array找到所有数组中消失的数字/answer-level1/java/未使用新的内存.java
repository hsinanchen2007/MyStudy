### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        //遍历数组元素
        for(int i = 0; i < nums.length; i++){
            //将他的值设为新的下标
            int newIndex = Math.abs(nums[i]) - 1;
            //检查新的下标对应的值是否为负数，如果是正值，则令为负；因此，这个nums[i]在数组中已经出现过了
            if(nums[newIndex] > 0){
                nums[newIndex] *= -1;
            }
        }
        //只要将值还为正的值放进list，就是缺失的数字
        List<Integer> result = new LinkedList<Integer>();
            for(int i = 1; i <= nums.length; i++){
                if(nums[i-1] > 0)
                    result.add(i);
            }
        return result;
    }
}
```