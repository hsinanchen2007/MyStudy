/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

/*

https://leetcode.cn/problems/sliding-window-maximum/

239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。


示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：

输入：nums = [1], k = 1
输出：[1]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
通过次数326,163提交次数652,640

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    2022.8.27

        For data structure, we might think about STL "priority_queue". However, this data structure will only allow
        push/pop/top access, we cannot remove a specific element in the middle or anywhere in the priority queue, so
        priority queue is not common, but Solution90 provides a way by using STL's priority queue

        We need a way to know largest element in the window all the time when slidding window is moving.
        Few ways are:
            1. By using C++ STL's deque
            2. By using C++ STL's multiset
            3. By using C++ STL's priority queue

        The solution99 from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md
            1. Use STL deque so we can access front and back sides
            2. In the push() function, the "while" condition is the key. It basically removes all smaller elements before 
            adding new element, if this new element is larger than those elements in the deque
            3. In the pop(), if the specified one is not the largest one, do nothing

            // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
            // 同时pop之前判断队列当前是否为空。
            void pop(int value) {
                if (!que.empty() && value == que.front()) {     --> only pop the element if it is largest one
                    que.pop_front();
                }
            }
            // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口
            // 元素的数值为止。这样就保持了队列里的数值是单调从大到小的了。
            void push(int value) {
                while (!que.empty() && value > que.back()) {    --> use "while" to remove all smaller elements
                    que.pop_back();
                }
                que.push_back(value);

            }

    2022.8.28

        The solution98 from 程序员吴师兄 is similar to above, by using deque and push/pop, but in one function

        The solution97 and solution96 are using deque to hold index or value

        The solution95/solution94/solution93/solution92 are using deque to hold index or value, similar to 
        solution97/96 above

        The solution91 is using multiset, which can hold same value into multiset, also do a sorting when adding
        the value, so we don't have to push/pop values in deque like all above solutions
            -- 使用 STL 自带的 multiset 就能满足我们的需求，这是一种基于红黑树的数据结构，可以自动对元素进行排序，又允许有重复值，
            完美契合。
        But, there is a tricky place
            -- 我们只想删除一个，而 erase 默认是将所有和目标值相同的元素都删掉，所以我们只能提供一个 iterator，代表一个确定的删除位置，
            先通过 find() 函数找到左边界 nums[i-k] 在集合中的位置，再删除即可。

        Solution90 is a surprise to me, by using priority queue. I was thinking that priority queue cannot be
        used as it can only access top by push/pop/top, but, it also using std::pair() and by using index, it 
        will pop out elements not within the slidding window by using "while" loop. That means, it is similar
        to the way by using deque, remove elements by value (if the incomnig element value is larger than elements
        in the deque), or by index (if the index of element is already out of slidding window), so the priority
        queue here will maintain all elements within the slidding window (by index) where the largest one can be 
        accessed from top all the time!

            for (int i = 0; i < nums.size(); ++i) {
                while (!q.empty() && q.top().second <= i - k) q.pop();
                q.push({nums[i], i});
                if (i >= k - 1) res.push_back(q.top().first);
            }

        Solution89 is using deque, same as above solution97/96

        Last solution is from https://leetcode-solution.cn/book, which is using multiset. Again, to get largest
        value within multiset, use rbegin() as it is increasing order, last element is the largest one. To remove
        the specific element, use find() by value to get the specific iterator of that value, then remove it, 
        othereise if we remove by just value, it will remove all of them as long as value is same. Refer this link:
        https://en.cppreference.com/w/cpp/container/multiset/erase

        Note that based on LC's runtime result, deque < priority queue < multiset. If we want fastest runtime result
        answer, use deque one
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @lc code=start
class Solution100 {
public:
    // 2022.7.24, by Hsinan (Time Limit Exceeded)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // return for answer
        std::vector<int> answer;

        // starts from 0 to k-1, and ensure right's limit
        for (int left = 0, right = k -1; right < nums.size(); left++, right++) {
            int max = INT_MIN;
            for (int i = left; i <= right; i++) {
                max = std::max(max, nums[i]);
            }
            answer.push_back(max);
        }

        return answer;
    }
};


class Solution99 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md
    /*
       这是使用单调队列的经典题目。
       
       难点是如何求一个区间里的最大值呢？ （这好像是废话），暴力一下不就得了。
       
       暴力方法，遍历一遍的过程中每次从窗口中在找到最大的数值，这样很明显是的算法。
      
       有的同学可能会想用一个大顶堆（优先级队列）来存放这个窗口里的k个数字，这样就可以知道最大的最大值是多少了， 
       但是问题是这个窗口是移动的，而大顶堆每次只能弹出最大值，我们无法移除其他数值，这样就造成大顶堆维护的不是
       滑动窗口里面的数值了。所以不能用大顶堆。
       
       此时我们需要一个队列，这个队列呢，放进去窗口里的元素，然后随着窗口的移动，队列也一进一出，每次移动之后，
       队列告诉我们里面的最大值是什么。
      
       这个队列应该长这个样子：
       class MyQueue {
       public:
         void pop(int value) {
         }
         void push(int value) {
         }
         int front() {
         return que.front();
         }
       };
      
       每次窗口移动的时候，调用que.pop(滑动窗口中移除元素的数值)，que.push(滑动窗口添加元素的数值)，然后
       que.front()就返回我们要的最大值。
       
       这么个队列香不香，要是有现成的这种数据结构是不是更香了！
       
       可惜了，没有！ 我们需要自己实现这么个队列。
      
       然后在分析一下，队列里的元素一定是要排序的，而且要最大值放在出队口，要不然怎么知道最大值呢。
      
       但如果把窗口里的元素都放进队列里，窗口移动的时候，队列需要弹出元素。
      
       那么问题来了，已经排序之后的队列 怎么能把窗口要移除的元素（这个元素可不一定是最大值）弹出呢。
       
       大家此时应该陷入深思.....
       
       其实队列没有必要维护窗口里的所有元素，只需要维护有可能成为窗口里最大值的元素就可以了，同时保证队里里
       的元素数值是由大到小的。
      
       那么这个维护元素单调递减的队列就叫做单调队列，即单调递减或单调递增的队列。C++中没有直接支持单调队列，
       需要我们自己来一个单调队列
      
       不要以为实现的单调队列就是 对窗口里面的数进行排序，如果排序的话，那和优先级队列又有什么区别了呢。
      
       来看一下单调队列如何维护队列里的元素。
      
       动画如下：
      
       239.滑动窗口最大值
      
       对于窗口里的元素{2, 3, 5, 1 ,4}，单调队列里只维护{5, 4} 就够了，保持单调队列里单调递减，此时队列
       出口元素就是窗口里最大元素。
      
       此时大家应该怀疑单调队列里维护着{5, 4} 怎么配合窗口经行滑动呢？
       
       设计单调队列的时候，pop，和push操作要保持如下规则：
      
       pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
       push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值
       小于等于队列入口元素的数值为止保持如上规则，每次窗口移动的时候，只要问que.front()就可以返回当前窗口
       的最大值。
       
       为了更直观的感受到单调队列的工作过程，以题目示例为例，输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3，
       动画如下：
      
       239.滑动窗口最大值-2
      
       那么我们用什么数据结构来实现这个单调队列呢？
      
       使用deque最为合适，在文章栈与队列：来看看栈和队列不为人知的一面中，我们就提到了常用的queue在没有指定
       容器的情况下，deque就是默认底层容器。
       
       基于刚刚说过的单调队列pop和push的规则，代码不难实现，如下：
      
       class MyQueue {   单调队列（从大到小）
       public:
          deque<int> que;    使用deque来实现单调队列
          每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
          同时pop之前判断队列当前是否为空。
          void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
          }
          如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的
          数值为止。这样就保持了队列里的数值是单调从大到小的了。
          void push(int value) {
            while (!que.empty() && value > que.back()) {
              que.pop_back();
            }
            que.push_back(value);
          }
          查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
          int front() {
            return que.front();
          }
       };
      
       这样我们就用deque实现了一个单调队列，接下来解决滑动窗口最大值的问题就很简单了，直接看代码吧。

       在来看一下时间复杂度，使用单调队列的时间复杂度是 O(n)。

       有的同学可能想了，在队列中 push元素的过程中，还有pop操作呢，感觉不是纯粹的O(n)。

       其实，大家可以自己观察一下单调队列的实现，nums 中的每个元素最多也就被 push_back 和 pop_back 各一次
       没有任何多余操作，所以整体的复杂度还是 O(n)。

       空间复杂度因为我们定义一个辅助队列，所以是O(k)。

       扩展
       大家貌似对单调队列 都有一些疑惑，首先要明确的是，题解中单调队列里的pop和push接口，仅适用于本题哈。
       单调队列不是一成不变的，而是不同场景不同写法，总之要保证队列里单调递减或递增的原则，所以叫做单调队列。 
       不要以为本题中的单调队列实现就是固定的写法哈。

       大家貌似对deque也有一些疑惑，C++中deque是stack和queue默认的底层实现容器（这个我们之前已经讲过啦），
       deque是可以两边扩展的，而且deque里元素并不是严格的连续分布的。
    */
private:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口
        // 元素的数值为止。这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口移除最前面元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }    
};


class Solution98 {
public:
    // 2022.7.24, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 滑动窗口最大值（ LeetCode 239 ）：https://leetcode-cn.com/problems/sliding-window-maximum/
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 构建存储最大值的数组
        vector<int> res;

        if(nums.size() == 0 || k == 0) {
            return res;
        }

        // 构建双端队列
        deque<int> deque;

        // 一开始滑动窗口不包含 K 个元素，不是合格的滑动窗口
        for(int i = 0; i < k; i++) {
            // 在滑动过程中，维护好 deque，确保它是单调递减队列

            // 反复判断，如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
            // 直到考察元素可以放入到队列中
            while(!deque.empty() && deque.back() < nums[i]) {
                deque.pop_back();
            }
            // 考察元素可以放入到队列中
            deque.push_back(nums[i]);
        }
        // 这个时候，滑动窗口刚刚好有 k 个元素，是合格的滑动窗口，那么最大值就是队列中的队首元素
        res.push_back(deque.front());
        // 现在让滑动窗口滑动
        for(int i = k; i < nums.size(); i++) {
            // 滑动窗口已经装满了元素，向右移动会把窗口最左边的元素抛弃
            // i - k 为滑动窗口的最左边
            // 如果队列的队首元素和窗口最左边的元素相等，需要将队首元素抛出
            // 如果不写这个判断，会导致队列中会包含非当前窗口的元素
            // 比如窗口大小为 1，队列为 1 -1，此时窗口为 【 1 】,队列为 1，输出最大值 1，下一个窗口为 【 -1 】，准备移动的时候队列 
            // 1 和数组最左端元素一样，
            // 必须移除，否则队列中是 【 1，-1 】，输出的结果是 1，而 1 不在窗口 【 -1 】中
            if(deque.front() == nums[i - k]) {
                deque.pop_front();
            }
            // 反复判断，如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
            // 直到考察元素可以放入到队列中
            while(!deque.empty() && deque.back() < nums[i]) {
                deque.pop_back();
            }

            // 考察元素可以放入到队列中
            deque.push_back(nums[i]);
            // 此时，结果数组的值就是队列的队首元素
            res.push_back(deque.front());
        }
        // 最后返回 res
        return res;
    }
};


