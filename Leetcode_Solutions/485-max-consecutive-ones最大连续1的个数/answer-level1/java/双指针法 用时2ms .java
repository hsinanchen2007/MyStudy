执行用时 :2 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :39 MB, 在所有 java 提交中击败了94.95%的用户
```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int front = 0;
        int last = 0;
        int res = 0;
        while (last < nums.length) {
        	if (nums[last] == 1) {
        		last ++;
        	}
            /** 若出现0 保存当前最大连续值 重置指针*/
        	else {
        		res = Math.max(res, last - front);
        		front = last + 1;
        		last = front;
        	}
        }
        /** 判断最后的连续值是否是最大值 */
        res = Math.max(res, last - front);
        
        return res;
    }
}