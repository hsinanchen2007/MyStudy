执行结果：通过  显示详情 
执行用时 :3 ms, 在所有 Java 提交中击败了62.42%的用户
内存消耗 :57.8 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
很简单的，暴力解法+双指针
1、暴力解法while循环，双指针界定两个元素相加等于target
2、我们可以转换一个思路————既然两个元素相加要等于target，然后题目又告诉我们是递增数组，那么保证循环体持续执行到right指向的元素第一次遇到大于或等于target的情况就可以了，后面的元素再怎么与小的数相加也不可能等于target，所以不需要考虑。
3、最后，用一个while循环体找到相加等于target的就行，然后break退出循环（里面可以考虑去重，楼主试过不加、加的两种情况，差别不大）

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        if(nums.length == 1 || target < 2) {
            return new int[]{};
        }
        int left = 0;
        int right = 0;
        while(right+1<=nums.length-1) {
        	if(nums[right]<target && nums[right+1]>=target) {
        		break;
        	}
        	right++;
        }
        int[] num = new int[2];
        while(left < right) {
        	if(nums[left] + nums[right] == target) {
                while(left<right && nums[left] == nums[left+1]) left++;
                while(left<right && nums[right] == nums[right-1]) right--;
        		num[0] = nums[left];
        		num[1] = nums[right];
                        break;
        	}else if(nums[left] + nums[right] > target) {
        		right--;
        	}else {
        		left++;
        	}
        }
        return num;
    }
}
```