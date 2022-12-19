/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

/*

https://leetcode.cn/problems/median-of-two-sorted-arrays/

4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5


提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
通过次数750,605提交次数1,809,785

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.10, very interesting question, it looks pretty easy but actually tricky
    // below answer can pass LC, but time O() will not meet the request, however, 
    // somehow it's not that slow compared with all below answers
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> allNums;
        int size1 = nums1.size(), size2 = nums2.size();

        for (int i = 0; i < nums1.size(); i++) allNums.push_back(nums1[i]);
        for (int j = 0; j < nums2.size(); j++) allNums.push_back(nums2[j]);

        sort(allNums.begin(), allNums.end());

        int left = allNums[(size1+size2-1)/2], right = allNums[(size1+size2)/2];

        return (left+right)/2.0;
    }
};


class Solution99 {
public:
    // 2022.7.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/median-of-two-sorted-arrays.cpp
    // Time:  O(log(min(m, n)))
    // Space: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m - 1;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k - 1 - left]. Thus A[left] is the (k+1)-th or above element.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        // kth element would be A[left - 1] or B[k - 1 - left].
        return max(Ai_minus_1, Bj);
    }
};


class Solution98 {
public:
    // 2022.7.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/median-of-two-sorted-arrays.cpp
    // Time:  O(log(max(m, n)) * log(max_val - min_val))
    // Space: O(1)
    // Generic solution.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> *> arrays{&nums1, &nums2};
        int total = accumulate(cbegin(arrays), cend(arrays), 0,
                               [](const auto& x, const auto& y) {
                                   return x + size(*y);
                               });
        if (total % 2 == 1) {
            return findKthInSortedArrays(arrays, total / 2 + 1);
        } else {
            return (findKthInSortedArrays(arrays, total / 2) +
                    findKthInSortedArrays(arrays, total / 2 + 1)) / 2.0;
        }
    }

private:
    int findKthInSortedArrays(const vector<vector<int> *>& arrays, int k) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        for (const auto array : arrays) {
            if (!empty(*array)) {
                left = min(left, array->front());
                right = max(right, array->back());
            }
        }
        // left xxxxxxxooooooo right, find first xo or oo
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(arrays, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(const vector<vector<int> *>& arrays, int num, int target) {
        int res = 0;
        for (const auto array : arrays) {
            if (!array->empty()) {  // count the number of values which are less or equal to num
                res += distance(array->cbegin(),
                                upper_bound(array->cbegin(), array->cend(), num));
            }
        }
        return res >= target;
    }
};


class Solution97 {
public:
    // 2022.7.11, from AcWing https://www.acwing.com/solution/content/50/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/50/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        算法1
        (递归) O(log(n+m))O(log(n+m))
        原问题难以直接递归求解，所以我们先考虑这样一个问题：

        在两个有序数组中，找出第k小数。

        如果该问题可以解决，那么第 (n+m)/2(n+m)/2 小数就是我们要求的中位数.

        先从简单情况入手，假设 m,n≥k/2m,n≥k/2，我们先从 nums1nums1 和 nums2nums2 中各取前 k/2k/2 个元素：

        如果 nums1[k/2−1]>nums2[k/2−1]nums1[k/2−1]>nums2[k/2−1]，则说明 nums1nums1 中取的元素过多，
        nums2nums2 中取的元素过少；因此 nums2nums2 中的前 k/2k/2 个元素一定都小于等于第 kk 小数，所以我们
        可以先取出这些数，将问题归约成在剩下的数中找第 k−⌊k/2⌋k−⌊k/2⌋ 小数.
        如果 nums1[k/2−1]≤nums2[k/2−1]nums1[k/2−1]≤nums2[k/2−1]，同理可说明 nums1nums1 中的前 k/2k/2 
        个元素一定都小于等于第 kk 小数，类似可将问题的规模减少一半.
        现在考虑边界情况，如果 m<k/2m<k/2，则我们从 nums1nums1 中取m个元素，从nums2nums2 中取 k/2k/2 个元素
        （由于 k=(n+m)/2k=(n+m)/2，因此 m,nm,n 不可能同时小于 k/2k/2.）：

        如果 nums1[m−1]>nums2[k/2−1]nums1[m−1]>nums2[k/2−1]，则 nums2nums2 中的前 k/2k/2 个元素一定都
        小于等于第 kk 小数，我们可以将问题归约成在剩下的数中找第 k−⌊k/2⌋k−⌊k/2⌋ 小数.
        如果 nums1[m−1]≤nums2[k/2−1]nums1[m−1]≤nums2[k/2−1]，则 nums1nums1 中的所有元素一定都小于等于第 
        kk 小数，因此第k小数是 nums2[k−m−1]nums2[k−m−1].
        时间复杂度分析：k=(m+n)/2k=(m+n)/2，且每次递归 kk 的规模都减少一半，因此时间复杂度是 O(log(m+n))O(log(m+n)).
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
        {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        else
        {
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
        {
            return findKthNumber(nums1, i, nums2, j + k / 2, k - k / 2);
        }
        else
        {
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        }
    }
};


class Solution96 {
public:
    // 2022.7.11, from AcWing https://www.acwing.com/solution/content/50/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/50/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        算法2
        （二分） O(log(min(m,n))O(log(min(m,n))
        该算法的处理细节非常繁琐，建议新手直接跳过。
        首先，让我们考虑只有一个有序数组的情况：

        如果我们将有序数组切分为等长的左右两部分，则 中位数 = (左半边的最大值 + 右半边的最小值) / 2.

        切分情况有两种，例如：

        数组长度是偶数，对于 [2 3 5 7], 我们在3和5之间切分：[2 3 / 5 7]，则 中位数 =(3+5)/2=(3+5)/2；
        数组长度是奇数，对于 [2 3 4 5 7]，我们在4的位置切分，且让4属于左右两边：[2 3 (4/4) 5 7]，则 
        中位数 =(4+4)/2=(4+4)/2.
        现在让我们来考虑两个有序数组的情况，类似于上述考虑方式：

        我们在两个数组中分别找到一个分割点（分割点可能在相邻数之间，也可能在数上），两个分割点左边元素的
        总个数等于右边元素的总个数，且左边元素的最大值 <= 右边元素的最小值，则该分割点即为所求。

        为了同时处理分割点在两数之间和在数上的情况，我们在数组中可能是分割点的位置添加虚拟元素 ‘@’，这样
        我们枚举数组 A′1A1′ 的所有元素，即可枚举 A1A1 所有可能的分割点：

        A1:[1,2,3,4,5]=>A′1:[@,1,@,2,@,3,@,4,@,5,@]A1:[1,2,3,4,5]=>A1′:[@,1,@,2,@,3,@,4,@,5,@]
        A2:[1,1,1,1]=>A′2:[@,1,@,1,@,1,@,1,@]A2:[1,1,1,1]=>A2′:[@,1,@,1,@,1,@,1,@]
        我们将数组 A1A1 的长度记为 N1N1，则 A′1A1′ 的长度为 2∗N1+12∗N1+1; A2A2 的长度记为 N2N2，则 
        A′2A2′ 的长度为 2∗N2+12∗N2+1. 总共有 2N1+2N2+22N1+2N2+2 个元素.

        假设数组 A′1A1′ 的分割点下标是 C1C1，数组 A′2A2′ 的分割点下标是 C2C2，则 C1C1 和 C2C2 之间具有
        如下等式关系：
        C1+C2=N1+N2

        证明：除了 C1C1 和 C2C2 以外，共有 2N1+2N22N1+2N2 个元素，要平均分配到左右两边，因此左边共有 
        N1+N2N1+N2 个元素. 数组下标从0开始，下标为 C1C1 的元素左边有 C1C1 个元素，下标为 C2C2 的元素左边
        有 C2C2 个元素，由此可得上述等式.

        为了方便表述，在 A′1A1′ 中，C1C1 左边（包括C1C1）的最大值记为 L1L1，C1C1 右边（包括C1C1）的最小值
        记为 R1R1；在 A′2A2′ 中，C2C2 左边（包括C2C2）的最大值记为 L2L2，C2C2 右边（包括C2C2）的最小值记为 
        R2R2；

        则如果我们选取的分割点满足
        L1<=R1&&L1<=R2&&L2<=R1&&L2<=R2
        L1<=R1&&L1<=R2&&L2<=R1&&L2<=R2

        则分割点即为所求. 由于 A1,A2A1,A2 都是有序的，因此 L1<=R1&&L2<=R2L1<=R1&&L2<=R2 一定满足；
        不满足的情况有两种：

        如果 L1>R2L1>R2，表示 A2A2中在分割点左侧的元素太少，此时我们需要将 C2C2 右移；
        如果 L2>R1L2>R1，表示 A2A2中在分割点左侧的元素太多，此时我们需要将 C2C2 左移；
        符合二分结构.

        另外，我们在实际操作中，不需要真的在原数组中插入 ‘@’，只需找出 L1,R1,L2,R2L1,R1,L2,R2 和 C1,C2C1,
        C2 的关系即可.
        
        我们可以列表找规律：

        C1C1	L1L1	R1R1
        0	INT_MIN	A1[0]
        1	A1[0]	A1[0]
        2	A1[0]	A1[1]
        3	A1[1]	A1[1]
        4	A1[1]	A1[2]
        由此我们可以发现:

        L1=A1[(C1−1)/2]L1=A1[(C1−1)/2]
        R1=A1[C1/2]R1=A1[C1/2]

        类似可得：
        L2=A2[(C2−1)/2]L2=A2[(C2−1)/2]
        R2=A2[C2/2]R2=A2[C2/2]
        最后，还有两点需要注意：

        我们只能二分长度较小的数组，因为长度较长的数组中的某些分割点可能不合法，会出现 C1>N1+N2C1>N1+N2 的情况；
        我们在数组边界设置两个哨兵，来处理 C1=0C1=0 或 C1=2N1C1=2N1 的情况：
        A1[−1]=INTMIN,A1[2N]=INTMAXA1[−1]=INTMIN,A1[2N]=INTMAX. 这样做并不会影响结果，但可以简化代码.
        时间复杂度：二分长度较短的数组，且每次二分的复杂度是 O(1)O(1)，所以总复杂度是 O(log(min(n,m)))O(log(min(n,m))).
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;
            int mid1 = N1 + N2 - mid2;

            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

            if (L1 > R2) lo = mid2 + 1;
            else if (L2 > R1) hi = mid2 - 1;
            else return (max(L1,L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};


class Solution95 {
public:
    // 2022.7.11, from https://github.com/grandyang/leetcode/issues/4
    /*
       这道题让我们求两个有序数组的中位数，而且限制了时间复杂度为 O(log (m+n))，看到这个时间复杂度，
       自然而然的想到了应该使用二分查找法来求解。但是这道题被定义为 Hard 也是有其原因的，难就难在要
       在两个未合并的有序数组之间使用二分法，如果这道题只有一个有序数组，让求中位数的话，估计就是个 
       Easy 题。对于这道题来说，可以将两个有序数组混合起来成为一个有序数组再做吗，图样图森破，这个
       时间复杂度限制的就是告诉你金坷垃别想啦。还是要用二分法，而且是在两个数组之间使用，感觉很高端啊。
       回顾一下中位数的定义，如果某个有序数组长度是奇数，那么其中位数就是最中间那个，如果是偶数，那么
       就是最中间两个数字的平均值。这里对于两个有序数组也是一样的，假设两个有序数组的长度分别为m和n，
       由于两个数组长度之和 m+n 的奇偶不确定，因此需要分情况来讨论，对于奇数的情况，直接找到最中间的
       数即可，偶数的话需要求最中间两个数的平均值。为了简化代码，不分情况讨论，使用一个小 trick，分别
       找第 (m+n+1) / 2 个，和 (m+n+2) / 2 个，然后求其平均值即可，这对奇偶数均适用。若 m+n 为
       奇数的话，那么其实 (m+n+1) / 2 和 (m+n+2) / 2 的值相等，相当于两个相同的数字相加再除以2，
       还是其本身。
      
       好，这里需要定义一个函数来在两个有序数组中找到第K个元素，下面重点来看如何实现找到第K个元素。
       首先，为了避免拷贝产生新的数组从而增加时间复杂度，使用两个变量i和j分别来标记数组 nums1 和 nums2 
       的起始位置。然后来处理一些 corner cases，比如当某一个数组的起始位置大于等于其数组长度时，
       说明其所有数字均已经被淘汰了，相当于一个空数组了，那么实际上就变成了在另一个数组中找数字，直接
       就可以找出来了。还有就是如果 K=1 的话，只要比较 nums1 和 nums2 的起始位置i和j上的数字就可以了。
       难点就在于一般的情况怎么处理？因为需要在两个有序数组中找到第K个元素，为了加快搜索的速度，可以
       使用二分法，那么对谁二分呢，数组么？其实要对K二分，意思是需要分别在 nums1 和 nums2 中查找第 
       K/2 个元素，注意这里由于两个数组的长度不定，所以有可能某个数组没有第 K/2 个数字，所以需要先 
       check 一下，数组中到底存不存在第 K/2 个数字，如果存在就取出来，否则就赋值上一个整型最大值
       （目的是要在 nums1 或者 nums2 中先淘汰 K/2 个较小的数字，判断的依据就是看 midVal1 和 
       midVal2 谁更小，但如果某个数组的个数都不到 K/2 个，自然无法淘汰，所以将其对应的 midVal 
       值设为整型最大值，以保证其不会被淘汰），若某个数组没有第 K/2 个数字，则淘汰另一个数组的前 
       K/2 个数字即可。举个例子来说吧，比如 nums1 = {3}，nums2 = {2, 4, 5, 6, 7}，K=4，要找
       两个数组混合中第4个数字，则分别在 nums1 和 nums2 中找第2个数字，而 nums1 中只有一个数字，
       不存在第二个数字，则 nums2 中的前2个数字可以直接跳过，为啥呢，因为要求的是整个混合数组的第
       4个数字，不管 nums1 中的那个数字是大是小，第4个数字绝不会出现在 nums2 的前两个数字中，所以
       可以直接跳过。
       
       有没有可能两个数组都不存在第 K/2 个数字呢，这道题里是不可能的，因为K不是任意给的，而是给的 
       m+n 的中间值，所以必定至少会有一个数组是存在第 K/2 个数字的。最后就是二分法的核心啦，比较这
       两个数组的第 K/2 小的数字 midVal1 和 midVal2 的大小，如果第一个数组的第 K/2 个数字小的话，
       那么说明要找的数字肯定不在 nums1 中的前 K/2 个数字，可以将其淘汰，将 nums1 的起始位置向后
       移动 K/2 个，并且此时的K也自减去 K/2，调用递归，举个例子来说吧，比如 nums1 = {1, 3}，
       nums2 = {2, 4, 5}，K=4，要找两个数组混合中第4个数字，那么分别在 nums1 和 nums2 中找第2个
       数字，nums1 中的第2个数字是3，nums2 中的第2个数字是4，由于3小于4，所以混合数组中第4个数字
       肯定在 nums2 中，可以将 nums1 的起始位置向后移动 K/2 个。反之，淘汰 nums2 中的前 K/2 个
       数字，并将 nums2 的起始位置向后移动 K/2 个，并且此时的K也自减去 K/2，调用递归即可，参见代码如下：
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int left1 = 0, right1 = nums1.size();
        int half = (nums1.size()+nums2.size()+1)/2; //left median or median
        int max_left=0, min_right=0;

        while (left1<= right1) {
            int mid1 = (left1+right1)/2;
            int mid2 = half-mid1;
            if (mid1 < nums1.size() && nums1[mid1] < nums2[mid2-1]) {
                left1 = mid1+1;
            } else if (mid1 > 0 && nums1[mid1-1] > nums2[mid2]) {
                right1 = mid1-1;
            } else {
                if (mid1 == 0) max_left = nums2[mid2-1];
                else if (mid2 == 0) max_left = nums1[mid1-1];
                else max_left = max(nums1[mid1-1], nums2[mid2-1]);

                if ((nums1.size()+ nums2.size()) & 1) return max_left;

                if (mid1 == nums1.size()) min_right = nums2[mid2];
                else if (mid2 == nums2.size()) min_right = nums1[mid1];
                else { min_right = min(nums1[mid1], nums2[mid2]);}
                
                return (static_cast<double>(min_right) + max_left)/2;
            }
        }
        assert(0);
        return -1;
    }
};


class Solution94 {
public:
    // 2022.7.24, from https://github.com/grandyang/leetcode/issues/4
    /*
       上面的解法一直使用的是原数组，同时用了两个变量来分别标记当前的起始位置。我们也可以直接生成新的数组，
       这样就不要用起始位置变量了，不过拷贝数组的操作可能会增加时间复杂度，也许会超出限制，不过就算当个思路
       拓展也是极好的。首先要判断数组是否为空，为空的话，直接在另一个数组找第K个即可。还有一种情况是当 
       K = 1 时，表示要找第一个元素，只要比较两个数组的第一个元素，返回较小的那个即可。这里分别取出两个数组
       的第 K/2 个数字的位置坐标i和j，为了避免数组没有第 K/2 个数组的情况，每次都和数组长度做比较，取出
       较小值。这里跟上面的解法有些许不同，上面解法直接取出的是值，而这里取出的是位置坐标，但是思想都是很
       类似的。不同在于，上面解法中每次固定淘汰 K/2 个数字，而这里由于取出了合法的i和j，所以每次淘汰i或j个。
       评论区有网友提出，可以让 j = k-i，这样也是对的，可能还更好一些，收敛速度可能会更快一些，参见代码如下：
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        if (nums1.empty()) return nums2[k - 1];
        if (nums2.empty()) return nums1[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min((int)nums1.size(), k / 2), j = min((int)nums2.size(), k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        } else {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }
};


class Solution93 {
public:
    // 2022.7.24, from https://github.com/grandyang/leetcode/issues/4
    /*
       此题还能用迭代形式的二分搜索法来解，是一种相当巧妙的应用，这里就参照 stellari 大神的帖子 来讲解吧。
       所谓的中位数，换一种角度去看，其实就是把一个有序数组分为长度相等的两段，中位数就是前半段的最大值和后
       半段的最小值的平均数，也就是离分割点相邻的两个数字的平均值。比如说对于偶数个数组 [1 3 5 7]，
       那么分割开来就是 [1 3 / 5 7]，其中 '/' 表示分割点，中位数就是3和5的平均值。对于奇数个数组 [1 3 4 5 7]，
       可以分割为 [1 3 4 / 4 5 7]，可以发现左右两边都有个4，则中位数是两个4的平均数，还是4。这里使用L表示
       分割点左边的数字，R表示分割点右边的数字，则对于 [1 3 5 7] 来说，L=3，R=5。对于 [1 3 4 5 7] 来说，
       L=4，R=4。那么对于长度为N的数组来说，可以分别得到L和R的位置，如下所示：
      
       N        Index of L        Index of R
       1            0                0
       2            0                1
       3            1                1
       4            1                2
       5            2                2
       6            2                3
       7            3                3
       8            3                4
      
       观察上表，可以得到规律，Idx(L)= (N-1)/2，idx(R) = N/2，所以中位数可以用下式表示：
       (L + R) / 2 = (A[(N - 1) / 2] + A[N / 2]) / 2
      
       为了统一数组长度为奇数和偶数的情况，可以使用一个小 tricky，即在每个数字的两边都加上一个特殊字符，比如井号，
       这个 tricky 其实在马拉车算法中也使用过，可以参见博主之前的帖子 Manacher's Algorithm 马拉车算法。这样做
       的好处是不管奇数或者偶数，加井号后数组的长度都是奇数，并且切割点的位置也是确定的，比如：
      
       [1 3 5 7]    ->    [# 1 # 3 # 5 # 7 #]        N = 4
       index               0 1 2 3 4 5 6 7 8         newN = 9
      
       [1 3 4 5 7]    ->    [# 1 # 3 # 4 # 5 # 7 #]        N = 5
       index                 0 1 2 3 4 5 6 7 8 9 10        newN = 11 
      
       这里的N是原数组的长度，newN 是添加井号后新数组的长度，可以发现 newN = 2N+1，而且切割点永远都在新数组中
       坐标为N的位置，且 idx(L) = (N-1)/2，idx(R) = N/2，这里的N就可以换成分割点的位置，岂不美哉（注意这里的 
       idx(L) 和 idx(R) 表示的是在未填充#号的坐标位置）！现在假设有两个数组：
      
       [1 3 4 5 7]    ->    [# 1 # 3 # 4 # 5 # 7 #]        N1 = 5
       index                 0 1 2 3 4 5 6 7 8 9 10        newN1 = 11
      
       [1 2 2 2]    ->    [# 1 # 2 # 2 # 2 #]        N2 = 4
       index               0 1 2 3 4 5 6 7 8         newN2 = 9 
       
       跟只有一个数组的情况类似，这里需要找到一个切割点，使得其分别可以将两个数组分成左右两部分，需要满足的是两个
       左半边中的任意一个数字都要小于两个右半边数组的数字，注意这里可能有的左半边或右半边会为空，但是两个左半边数字
       的个数和应该等于两个右半边的个数和。这里还可以观察出一些规律：
       1. 总共有 2N1 + 2N2 + 2 个位置，那么除去两个分割点，两个左右半边应该各有 N1 + N2 个数字。
       2. 因此，对于一个在 A2 数组中的分割点位置 C2 = K，在 A1 数组中的位置应该为 C1 = N1 + N2 - K，比如假如在 
       A2 中的分割点位置为 C2 = 2，那么在 A1 中的位置为 C1 = 4 + 5 - C2 = 7。 
      
       [# 1 # 3 # 4 # (5/5) # 7 #]
      
       [# 1 / 2 # 2 # 2 #]
      
       3. 假如两个数组都被分割了，那么就应该会有两个L和R，分别是：
       L1 = A1[(C1 - 1) / 2]
       R1 = A1[C1 / 2]
      
       L2 = A2[(C2 - 1) / 2]
       R2 = A2[C2 / 2] 
      
       对于上面的例子就有：
       L1 = A1[(7 - 1) / 2] = A1[3] = 5
       R1 = A1[7 / 2] = A1[3] = 5
      
       L2 = A2[(2 - 1) / 2] = A2[0] = 1
       R2 = A2[2 / 2] = A2[1] = 2
      
       现在需要检测这个切割点是否是正确的中位数的切割点，那么根据之前的分析，任意的左半边的数字都需要小于等于右半边的数字，
       L1 和 L2 是左半边的最大的数字，R1 和 R2 是右半边的最小的数字，所以需要满足下列关系：
       L1 <= R1 && L1 <= R2 && L2 <= R1 && L2 <= R2
      
       由于两个数组都是有序的，所以 L1 <= R1 和 L2 <= R2 都是满足的，那么就只需要满足下列的不等式即可：
       L1 <= R2 && L2 <= R1
      
       这样的话就可以利用二分搜索了，假如 L1 > R2 的话，说明数组 A1 的左半边的数字过大了，需要把切割点 C1 往左移动。
       假如 L2 > R1，说明数组 A2 的左半边数字过大，需要把分割点 C2 左移。若满足上面的条件，说明当前切割点就是正确的，
       那么中位数就可以求出来了，即为：
       (max(L1, L2) + min(R1, R2)) / 2
      
       最后还有两点注意事项：
       1. 由于 C1 和 C2 是可以互相计算而得，即一个确定了，另一个就可以计算出来了。所以尽量去移动较短的那个数组，这样得到
       的时间复杂度为 O(lg(min(N1, N2)))。
       2. 对于 corner case 的处理，当切割点在 0 或者 2n 的位置时，将L或R的值分别赋值为整型最小值和最大值，这不会改变正确
       的切割点的位置，会使得代码实现更加方便。
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        int left = 0, right = n * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/4.%20Median%20of%20Two%20Sorted%20Arrays
    // OJ: https://leetcode.com/problems/median-of-two-sorted-arrays/
    // Author: github.com/lzl124631x
    // Time: O(log(min(M, N)))
    // Space: O(1)
    // Ref: https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
    // Ref: https://youtu.be/LPFhl65R7ww
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int M = nums1.size(), N = nums2.size(), L = 0, R = M, K = (M + N + 1) / 2;
        while (true) {
            int i = (L + R) / 2, j = K - i;
            if (i < M && nums2[j - 1] > nums1[i]) L = i + 1;
            else if (i > L && nums1[i - 1] > nums2[j]) R = i - 1;
            else {
                int maxLeft = max(i ? nums1[i - 1] : INT_MIN, j ? nums2[j - 1] : INT_MIN);
                if ((M + N) % 2) return maxLeft;
                int minRight = min(i == M ? INT_MAX : nums1[i], j == N ? INT_MAX : nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
};


class Solution91 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0004/
    // Time: O(logmin(m,n))
    // Space: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n1;

        while (l <= r) {
        const int partition1 = (l + r) / 2;
        const int partition2 = (n1 + n2 + 1) / 2 - partition1;
        const int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
        const int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
        const int minRight1 = partition1 == n1 ? INT_MAX : nums1[partition1];
        const int minRight2 = partition2 == n2 ? INT_MAX : nums2[partition2];
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            return (n1 + n2) % 2 == 0
                    ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) * 0.5
                    : max(maxLeft1, maxLeft2);
        else if (maxLeft1 > minRight2)
            r = partition1 - 1;
        else
            l = partition1 + 1;
        }

        throw;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/MaskRay/LeetCode/blob/master/median-of-two-sorted-arrays.cc
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        int m = a.size(), n = b.size(), i = 0, j = 0, k = m+n-1 >> 1;
        while (k > 0) {
            int p = k-1 >> 1;
            if (j+p >= n || i+p < m && a[i+p] < b[j+p]) {
                i += p+1;
            } else {
                j += p+1;
            }
            k -= p+1;
        }
        int s = j >= n || i < m && a[i] < b[j] ? a[i++] : b[j++];
        return m+n & 1 ? s : (j >= n || i < m && a[i] < b[j] ? s+a[i] : s+b[j]) * 0.5;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