class Solution97 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/239.%20Sliding%20Window%20Maximum
    // Assume the array is [3, 1, 2, ...] and k = 3, popping 3 out of the window will result in 
    // max value update, but popping 1 won't. This means that we can just keep track of [3, 2], 
    // i.e. a monotonically decreasing sequence of values.
    //
    // Here we store the index of the monotonoically decreasing sequence. When a new value A[i] 
    // is added to the window, we pop the trailing index in the deque which are pointing to values 
    // that are smaller or equal to A[i]. Then we can push i into the deque.
    //
    // We need to pop the index which falls out of the window from the deque as well.
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < A.size(); ++i) {
            if (q.size() && q.front() == i - k) q.pop_front();
            while (q.size() && A[q.back()] <= A[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(A[q.front()]);
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/239.%20Sliding%20Window%20Maximum
    // Similar to Solution 1, but here we store the values instead of the indexes in the deque.
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= k && q.size() && q.front() == A[i - k]) q.pop_front();
            while (q.size() && q.back() < A[i]) q.pop_back();
            q.push_back(A[i]);
            if (i >= k - 1) ans.push_back(q.front());
        }
        return ans;
    }
};


class Solution95 {
public:
    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0239/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;  // max queue

        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            if (i >= k && nums[i - k] == q.front())  // out of bound
                q.pop_front();
            if (i >= k - 1)
                ans.push_back(q.front());
        }

        return ans;
    }
};


