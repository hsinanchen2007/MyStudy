定义一个函数f(i)表示数组中在i位置之前一共缺失了几个数字。有了这个之后，就可以用二分法来处理
如果f(i) < k ,则需要到i+1 的位置开始找;否则在i之前的位置找。如果f(last)(last表示数组的
长度减1) < k,表示结果为在nums[last]加上k - f(last);否则假设二分法返回的为last == end,
f(end)表示在end之前缺失了f(end)个数字,现在我们需要找第k个，则从end位置往前找k-f(end)+1,
所以这时候结果为nums[end] + (k - f(end))。
代码如下:
```
class Solution {
    int[] nums;

    public int missingElement(int[] nums, int k) {
        this.nums = nums;
        int start = 0, end = nums.length - 1;
        while (start < end) {
            int mid = start + ((end - start) >>> 1);
            if (f(mid) < k) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        if (f(end) >= k) {
            return nums[end] - (f(end) - k + 1);
        } else {
            return nums[end] + (k - f(end));
        }

    }

    //找出数组中在i位置之前一共缺失了几个数字
    private int f(int i) {
        return nums[i] - nums[0] - i;
    }
```
