### 解题思路
把nums数组元素存入Set，找到重复的就存入result数组，然后遍历Set，不包含就存入result
时间复杂度为O(n)

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] result = new int[2];
        Set<Integer> set = new HashSet<>();
        for(int i = 0;i<nums.length;i++){
            if(set.contains(nums[i])){
                result[0] = nums[i];
            }else {
                set.add(nums[i]);
            }
        }
        for(int j =1;j<=nums.length;j++){
            if(!set.contains(j)){
                result[1] = j;
            }
        }
        return result;
    }
}
```