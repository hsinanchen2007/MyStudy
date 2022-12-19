### 解题思路
- 从后往前找到最大索引 k 使得a[k] a[k+1]是最后一个升序对 。若k=-1既不存在：整个数组已为完全倒叙=最后一个排列=我们按要求返回整个数组的升序表示（翻转即可）

- 找到升序对：
[a[k+1],a[n-1]]是严格递减的，代表我们已经穷尽了选择。在这个区间内选择**最后**一个比a[k]大的元素a[l]  与a[k]交换  相当于固定一个新的minimal root / starting point that follows lexicographic ordering policy  "swap next rooting before decreasing section"
新的[a[k+1],a[n-1]] 此时仍是严格递减的 = maximized  代表以新的fixed point开始的最后一个排列
所以我们需要翻转该部分使之为严格升序= minimized = 以当前fixed point开始的第一个排列
- 正确性
我们选择fixed point的步骤是optimal的 it is the minimal root we can choose at each step
构造出以optimal fixed point后序列的步骤也是optimal的 it is a minimized strictly increasing sequence   
inductively the result is the next lexicographically ordered permutation.

### 代码

```java
class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    private void reverse(int[] nums, int i, int j) {
        while(i < j) swap(nums, i++, j--);
    }
    public void nextPermutation(int[] nums) {
        int first = -1, second = -1;
        for(int i = nums.length - 2; i >= 0; i--)
            if(nums[i] < nums[i + 1]) {first = i;break;}
        if(first == -1) {reverse(nums, 0, nums.length - 1); return;}
        for(int i = nums.length - 1; i >= 0; i--) 
            if(nums[i] > nums[first]) {second = i; break;}
        swap(nums, first, second);
        reverse(nums, first + 1, nums.length - 1);
    }
}
```