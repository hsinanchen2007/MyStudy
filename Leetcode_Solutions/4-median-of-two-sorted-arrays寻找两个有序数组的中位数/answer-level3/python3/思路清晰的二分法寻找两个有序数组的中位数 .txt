# 二分法寻找两个有序数组的中位数

## 思路

由于题目要求时间复杂度为 O(log(m + n))，所以不能从两个有序数组的首尾挨个遍历来找到中位数（复杂度 O(m + n)）；而是要通过某种策略，通过每次比较，能够直接按比例的刷掉一组数字，最后找到中位数（复杂度 O(log(m + n))）。

这样，我们很容易能想到直接比较两个数组的中位数，然后再根据他们的大小关系，来缩小继续比较的范围。

为了防止过于抽象，我们具体来看一组例子：

1, 5, 6, 7
1, 2, 3, 4, 8, 9

数组一中位数是5和6，均大于数组二中位数3, 4。这样，我们可以认为数组一中5以及5以后的这**最后三个数字**都是大于等于最终我们要寻找的中位数的数字，这样，我们只需要记录他们中最小的数字即可，而不用在意他们每个数字究竟是多少，记录下他们中最小的数字`min_right = 5`；考虑到中位数两边数字大小关系的对称性，数组二中的**前三个数字**也必然是小于等于中位数的数字，同样道理，我们记录下他们中最大的数字`max_left = 3`。这里使用`left`表示小于等于要寻找的中位数，`right`表示大于等于要寻找的中位数。（为什么不去刷掉数组二中4以及4之前的前四个数字，和数组一中后四个数字，留给各位自己思考一下。）

经过这一步之后，剩余的数字：

1
4, 8, 9

同样的，数组一中位数1小于数组二中位数8通过比较后，可以抛去数组一的1和数组二的9，并与之前的记录作比较：`max_left = max(max_left, 1)`，即`max_left = 3`，同样地，`min_right = min(min_right, 9)`，即`min_right = 5`。

现在剩余数字：

空
4, 8

数组一已经空了，数组二的中位数为4和8，则4必然小于等于要寻找的中位数，8必然大于等于要寻找的中位数，所以`max_left = max(max_left, 4)`，即`max_left = 4`，同样地，`min_right = min(min_right, 8)`，即`min_right = 5`。

现在，数组一和数组二都已经空了，可以求出中位数为`median = (max_left + min_right) * 0.5`

## 问题和解决办法

这个思路看起来很美，但是有一个致命的问题，若两数组数字总个数为单数时，中位数只有一个，在前面的思路中，除非这个中位数一直到最后一次才被划分，则会被划分到`max_left`或`min_right`其中一个中，则最终`median = (max_left + min_right)`不能得到正确结果。

为了解决这个问题，有一个很巧妙的办法：将每个数都重复一次，保证数字总数为偶数个。这样就可以保证`max_left`和`min_right`都能包含这个中位数。
当然，我们不必真的建立两个新的数组，让每个数字重复一次，而是通过索引映射，来虚拟实现：

假设数组长度为`m`，则其索引为`0`~`m-1`。每个数字重复一次后，得到的扩展数组，则长度为`2m`,索引为`0`到`2m-1`。从扩展数组到原始数组的索引映射关系为：f(n) = n / 2.

比如：
0 1 2 3 -> 0 0 1 1 2 2 3 3
分别记作A和A',则A'[3] = A[3/2] = A[1] = 1, A'[4] = A[2] = 2.

这样，可以通过扩展数组的索引映射，虚拟的实现扩展数组，来保证中位数是两个数字，就可以通过前面的思路求得中位数了。

大家可以自己用例子，将包含扩展数字的完整的思路试一遍，覆盖一下各个情况，让思路变得更加清晰。

## 代码

