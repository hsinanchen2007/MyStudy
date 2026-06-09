右指针`right`指向窗口右侧，左指针`left`指向窗口中最大（且最有）的元素，窗口每次移动把`nums[left]`赋值到`result`数组即可。

窗口移动时：
先确保`right - left <= k-1`, 如果`left`过小，则从`[left+1, right]`的区间寻找最大的元素，把`left`指向它；
如果`nums[right]>nums[left], left=right`

空间复杂度：O(1)
时间复杂度：
外循环执行时间复杂度为O(n),内循环执行时间复杂度为O(k)；
**最好情况时**，内部循环永远不触发， O(n)；
**最坏情况**，内部循环每次都触发（递减数列），O(n*k);
**平均情况**，
因为两两随机数相比，左边比右边大的概率为0.5，所以一个数比后续k个随机数都大的的概率为0.5^k， 
所以内部循环执行的概率 P1 = nums[left] > 后续k-1个元素的概率 = 0.5^(k-1),
内部循环不执行的概率 P2 = 1 - 0.5^(k-1),
时间复杂度 = O(n * (k * p1 + 1 * p2)) 
= O(n * (k * 0.5^(k-1) + 1 * (1 - 0.5^(k-1))) 
= O(n* (1 + (k-1)*0.5^(k-1))) 
= O(n)


```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length < 2) {
            return nums;
        }
        int left = 0;
        int[] res = new int[nums.length - (k - 1)];
        // 记窗口长度为 k 的窗口为 K，子窗口为 C
        // C.length <=k
        // C 右边界与 K 相同，C 左边界是 K 中的最大元素。
        for (int right = 0; right < nums.length; right++) {
            // 保证C.length <= k
            if (right - left > k - 1) {
                left++;
                // 保证 left 指向的是窗口中最大的数
                for (int i = left + 1; i <= right; i++) {
                    if (nums[i] >= nums[left]) {
                        left = i;
                    }
                }
            } else if (nums[right] >= nums[left]) {
                left = right;
            }
            if (right >= k - 1) {
                res[right - (k - 1)] = nums[left];
            }
            // System.out.printf("%d -> %d \n", nums[left], nums[right]);
        }
        // System.out.println(Arrays.toString(nums));
        // System.out.println(Arrays.toString(res));
        return res;
    }
}
```