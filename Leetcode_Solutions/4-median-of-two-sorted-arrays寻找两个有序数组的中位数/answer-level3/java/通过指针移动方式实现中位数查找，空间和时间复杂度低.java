### 解题思路
此处撰写解题思路
先看下单个有序数组中需要中位数的方法：
- 计算中位数的下标: 数组长度位偶数，中位数有两个，位置p1 = (length -1)/2, p2 = p1 +1，数组长度位奇数，中位数只有一个，即p1;
- 根据中位数的数组下标，取数就完成了

本题的难点是：两个数组，如果扩展的，可能会扩展到多个数组，我们还是先看看两个数组的场景。两个数组取中位数思路与但数组处理雷同，我们把两个数组虚拟成一个单数组，同样计算其中位数的数组下标（虚拟的），一旦遍历指针等于中位数下标，遍历就停止了。
问题进一步缩小到：如何在两个数组中有序的遍历，方式就是给每个数组定义一个移动指针，通过比较指针下一位置的数值大小，决定移动哪一个数组的指针，这样就实现了有序遍历。
当然整个处理过程，其边界情况必须要考虑。
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
       //空数组我们就复制一个相同的数组，一个小技巧，避免各种判断，让处理更具通用性
        if (nums1.length == 0)
            nums1 = nums2;
        if (nums2.length == 0)
            nums2 = nums1;

        if (nums1.length == 0)
            return 0;

        //计算两个数组的总长，然后算出中位数字所在的位置（虚拟位置，假设数组合并后的位置）
        int length = nums1.length + nums2.length;
        int position = (length - 1) / 2;
        double result = 0;
        //移动位数，寻找第一个中位数数组和位置
        result = findValue(nums1, nums2, position);

        //移动位置，寻找第二个中位数，长度为偶数，则需在两个连接中寻找第二个中位数
        if (length % 2 == 0) {
            int result2 = findValue(nums1, nums2, position + 1);
            result += result2;

        } else {
            result += result;
        }

        return result / 2;
    }

    static int findValue(int[] nums1, int[] nums2, int position) {
        int result = 0;
        //两个数组的移动下标
        int p1 = -1, p2 = -1;
        for (; p1 + p2 + 1 < position; ) {
            //两条链同时移动，取最小值节点作为下一个移动对象
            if (p1 + 1 < nums1.length && p2 + 1 < nums2.length) {
                if (nums1[p1 + 1] > nums2[p2 + 1]) {
                    p2++;
                    result = nums2[p2];
                } else {
                    p1++;
                    result = nums1[p1];
                }
            } else if (p1 + 1 < nums1.length) {
                p1++;
                result = nums1[p1];
            } else if (p2 + 1 < nums2.length) {
                p2++;
                result = nums2[p2];
            }
        }

        return result;
    }
}
```