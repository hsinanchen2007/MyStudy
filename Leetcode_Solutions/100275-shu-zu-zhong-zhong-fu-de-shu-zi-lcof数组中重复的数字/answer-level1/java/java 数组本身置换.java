### 解题思路
这种问题最快想到的是哈希表解法
但创建哈希表和对哈希表进行操作将需要额外的时间和空间
换个思路（既然数组元素的值最大不会超过数组的索引），那何不把该数组当中哈希表来使用，哈希表本身也可以看作是个数组啊！是不是！！

所以流程：
**将元素值为 i的元素交换到索引为 i的位置上（提前判断两个元素是不是相	等，相等即说明先前已经有个值为 i的元素被置换到该位置了，找到相同元素了）**

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
		//  对每个位置进行操作
        for(int i=0;i<nums.length;i++) {
			//  循环出来该位置必定是 nums[i] = i; 即到了它应该到的地方
			while(nums[i] != i) {
			//  提前判断是否相等
				if(nums[i] == nums[nums[i]]) {
					return nums[i];
				}
				//  将元素nums[i] 置换到索引为nums[i]的位置上
				else {
					int temp = nums[i];
					nums[i] = nums[nums[i]];
					nums[temp] = temp;
				}
			}
		}
		
        return -1;
    }
}
```