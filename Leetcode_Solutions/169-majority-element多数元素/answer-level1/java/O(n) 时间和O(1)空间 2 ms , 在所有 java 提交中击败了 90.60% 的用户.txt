### 解题思路
- 专业术语叫摩尔投票法。
- 思想：用数组中2个元素抵消法，相等+1，不等减-1，为0时重新取新下标元素。这样超过一半的元素肯定是抵消不完的，就直接返回之前赋值的元素即可。
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        // Arrays.sort(nums);
        // return nums[nums.length/2];

        int countFlag=0;
        int result = 0;
        for(int i=0;i<nums.length;i++)
        {
            //初次默认第一个。后续每次判断当countFlag为0，意味着之前元素抵消完成。
            if(countFlag==0){
               //赋值新元素作为即将可能要返回的值
                result=nums[i];
            }
            // 即将可能返回的值给当前比，相等+1，不相等-1，累计为0重新赋值新坐标元素。
            countFlag+=(result==nums[i])?1:-1;
        }
        return result;
    }
}
```