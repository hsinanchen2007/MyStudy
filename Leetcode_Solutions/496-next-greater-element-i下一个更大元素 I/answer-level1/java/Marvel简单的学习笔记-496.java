### 解题思路
很自然地，先想到的是哈希表，如果哈希表可以记录每个数字所在位置右边第一个比它大的数，那么只要遍历数组nums1每个元素，通过查询哈希表就能完成输出。关键在于怎么构造这个哈希表。
可以借助栈，**逆序遍历nums2**，对于第一个元素，此时栈为空，则意为它右边第一个比它大的数不存在，添加该数到-1的映射，然后将其压入栈；
接下来是第二个元素，如果它比栈顶元素（即它右边第一个元素）小，说明找到右边第一个比它大的数，添加映射后将其压入栈；
再接下来，如果元素大于等于栈顶元素，说明它右边第一个元素不满足大于它的条件，将其弹出栈，循环此操作，直至找到比它大的元素，添加映射后，压入栈。需要注意的是有可能循环后直到栈为空也找不到比它大的元素，说明不存在，同样添加其到-1的映射后压入栈。
如此这般，nums2所有元素都找到了各自右边第一个比它们大的元素，哈希表的构造就完成了。接下来遍历nums1，查询哈希表完成输出。

时间复杂度：O(n)。
空间复杂度：O(n)。

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> stack = new Stack<Integer>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = nums2.length - 1; i >= 0; i--)
        {
            int n = nums2[i];
            while(!stack.isEmpty() && n >= stack.peek())
                stack.pop();
            if(stack.isEmpty())
                map.put(n, -1);
            else
                map.put(n, stack.peek());
            stack.push(n);
        }
        int[] ans = new int[nums1.length];
        for(int i = 0; i < ans.length; i++)
            ans[i] = map.get(nums1[i]);
        return ans;
    }
}
```