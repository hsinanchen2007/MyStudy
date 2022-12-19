### 解题思路
方法一：正常思路可以先排序，再取中间值，中间值就是数组中出现次数超过一半的数字。

方法二：不正常思路的话，用target记录上一次访问的值，count表明当前值出现的次数，如果下一个值和当前值相同那么count++；如果不同count--，减到0的时候就要更换新的target值了，因为如果存在超过数组长度一半的值，那么最后target一定会是该值。可以这样理解，count的自加和自减就是在描述一种抵消关系，由于超过一半的出现次数，导致最后的target一定会是该值。（这种方法的时间复杂度自然会小些）

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int target = nums[0];//初始化为数组的第一个元素，接下来用于记录上一次访问的值
		int count = 1;//用于记录出现次数
		for(int i = 1;i<nums.length;i++) {
			if(target == nums[i]) {
				count++;
			}else {
				count--;
			}
			if(count == 0) {//当count=0时，更换target的值为当前访问的数组元素的值，次数设为1
				target = nums[i];
				count = 1;
			}
		}
		return target;
    }
}
```