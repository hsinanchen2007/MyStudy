### 解题思路
方法1：
由于题目的数组条件为递增数组，所以可以采用双指针方法，一左一右，相加后与target比较，小->左指针右移，大->右指针左移，直至等于target。否则返回空数组。

方法2：
利用集合，利用增强for循环，判断当前nums[i]与集合中元素是否满足相加等于target，若没有，添加到元素，继续遍历直至满足条件。否则返回空数组。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //双指针
        // int left = 0;
        // int right = nums.length - 1;
        // while(left < right){
            
        //         if(nums[left] + nums[right] < target)
        //             left++;
        //         else if(nums[left] + nums[right] > target)
        //             right--;
        //         else 
        //             return new int[]{nums[left],nums[right]};
        //     }
        
        // return new int[]{};
        //Set集合（元素不可重复）
        Set<Integer> set = new HashSet<>();
        for(int num : nums){
            if(!set.contains(target - num))
                set.add(num);
            else
                return new int[]{num,target - num};
        }
        return new int[]{};
    }
}
```