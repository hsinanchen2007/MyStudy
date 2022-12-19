### 解题思路
nextPermutation可以分两种情况，
第一个num[0]变位置, 如果nums[0]>=nums[1], 则数组倒置，即为结果
如果nums[0]<nums[1], 则先将nums[1,2,...], 然后找到第一个大于nums[0]的位置，再进行位置交换即可得到结果


第一个num[0]不变位置, 只要nums[1,2,...]之后，至少存在一个对即可(ai, aj) ai<aj; 则可以递归到nextPermutationInner(nums, 1)

### 代码

```java
/**
 * @Author : josan
 * @Date : 2020/2/7 13:27
 * @Package : leetcode.study.group002.ex0031
 * @ProjectName: pom-parent
 * @Description:
 */
public class Solution {
    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length < 2) {
            return ;
        }

        nextPermutationInner(nums, 0);
    }

    private void nextPermutationInner(int[] nums, int st) {
        if (nums.length - st <= 1) {
            return ;
        }

        int i = st + 1;
        for (; i < nums.length - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }

        if (i < nums.length - 1) {
            nextPermutationInner(nums, st + 1);
        } else {
            if (nums[st] >= nums[st + 1]) {
                reverseArray(nums, st, nums.length);
            } else {
                reverseArray(nums, st + 1, nums.length);
                int left = st + 1;
                while (left < nums.length && nums[st] >= nums[left]) {
                    ++left;
                }
                int temp = nums[st];
                nums[st] = nums[left];
                nums[left] = temp;
            }
        }
    }

    private void reverseArray(int[] nums, int st, int ed) {
        int i = st;
        int j = ed - 1;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            ++i;
            --j;
        }
    }

}

```

### 测试代码
```
package leetcode.study.group002.ex0031;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @Author : josan
 * @Date : 2020/2/2 21:07
 * @Package : leetcode.study.ex0001
 * @ProjectName: pom-parent
 * @Description:
 */
public class TestSolution {
    @Test
    public void testNextPermutation() {
        doTestNextPermutation(new int[]{1, 2, 3}, new int[]{1, 3, 2});
        doTestNextPermutation(new int[]{3, 2, 1}, new int[]{1, 2, 3});
        doTestNextPermutation(new int[]{1, 1, 5}, new int[]{1, 5, 1});
    }

    private void doTestNextPermutation(int[] nums, int[] expected) {
        Solution solution = new Solution();
        solution.nextPermutation(nums);
        Assert.assertArrayEquals("not the same", expected, nums);
    }
}

```