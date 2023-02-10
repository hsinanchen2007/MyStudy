/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

/*

https://leetcode.cn/problems/kth-largest-element-in-an-array/

215. 数组中的第K个最大元素

中等
2K
company
Facebook
company
亚马逊
company
字节跳动
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1:

输入: [3,2,1,5,6,4], k = 2
输出: 5

示例 2:

输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
 

提示：

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/

// @lc code=start
class Solution100 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
        int pivotIndex = nums.size();
        
        while (pivotIndex != k - 1) {
            pivotIndex = partition(nums, low, high);
            if (pivotIndex < k - 1) {
                low = pivotIndex + 1;
            } else {
                high = pivotIndex - 1;
            }
        }
        
        return nums[k - 1];        
    }
private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        
        int i = low + 1;
        int j = high;
        
        while (i <= j) {
            if (nums[i] < pivot && pivot < nums[j]) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= pivot) {
                i++;
            }
            if (pivot >= nums[j]) {
                j--;
            }
        }
        
        swap(nums[low], nums[j]);
        return j;
    }
};


class Solution99 {
public:
    // 2023.2.4, from https://walkccc.me/LeetCode/problems/0215/
    // Time: O(nlogk)
    // Space: O(k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (const int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};


class Solution98 {
public:
    // https://leetcode.com/problems/kth-largest-element-in-an-array/
    // Author: github.com/lzl124631x
    // Time: O(N + klogN)
    // Space: O(1)
    int findKthLargest(vector<int>& A, int k) {
        make_heap(begin(A), end(A));
        while (--k) {
            pop_heap(begin(A), end(A));
            A.pop_back();
        }
        return A[0];
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
    // Author: github.com/lzl124631x
    // Time: O(N) on average, O(N^2) in the worst case
    // Space: O(1)
    int findKthLargest(vector<int>& A, int k) {
        nth_element(begin(A), begin(A) + k - 1, end(A), greater<>());
        return A[k - 1];
    }
};


class Solution96 {
public:
    // OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
    // Author: github.com/lzl124631x
    // Time: O(N) on average, O(N^2) in the worst case
    // Space: O(1)
    int findKthLargest(vector<int>& A, int k) {
        partial_sort(begin(A), begin(A) + k, end(A), greater<>());
        return A[k - 1];
    }
};


class Solution95 {
public:
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
    int findKthLargest(vector<int>& nums, int k) {

        // 简单了解【优先队列】
        // Queue是一个先进先出（FIFO）的队列。
        // 在银行柜台办业务时，我们假设只有一个柜台在办理业务，但是办理业务的人很多，怎么办？
        // 可以每个人先取一个号，例如：A1、A2、A3……然后，按照号码顺序依次办理，实际上这就是一个 Queue。
        // 如果这时来了一个VIP客户，他的号码是V1，虽然当前排队的是A10、A11、A12……但是柜台下一个呼叫的客户号码却是V1。
        // 这个时候，我们发现，要实现“VIP插队”的业务，用 Queue 就不行了，因为 Queue 会严格按 FIFO 的原则取出队首元素。
        // 我们需要的是优先队列：PriorityQueue。
        // PriorityQueue 和 Queue 的区别在于，它的出队顺序与元素的优先级有关
        // 对 PriorityQueue 调用 remove() 或 poll()方法，返回的总是优先级最高的元素。

        // 这里，我们创建了一个没有任何参数的优先级队列
        // 在这种情况下，优先级队列的头是队列中最小的元素
        // 元素将按升序从队列中移除
        priority_queue<int, vector<int>, greater<int> > minHeap; 

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            
            // 在遍历过程中，对每个访问的元素采取如下的判断
            // 优先队列里面的元素个数达到了 k 个
            // 并且当前访问的元素小于了优先队列中的最小值，即队头元素
            // 说明当前访问的元素没有资格加入到优先队列中
            if ( minHeap.size() == k && nums[i] <= minHeap.top() ) {

                // 那么继续访问下一个元素
                continue;

            }

            // 将元素插入队列，在优先队列内部会进行排序操作
            // 使得优先级队列的头是队列中最小的元素
            minHeap.push(nums[i]);

            // 插入了当前元素之后，如果个数超过了 k
            if (minHeap.size() > k) {

                // 那么需要把最小的元素移除
                minHeap.pop();

            }
        }

        // 遍历结束之后，minHeap 存储了数组的前 k 个最大的元素
        // 而第 k 大的元素就是优先队列 minHeap 中的最小值
        return minHeap.top();

    }
};


class Solution94 {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/432564/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[k];
        int x = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i ++ ; while (nums[i] > x);
            do j -- ; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k - 1);
    }
};


class Solution93 {
public:
    // 2023.2.9, from https://github.com/grandyang/leetcode/issues/215
    /*
        下面这种解法是利用了 priority_queue 的自动排序的特性，跟上面的解法思路上没有什么区别，当然我们也可以换成 multiset 来做，
        一个道理，参见代码如下：
    */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};


class Solution {
public:
    // 2023.2.9, from https://github.com/grandyang/leetcode/issues/215
    /*
        上面两种方法虽然简洁，但是确不是本题真正想考察的东西，可以说有一定的偷懒嫌疑。这道题最好的解法应该是下面这种做法，用到了快速排序 
        Quick Sort 的思想，这里排序的方向是从大往小排。对快排不熟悉的童鞋们随意上网搜些帖子看下吧，多如牛毛啊，总有一款适合你。核心思想
        是每次都要先找一个中枢点 Pivot，然后遍历其他所有的数字，像这道题从大往小排的话，就把大于中枢点的数字放到左半边，把小于中枢点的放
        在右半边，这样中枢点是整个数组中第几大的数字就确定了，虽然左右两部分各自不一定是完全有序的，但是并不影响本题要求的结果，因为左半
        部分的所有值都大于右半部分的任意值，所以我们求出中枢点的位置，如果正好是 k-1，那么直接返回该位置上的数字；如果大于 k-1，说明要求
        的数字在左半部分，更新右边界，再求新的中枢点位置；反之则更新右半部分，求中枢点的位置；不得不说，这个思路真的是巧妙啊～    
    */
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};


// @lc code=end

