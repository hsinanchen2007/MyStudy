### 解题思路
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。
目标：找到nums1中所有元素在nums2中的下一个更大元素 并返回对应的“下一个更大元素”数组
准备一个hashmap和stack
- 逆序遍历数组2维护一个单调栈（从栈底到栈顶呈单调递减）:
    - 若栈非空并且数组2当前值大于栈顶元素  持续pop...
    - //此时栈要么空了要么栈中更小的都被清除了
    - map上添加映射：   数组2当前值 -------> -1 或 栈顶元素（下一个更大元素）
    - stack.push(数组2当前值)
把结果搬移到nums1[]里并返回

逆序遍历数组并推到栈上效果：  12345  -> top 12345 bottom
例子：nums1 = [4,1,2], nums2 = [1,3,4,2]
栈4 3 1 top
MAP: 2，-1     4，-1   3，4  1，3

复杂度： nums1.length = M nums2.length = N M<=N  空间O(N)（额外的hashmap存放所有nums2中下个更大元素）
时间O(N) 第一个循环如果平铺展开的话：所有元素只会入栈一次，出栈一次或者0次，被put一次 = O(3N) 第二个循环O(M) 总共 N+M <= 2N = O(N)
### 代码
```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        for(int i = nums2.length-1; i>=0; i--){
            while(!stack.empty() && nums2[i]>stack.peek()) stack.pop();
            map.put(nums2[i], (stack.empty())? -1 : stack.peek());
            stack.push(nums2[i]);
        }
        for(int i = 0; i<nums1.length; i++){
            nums1[i] = map.get(nums1[i]);
        }
        return nums1;        
    }
}
```