```cpp []
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto m = nums1.size();
        auto n = nums2.size();
        if (m <= n)
        {
            size_t head1 = 0, tail1 = 2 * m, head2 = 0, tail2 = 2 * n;
            int leftMax = INT32_MIN, rightMin = INT32_MAX;
            while (true)
            {
                auto indexLeftMedian1 = (head1 + tail1 - 1) >> 1;
                auto indexRightMedian1 = (head1 + tail1) >> 1;
                auto indexLeftMedian2 = (head2 + tail2 - 1) >> 1;
                auto indexRightMedian2 = (head2 + tail2) >> 1;

                auto medianLeft1 = (head1 == tail1) ? INT32_MIN : nums1[indexLeftMedian1 >> 1];
                auto medianRight1 = (head1 == tail1) ? INT32_MAX : nums1[indexRightMedian1 >> 1];
                auto medianLeft2 = (head2 == tail2) ? INT32_MIN : nums2[indexLeftMedian2 >> 1];
                auto medianRight2 = (head2 == tail2) ? INT32_MAX : nums2[indexRightMedian2 >> 1];

                if (medianLeft1 > medianRight2)
                {
                    size_t moveLength = tail1 - indexLeftMedian1;
                    tail1 = indexLeftMedian1;
                    head2 = head2 + moveLength;
                    leftMax = max(leftMax, nums2[(head2 - 1) >> 1]);
                    rightMin = min(rightMin, medianLeft1);
                }
                else if (medianRight1 < medianLeft2)
                {
                    size_t moveLength = indexRightMedian1 + 1 - head1;
                    head1 = indexRightMedian1 + 1;
                    tail2 = tail2 - moveLength;
                    leftMax = max(leftMax, medianRight1);
                    rightMin = min(rightMin, nums2[tail2 >> 1]);
                }
                else
                {
                    leftMax = max(leftMax, max(medianLeft1, medianLeft2));
                    rightMin = min(rightMin, min(medianRight1, medianRight2));
                    break;
                }
            }
            return (leftMax + rightMin) * 0.5;
        }
        else
        {
            return findMedianSortedArrays(nums2, nums1);
        }
    }
};
```
```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1); n = len(nums2)
        if m <= n :
            head1, tail1, head2, tail2 = 0, 2*m, 0, 2*n
            leftMax, rightMin = -float("inf"), float("inf")
            while True:
                indexLeftMedian1 = (head1 + tail1 - 1) >> 1
                indexRightMedian1 = (head1 + tail1) >> 1
                indexLeftMedian2 = (head2 + tail2 - 1) >> 1
                indexRightMedian2 = (head2 + tail2) >> 1
                if head1 == tail1:
                    if head2 != tail2:
                        leftMax = max(leftMax, nums2[indexLeftMedian2 >> 1])
                        rightMin = min(rightMin, nums2[indexRightMedian2 >> 1])
                    break
                   
                medianLeft1 = nums1[indexLeftMedian1 >> 1]
                medianRight1 = nums1[indexRightMedian1 >> 1]
                medianLeft2 = nums2[indexLeftMedian2 >> 1]
                medianRight2 = nums2[indexRightMedian2 >> 1]

                if medianLeft1 > medianRight2 :
                    moveLength = tail1 - indexLeftMedian1
                    tail1 = indexLeftMedian1
                    head2 = head2 + moveLength
                    leftMax = max(leftMax, nums2[(head2 - 1) >> 1])
                    rightMin = min(rightMin, medianLeft1)
                elif medianRight1 < medianLeft2 :
                    moveLength = indexRightMedian1 + 1 - head1
                    head1 = indexRightMedian1 + 1
                    tail2 = tail2 - moveLength
                    leftMax = max(leftMax, medianRight1)
                    rightMin = min(rightMin, nums2[tail2 >> 1])
                else :
                    leftMax = max(leftMax, max(medianLeft1, medianLeft2))
                    rightMin = min(rightMin, min(medianRight1, medianRight2))
                    break
            return (leftMax + rightMin) / 2
        else :
            return self.findMedianSortedArrays(nums2, nums1)
```







