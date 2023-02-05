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


class Solution {
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


// @lc code=end

