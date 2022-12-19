/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

/*

https://leetcode.cn/problems/find-k-closest-elements/

658. 找到 K 个最接近的元素
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。
返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]

示例 2：

输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]
 

提示：

1 <= k <= arr.length
1 <= arr.length <= 104
arr 按 升序 排列
-104 <= arr[i], x <= 104
通过次数78,006提交次数161,633

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.8, by Hsinan
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        bool found = false;
        vector<int> answer;   
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] < x) {
                left = middle + 1;
            } else if (arr[middle] > x) {
                right = middle -1;
            } else if (arr[middle] == x) {
                left = middle;
                found = true;
                break;
            }
        }
        // if found == true, use two pointers to check left and right until k elements
        if (found) {
            answer.push_back(arr[left]);
            // update k as itself already included 
            k = k - 1;
            int indexL = left - 1;
            int indexR = left + 1;
            while (k > 0) {
                // compare values of indexL and indexR, pick closest one then ++/-- indexL and indexR
                if (indexL >= 0 && indexR <= arr.size() - 1) {
                    if (std::abs(arr[indexL] - x) <= std::abs(arr[indexR] - x)) {
                        answer.push_back(arr[indexL]);
                        indexL--;
                        k = k - 1;
                    } else {
                        answer.push_back(arr[indexR]);
                        indexR++;
                        k = k - 1;
                    }
                } else if (indexL < 0) {
                    // can only add from right
                    answer.push_back(arr[indexR]);
                    indexR++;
                    k = k - 1;
                } else {
                    // can only add from left
                    answer.push_back(arr[indexL]);
                    indexL--;
                    k = k - 1;                    
                }
            }

            // sort as it is required to return a sorted vector
            sort(answer.begin(), answer.end());

            return answer;
        } else {
            // trick part, at the momment, left > right, so we need to assign the indexL and indexR reversely
            int indexL = right;
            int indexR = left;
            while (k > 0) {
                if (indexL >= 0 && indexR <= arr.size() - 1) {
                    // compare values of indexL and indexR, pick closest one then ++/-- indexL and indexR
                    if (std::abs(arr[indexL] - x) <= std::abs(arr[indexR] - x)) {
                        answer.push_back(arr[indexL]);
                        indexL--;
                        k = k - 1;
                    } else {
                        answer.push_back(arr[indexR]);
                        indexR++;
                        k = k - 1;
                    }
                } else if (indexL < 0) {
                    // can only add from right
                    answer.push_back(arr[indexR]);
                    indexR++;
                    k = k - 1;
                } else {
                    // can only add from left
                    answer.push_back(arr[indexL]);
                    indexL--;
                    k = k - 1;                    
                }
            }

            // sort as it is required to return a sorted vector
            sort(answer.begin(), answer.end());

            return answer;            
        }
    }
};


class Solution99 {
public:
    // 2022.9.8, from https://www.acwing.com/activity/content/code/content/919484/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/919484/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // 堆，nlogk
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> heap;
        for (auto v: arr) {
            heap.push({abs(x - v), v});
            if (heap.size() > k) heap.pop();
        }
        vector<int> res;
        while (heap.size()) res.push_back(heap.top().second), heap.pop();
        sort(res.begin(), res.end());
        return res;
    }
};


class Solution98 {
public:
    // 2022.9.8, from https://www.acwing.com/activity/content/code/content/919484/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/919484/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // 二分 + 双指针，logn+k
    vector<int> findClosestElements(vector<int>& arr, int k, int T) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (arr[mid] >= T) r = mid;
            else l = mid + 1;
        }
        if (r) {
            int x = arr[r - 1], y = arr[r];
            if (make_pair(abs(x - T), x) < make_pair(abs(y - T), y))
                r -- ;
        }
        int i = r, j = r;
        for (int u = 0; u < k - 1; u ++ ) {
            if (i - 1 < 0) j ++ ;
            else if (j + 1 >= arr.size()) i -- ;
            else {
                int x = arr[i - 1], y = arr[j + 1];
                pair<int, int> a(abs(x - T), x), b(abs(y - T), y);
                if (a < b) i -- ;
                else j ++ ;
            }
        }
        vector<int> res;
        for (int u = i; u <= j; u ++ ) res.push_back(arr[u]);
        return res;
    }
};


class Solution97 {
public:
    // 2022.9.8, from https://github.com/grandyang/leetcode/issues/658
    /*
        这道题给我们了一个数组，还有两个变量k和x。让找数组中离x最近的k个元素，而且说明了数组是有序的，如果两个数字
        距离x相等的话，取较小的那个。从给定的例子可以分析出x不一定是数组中的数字，由于数组是有序的，所以最后返回的
        k个元素也一定是有序的，那么其实就是返回了原数组的一个长度为k的子数组，转化一下，实际上相当于在长度为n的数组
        中去掉 n-k 个数字，而且去掉的顺序肯定是从两头开始去，因为距离x最远的数字肯定在首尾出现。那么问题就变的明朗
        了，每次比较首尾两个数字跟x的距离，将距离大的那个数字删除，直到剩余的数组长度为k为止，参见代码如下：
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};


class Solution96 {
public:
    // 2022.9.8, from https://github.com/grandyang/leetcode/issues/658
    /*
        下面这种解法是论坛上的高分解法，用到了二分搜索法。其实博主最开始用的方法并不是帖子中的这两个方法，虽然也是用的
        二分搜索法，但博主搜的是第一个不小于x的数，然后同时向左右两个方向遍历，每次取和x距离最小的数加入结果 res 中，
        直到取满k个为止。但是下面这种方法更加巧妙一些，二分法的判定条件做了一些改变，就可以直接找到要返回的k的数字的子
        数组的起始位置，感觉非常的神奇。每次比较的是 mid 位置和x的距离跟 mid+k 跟x的距离，以这两者的大小关系来确定
        二分法折半的方向，最后找到最近距离子数组的起始位置，参见代码如下：
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};


class Solution95 {
public:
    // 2022.9.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-k-closest-elements.cpp
    // Time:  O(logn + k)
    // Space: O(1)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto i = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        int left = i - 1, right = i;                                    
        while (k--) {
            (right >= arr.size() || (left >= 0 && abs(arr[left] - x) <= abs(arr[right] - x) )) ? --left : ++right;
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};


class Solution94 {
public:
    // 2022.9.8, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/658.%20Find%20K%20Closest%20Elements
    // OJ: https://leetcode.com/problems/find-k-closest-elements/
    // Author: github.com/lzl124631x
    // Time: O(logN + K)
    // Space: O(1)
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int N = A.size(), j = lower_bound(begin(A), end(A), x) - begin(A), i = j - 1;
        while (j - i - 1 < k) {
            if (i == -1 || (j < N && abs(A[j] - x) < abs(A[i] - x))) ++j;
            else --i;
        }
        return vector<int>(begin(A) + i + 1, begin(A) + j);
    }
};



class Solution93 {
public:
    // 2022.9.8, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/658.%20Find%20K%20Closest%20Elements
    // OJ: https://leetcode.com/problems/find-k-closest-elements/
    // Author: github.com/lzl124631x
    // Time: O(log(N - k) + k)
    // Space: O(1)
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int L = 0, R = A.size() - k;
        while (L < R) {
            int M = (L + R) / 2;
            if (x - A[M] > A[M + k] - x) L = M + 1;
            else R = M;
        }
        return vector<int>(begin(A) + R, begin(A) + R + k);
    }
};


class Solution92 {
public:
    // 2022.9.8, from https://walkccc.me/LeetCode/problems/0658/
    // Time: O(log(n−k)+k)
    // Space: O(k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;

        while (l < r) {
        const int m = (l + r) / 2;
        if (x - arr[m] <= arr[m + k] - x)
            r = m;
        else
            l = m + 1;
        }

        return {begin(arr) + l, begin(arr) + l + k};
    }
};


class Solution {
public:
    // 2022.9.8, from https://github.com/wisdompeak/LeetCode/blob/master/Binary_Search/658.Find-K-Closest-Elements/658.Find-K-Closest-Elements.cpp
    /*
        658.Find-K-Closest-Elements
        容易想到的基本思路是，找一个k-size的滑窗，使得x-arr[left]和arr[right]-x尽量地接近。以此为依据，调整起始点left的二分搜索范围。
        但这种二分法，最后的收敛结果并不一定是最终理想的k-size滑窗的起始点。

        有一个非常NB的方法。同样是调整起始点left的二分搜索范围，但是查看的是长度为k+1的滑窗。因为这个窗口有k+1个元素，肯定有一个元素不属于
        k-closest element，容易知道，这个不合格的元素肯定就是arr[left]和arr[left+k]中的一个！那怎么判断是其中哪一个呢？就找其中“相对
        不合格”的那个。

        如果x-arr[left] > arr[left+k]-x，说明arr[left]不合格，所以最终的k-size滑窗的起始点不会是left或其左边的任何位置。
        如果x-arr[left] < arr[left+k]-x，说明arr[left+k]不合格，所以最终的k-size滑窗的末尾点不会是right或其右边的任何位置，也就是说
        k-size滑窗的起始点不会是left右边的任何位置（注意可以是left）。
        如果x-arr[left] == arr[left+k]-x，说明arr[left]和arr[left+k]并列。根据规则，第k个closest只能算一个，所以那个不合格的元素只能
        给arr[left+k]，因此后续的处理就同2. 因为此题一定有解，所以收敛后的位置就一定是最终理想的k-size滑窗的起始点。
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int low = 0;
        int hi = arr.size()-k;
        
        while (low<hi)
        {
            int mid = low+(hi-low)/2;
            
            if (x - arr[mid] > arr[mid+k] - x)
                low = mid+1;
            else
                hi = mid;
        }
        
        vector<int>ret;
        for (int i=low; i<low+k; i++)
            ret.push_back(arr[i]);
        
        return ret;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

