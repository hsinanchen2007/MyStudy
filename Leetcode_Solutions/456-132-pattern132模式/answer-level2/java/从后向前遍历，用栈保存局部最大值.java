![image.png](https://pic.leetcode-cn.com/ba8dd0c58cd8b4ff749cbf12f5bbfd9b54bdabc3fc00984f8cf7268d24c10feb-image.png)

思想 ： （当前值表示正在遍历的值nums[i]）
利用栈来保存最大值（其实是相对于second来说最大的，但是可以理解为最大值）。
用second值来保存第二大的值
从后向前遍历，如果当前值小于第二大的值，则匹配成功。
如果当前值大于第二大的值，则说明当前值是最大值（就是前面说的，相对于second来说最大，局部最大），就要将当前值push到栈中。
但是，在push之前，要将栈中的最大值（算上当前值就是第二大的值）更新给second变量。

代码：
初始化时，将最后一个元素压栈，second变量设置为最小值，遍历从倒数第二个开始。
第一轮遍历，当前值一定大于second（second初始化为最小值），所以一定要压栈，并在压栈之前，将小于当前值的最大值 赋值给second。
第n轮遍历，当前值小于second，说明存在132模式，即 1->当前值, 2->second值, 3->栈中局部最大值。
当前值大于second，说明当前值是局部最大值，更新second和栈，进行第n+1轮遍历。
遍历结束后，没有发现存在小于second值的当前值，说明匹配132失败，返回false；

代码中写了详细的注释，可以配合画图进行理解。
（参考了 jiaxin同学 的题解）
```
class Solution {
    public boolean find132pattern(int[] nums) {

        if (nums.length <= 2) {
            return false;
        }
        // 栈中保存的是最大值
        Stack<Integer> stack = new Stack<>();
        // second为第二大的值
        int second = Integer.MIN_VALUE;
        stack.push(nums[nums.length - 1]);
        for (int i = nums.length - 2; i >= 0; i++) {

            // 如果有比second小的数出现，说明符合要求，返回true
            if (nums[i] < second) {
                return true;
            } else {
                // 否则，说明当前的值比第二的大，也就是当前值是最大值。
                // 应该把当前值放到栈中，但是在这之前要更新second，把比当前值小的最大值（第二大的值）给second
                while (!stack.isEmpty() && nums[i] > stack.peek()) {
                    second = Math.max(second, stack.pop());
                }
                stack.push(nums[i]);
            }
        }
        // 遍历整个数组，也没有发现当前值小于第二大的值，返回false
        return false;
    }
}
```

