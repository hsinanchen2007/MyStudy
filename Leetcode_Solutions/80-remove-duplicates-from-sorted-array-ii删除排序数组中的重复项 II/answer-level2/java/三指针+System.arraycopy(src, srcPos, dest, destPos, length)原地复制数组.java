![2020013001.PNG](https://pic.leetcode-cn.com/8803b259bff891192142733c675ec8d776fd7370c11dd5dcfef76edb16701d33-2020013001.PNG)

### 解题思路
遍历一遍数组(使用System.arraycopy(src, srcPos, dest, destPos, length)复制数组);
声明指针leftIndex记录出现次数不超过两次的元素的位置;
声明指针rightIndex记录删除重复元素后当前数组的长度;
声明指针i(初始为1),用来遍历数组;
声明count(初始为1)记录重复元素的个数;
当count==2时,leftIndex=i;
当count>2时,更新count,i和rightIndex的值:
---i = leftIndex+1;
---rightIndex = rightIndex-(i-leftIndex-1),这种情况是当i出现在数组中间位置时;
---或rightIndex = rightIndex-(i-leftIndex),这种情况是当i出现在数组末尾时；
---count=1;
当循环终止(终止条件i<rightIndex)时,返回rightIndex;

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int leftIndex =0;
        int i = 1;
		int temp=0;
        int count = 1;
        int rightIndex = nums.length;
        while(i<rightIndex) {
        	if(nums[i]==nums[i-1]) {
        		count++;
        		if(count==2) {
        			leftIndex=i;
        		}
        	}
        	if(nums[i]!=nums[i-1]||i==rightIndex-1) {
        		if(count>2) {
        			if(i==rightIndex-1&&nums[i]==nums[i-1]) {
        				temp=i-leftIndex;
        			}else if((i!=nums.length-1)||(i==nums.length-1&&nums[i]!=nums[i-1])){
        				temp=i-leftIndex-1;
        			}
        			System.arraycopy(nums, i, nums, leftIndex+1, nums.length-i);
        			rightIndex = rightIndex-temp;
        			i=leftIndex+1;
        		}
        		count=1;
        	}
        	i++;
        }
    	return rightIndex;
    }
}
```