#### 方法一：单调栈

我们可以忽略数组 `nums1`，先对将 `nums2` 中的每一个元素，求出其下一个更大的元素。随后对于将这些答案放入哈希映射（HashMap）中，再遍历数组 `nums1`，并直接找出答案。对于 `nums2`，我们可以使用单调栈来解决这个问题。

我们首先把第一个元素 `nums2[1]` 放入栈，随后对于第二个元素 `nums2[2]`，如果 `nums2[2] > nums2[1]`，那么我们就找到了 `nums2[1]` 的下一个更大元素 `nums2[2]`，此时就可以把 `nums2[1]` 出栈并把 `nums2[2]` 入栈；如果 `nums2[2] <= nums2[1]`，我们就仅把 `nums2[2]` 入栈。对于第三个元素 `nums2[3]`，此时栈中有若干个元素，那么所有比 `nums2[3]` 小的元素都找到了下一个更大元素（即 `nums2[3]`），因此可以出栈，在这之后，我们将 `nums2[3]` 入栈，以此类推。

可以发现，我们维护了一个单调栈，栈中的元素从栈顶到栈底是单调不降的。当我们遇到一个新的元素 `nums2[i]` 时，我们判断栈顶元素是否小于 `nums2[i]`，如果是，那么栈顶元素的下一个更大元素即为 `nums2[i]`，我们将栈顶元素出栈。重复这一操作，直到栈为空或者栈顶元素大于 `nums2[i]`。此时我们将 `nums2[i]` 入栈，保持栈的单调性，并对接下来的 `nums2[i + 1], nums2[i + 2] ...` 执行同样的操作。

下面的动画中给出了一个例子。

<![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide1.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide2.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide3.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide4.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide5.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide6.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide7.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide8.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide9.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide10.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide11.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide12.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide13.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide14.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide15.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide16.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide17.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide18.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide19.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide20.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide21.JPG),![2500](https://pic.leetcode-cn.com/Figures/496_Next_Greater_Element_ISlide22.JPG)>

```Java [sol1]
public class Solution {
    public int[] nextGreaterElement(int[] findNums, int[] nums) {
        Stack < Integer > stack = new Stack < > ();
        HashMap < Integer, Integer > map = new HashMap < > ();
        int[] res = new int[findNums.length];
        for (int i = 0; i < nums.length; i++) {
            while (!stack.empty() && nums[i] > stack.peek())
                map.put(stack.pop(), nums[i]);
            stack.push(nums[i]);
        }
        while (!stack.empty())
            map.put(stack.pop(), -1);
        for (int i = 0; i < findNums.length; i++) {
            res[i] = map.get(findNums[i]);
        }
        return res;
    }
}
```

 **复杂度分析**

 * 时间复杂度：$O(M+N)$，其中 $M$ 和 $N$ 分别是数组 `nums1` 和 `nums2` 的长度。

 * 空间复杂度：$O(N)$。我们在遍历 `nums2` 时，需要使用栈，以及哈希映射用来临时存储答案。