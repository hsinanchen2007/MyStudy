### 解题思路
- 方法1：这是我想到的方法，先排序，然后查找对应元素；
- 方法2：这是参考网友的方法，先求0---n的和，然后减去数组各元素和，即为缺失元素，这种方法效率高，相对更好

### 代码

```java
//方法1
class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        if(nums[nums.length-1]!=nums.length)
            return nums.length;
        if(nums[0]!=0)
             return 0;
        for(int i=1;i<nums.length;i++){  
            int result=nums[i-1]+1;
            if(nums[i]!=result)
                return result;
        }
        return -1;
       
        }
}
```
```java
//方法2
class Solution {
    public int missingNumber(int[] nums) {
        int sum=0;
        int cc=nums.length*(nums.length+1)/2;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        return cc-sum;
        }
}
```
