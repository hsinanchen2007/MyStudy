### 解题思路
二分查找，时间复杂度O(log(n+m))，空间复杂度O(1)，理论上代码里对于数组都是引用，不清楚为什么会突然爆90多MB内存……知道的可以提醒一下
大部分思路来自精选的题解，这里改成了非递归的形式。

思路：
找到中位数其实就是找两个数组合并后第k个元素（k=(n+m)/2)，换句话说，因为数组是从大到小排列的，所以其实是找第k小的元素。
对于两个数组给出双指针，一个指向开头一个指向结尾，对于每一次搜索比较数组前k/2个，也就是比较第k/2 -1个（下表从0开始）元素，如果左边数组比右边大，那么丢弃右边的前k/2个值，移动指针并缩减k值，最后找到的数即为第k小的数。
对于中位数，不仅要找(n+m)/2，还要考虑和为偶数情况，所以对k做处理即找(n+m+1)/2和(n+m+2)/2，最后将找到的值求和除2，这样不管是奇数（会找到同一个值）还是偶数（会找到两个值）都能很好处理了。

### 代码

```cpp
class Solution
{
public:
    int findKthMin(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n1Size = nums1.size();
        int n2Size = nums2.size();
        int n1Left = 0;
        int n1Right = n1Size - 1;
        int n2Left = 0;
        int n2Right = n2Size - 1;
        int n1CurSize, n2CurSize;
        int k1Div, k2Div;
        int k1Cur, k2Cur;

        while (k > 1)
        {
            n1CurSize = n1Right - n1Left + 1;
            n2CurSize = n2Right - n2Left + 1;

            if (n1CurSize == 0)
                return nums2[n2Left + k - 1];
            if (n2CurSize == 0)
                return nums1[n1Left + k - 1];

            k1Div = k / 2;
            k2Div = k1Div;
            k1Cur = n1Left + k1Div - 1;
            k2Cur = n2Left + k2Div - 1;

            if (k1Cur > n1Right)
            {
                k1Cur = n1Right;
                k1Div = n1CurSize;
            }
            if (k2Cur > n2Right)
            {
                k2Cur = n2Right;
                k2Div = n2CurSize;
            }

            if (nums1[k1Cur] > nums2[k2Cur])
            {
                n2Left = k2Cur + 1;
                k -= k2Div;
            }
            else
            {
                n1Left = k1Cur + 1;
                k -= k1Div;
            }
        }
        if (n1Left > n1Right)
            return nums2[n2Left];
        if (n2Left > n2Right)
            return nums1[n1Left];
        return min(nums1[n1Left], nums2[n2Left]);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1Size = nums1.size();
        int n2Size = nums2.size();
        int k1 = (n1Size + n2Size + 1) / 2;
        int k2 = (n1Size + n2Size + 2) / 2;
        double left = findKthMin(nums1, nums2, k1) / 2.0;  //(/ 2.0);
        double right = findKthMin(nums1, nums2, k2) / 2.0; //(/ 2.0);
        return left + right;
    }
};
```