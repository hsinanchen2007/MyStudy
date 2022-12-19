### 解题思路
感觉不能直接假定数组总是存在最多元素，我就给了一个判定，如若找不到nums[nums.length/2]这个元素大于n/2，则返回一个-1，这样就能严谨一点，个人看法，欢迎点评，不喜勿喷

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int count1 = 0;
        int count2 = 0;
        for(int i = nums.length/2;i>=0;i--) {
        	if(nums[i] == nums[nums.length/2]) {
        		count1+=1;
        	}
        }
        for(int j = nums.length /2;j<=nums.length-1;j++) {
        	if(nums[j] == nums[nums.length/2]) {
        		count2+=1;
        	}
        }
        if(count1+count2>=nums.length/2) {
        	return nums[nums.length/2];
        }
        return -1;
    }
}
```