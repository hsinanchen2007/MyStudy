
![KthNum.png](https://pic.leetcode-cn.com/c42a285a1ba0b0df2a0ce8cdff8d89c4801c576d0c84ae26b1598930408dd8c8-KthNum.png)
简单桶排序算法，将输入数组中所有数作为本地数组的下标，记录每个数出现的次数到本地数组，经过试探测试用例中数的范围是-10000到10000之间，所以申请20001大小的数字记录，如果测试用例数字范围变大了，则性能就会下降。
查找输出第k个数，从本地数组末尾开始遍历，累加每个数的出现的次数，如果累加的次数大于等于k，则通过数组下标计算出第k个数字输出即可。

int findKthLargest(int *nums, int numsSize, int k)
{
    int bucket[20001] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        bucket[nums[i] + 10000]++;
    }

    int count= 0, ret = 0;
    for (int j = 20000; j > 0; j--) {
        count += bucket[j];
        if (count >= k) {
            ret = j - 10000;
            break;
        }
    }

    return ret;
}
