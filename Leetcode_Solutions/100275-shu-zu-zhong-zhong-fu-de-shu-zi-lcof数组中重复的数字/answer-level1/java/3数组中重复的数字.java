### 解题思路
方法一：由题目可知所有数字都在0~n-1范围内，如果没有重复的元素，排序之后，nums[i] = i；如果有重复的元素，一定存在另一个j使得nums[j] = nums[i] =i
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
}
```
方法二：
使用哈希表，如果nums[i]未出现过，将其添加在哈希表中，如果nums[i]已经存在哈希表中，则表明该元素重复，直接返回该元素.
```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; i++){
            if(set.contains(nums[i])){
                return nums[i];
            }
            else{
                set.add(nums[i]);
            }

            //这里循环体可以改为：
            //if(!set.add(nums[i])){
                // return nums[i];
            // }
            
        }
        return -1;
    }
}
```