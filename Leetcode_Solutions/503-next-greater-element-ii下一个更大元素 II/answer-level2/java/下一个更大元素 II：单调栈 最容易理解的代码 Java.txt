### 解题思路
1 首先需要解决的问题是，如何实现循环数组，即“最后一个元素的下一个元素是数组的第一个元素”。事实上，我们只要能遍历两遍数组，效果就等同于循环。虽然创建一个长度为原数组二倍的数组也可以，但为了额外空间尽可能少，这里采用取模的方式，将索引限制在小于数组长度的正整数范围内。见代码中注释。

2 维护一个单调栈，由栈顶至栈底由小到大。
（1）当遍历到数组的一个新的元素时，若栈顶比该元素小，那么对此时的栈顶来说，找到了下一个更大元素，便从栈中弹出。继续判断栈顶是否小于该元素，小于则弹出，直到栈为空或栈顶大于该元素。
（2）当栈为空或栈顶大于该元素时，直接将该元素入栈。

由于本题中未规定数组中元素无重复，所以为了唯一识别一个元素，栈中需要保存数组的索引，而不是数组元素的值。

时间复杂度 O(N)，空间复杂度O(N)

### 代码

```java
import java.util.*;

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        int[] res = new int[nums.length];
        for(int i = 0; i < res.length; i++) {
            res[i] = -1;
        }
        for(int i = 0; i < 2 * nums.length - 1; i++) {
            int index = i % nums.length; // 取模，实现循环数组
            while(!stack.isEmpty() && nums[stack.peek()] < nums[index]) { // 找到下一个更大元素
                res[stack.pop()] = nums[index]; // 栈中保存的是索引
            }
            stack.push(index);         
        }
        return res;
    }
}
```