### 442. [数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)
#### 题目描述
![image.png](https://pic.leetcode-cn.com/1c90e689a08656360d0636f30be3523cfc336918472b5a93513d72b80377a764-image.png)
#### 思路
-  对于数组中的元素，因为所有元素都大于0（`nums[1] > 1 > 0`），所以可以使用正负来表示出现的次数，**正**表示还没出现过，**负**表示出现过一次，因为`nums[1] > 1 > 0`，所以`Math.abs(nums[i])`为元素原值，下文使用`absx`来表示元素真正的值
    -  对于大部分的元素（`absx != len`），`nums[absx]`的正负可以表示`x`出现的次数
    -  当`x == nums.length`时数组会越界，此时将元素`x`的出现次数在`num[0]`中表示
-  由题意：元素可能出现**两次或一次**
    - 当元素x第一次出现时将`num[i]`取负数
    - 如果已经为负则表示，元素i已出现过，此次为第二次出现，将元素i加入list

#### 代码
```Java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int len = nums.length;
        for (int i = 0; i < len; i++){
            int absx = Math.abs(nums[i]);

            if (absx == len){
                if (nums[0] < 0){
                    list.add(len);
                } else{
                    nums[0] = - nums[0];
                }
            }else{
                if (nums[absx] < 0){
                    list.add(absx);
                } else{
                    nums[absx] = - nums[absx];
                }
            }
        }

        return list;
    }
}
```