class Solution94 {
public:
    // 2022.7.24, from https://github.com/MaskRay/LeetCode/blob/master/sliding-window-maximum.cc
    #define FOR(i, a, b) for (int i = (a); i < (b); i++)
    #define REP(i, n) FOR(i, 0, n)
    vector<int> maxSlidingWindow(vector<int> &a, int k) {
        int n = (int)a.size();
        vector<int> b;
        deque<int> q;
        REP(i, n) {
        if (q.size() && q.front() <= i-k)
            q.pop_front();
        while (q.size() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k-1)
            b.push_back(a[q.front()]);
        }
        return b;
    }
};


class Solution93 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sliding-window-maximum.cpp
    // Time:  O(n)
    // Space: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front() == k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            if (i >= k - 1) {
                result.emplace_back(nums[dq.front()]);
            }
        }
        return result;
    }
};


class Solution92 {
public:
    // 2022.7.24, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/445221/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++ ) {
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/239
    /*
        这道题给定了一个数组，还给了一个窗口大小k，让我们每次向右滑动一个数字，每次返回窗口内的数字的最大值。
        难点就在于如何找出滑动窗口内的最大值（这不废话么，求得不就是这个），那么最狂野粗暴的方法就是每次遍历
        窗口，找最大值呗，OJ 说呵呵哒，no way！我们希望窗口内的数字是有序的，但是每次给新窗口排序又太费时了，
        所以最好能有一种类似二叉搜索树的结构，可以在 lgn 的时间复杂度内完成插入和删除操作，那么使用 STL 自带
        的 multiset 就能满足我们的需求，这是一种基于红黑树的数据结构，可以自动对元素进行排序，又允许有重复值，
        完美契合。所以我们的思路就是，遍历每个数字，即窗口右移，若超过了k，则需要把左边界值删除，这里不能直接
        删除 nums[i-k]，因为集合中可能有重复数字，我们只想删除一个，而 erase 默认是将所有和目标值相同的元素
        都删掉，所以我们只能提供一个 iterator，代表一个确定的删除位置，先通过 find() 函数找到左边界 nums[i-k] 
        在集合中的位置，再删除即可。然后将当前数字插入到集合中，此时看若 i >= k-1，说明窗口大小正好是k，就
        需要将最大值加入结果 res 中，而由于 multiset 是按升序排列的，最大值在最后一个元素，我们可以通过 
        rbegin() 来取出，参见代码如下：

        解法一：
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            if (i >= k - 1) res.push_back(*st.rbegin());
        }
        return res;
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/239
    /*
        我们也可以使用优先队列来做，即最大堆，不过此时我们里面放一个 pair 对儿，由数字和其所在位置组成的，
        这样我们就可以知道每个数字的位置了，而不用再进行搜索了。在遍历每个数字时，进行 while 循环，假如
        优先队列中最大的数字此时不在窗口中了，就要移除，判断方法就是将队首元素的 pair 对儿中的 second
        （位置坐标）跟 i-k 对比，小于等于就移除。然后将当前数字和其位置组成 pair 对儿加入优先队列中。
        此时看若 i >= k-1，说明窗口大小正好是k，就将最大值加入结果 res 中即可，参见代码如下：

        解法二：
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i - k) q.pop();
            q.push({nums[i], i});
            if (i >= k - 1) res.push_back(q.top().first);
        }
        return res;
    }
};


class Solution89 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/239
    /*
        题目中的 Follow up 要求我们代码的时间复杂度为 O(n)。提示我们要用双向队列 deque 来解题，
        并提示我们窗口中只留下有用的值，没用的全移除掉。果然 Hard 的题目我就是不会做，网上看到了
        别人的解法才明白，解法又巧妙有简洁，膜拜啊。大概思路是用双向队列保存数字的下标，遍历整个数组，
        如果此时队列的首元素是 i-k 的话，表示此时窗口向右移了一步，则移除队首元素。然后比较队尾元素
        和将要进来的值，如果小的话就都移除，然后此时我们把队首元素加入结果中即可，参见代码如下：

        解法三：
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution {
public:
    // 2022.8.27, from https://leetcode-solution.cn/book
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> mysetting;
        for (int i = 0; i < nums.size(); i++) {
            mysetting.insert(nums[i]);
            if (i >= k - 1) {
                res.push_back(*mysetting.rbegin());
                mysetting.erase(mysetting.find(nums[i - k + 1]));
            }
        }
        return res;
    }
};


// @lc code=end

