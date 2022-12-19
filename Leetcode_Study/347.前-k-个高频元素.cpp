/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

/*

https://leetcode.cn/problems/top-k-frequent-elements/

347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 
示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

通过次数323,298提交次数511,887

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.md
    /*
       这道题目主要涉及到如下三块内容：
       
       要统计元素出现频率
       对频率排序
       找出前K个高频元素
       首先统计元素出现的频率，这一类的问题可以使用map来进行统计。
       
       然后是对频率进行排序，这里我们可以使用一种 容器适配器就是优先级队列。
      
       什么是优先级队列呢？
      
       其实就是一个披着队列外衣的堆，因为优先级队列对外接口只是从队头取元素，从队尾添加元素，再无其他取元素的方式，看起来就是一个队列。
       
       而且优先级队列内部元素是自动依照元素的权值排列。那么它是如何有序排列的呢？
       
       缺省情况下priority_queue利用max-heap（大顶堆）完成对元素的排序，这个大顶堆是以vector为表现形式的complete binary tree（完全二叉树）。
       
       什么是堆呢？
      
       堆是一棵完全二叉树，树中每个结点的值都不小于（或不大于）其左右孩子的值。 如果父亲结点是大于等于左右孩子就是大顶堆，小于等于左右孩子就是小顶堆。
      
       所以大家经常说的大顶堆（堆头是最大元素），小顶堆（堆头是最小元素），如果懒得自己实现的话，就直接用priority_queue（优先级队列）就可以了，
       底层实现都是一样的，从小到大排就是小顶堆，从大到小排就是大顶堆。
      
       本题我们就要使用优先级队列来对部分频率进行排序。
      
       为什么不用快排呢， 使用快排要将map转换为vector的结构，然后对整个数组进行排序， 而这种场景下，我们其实只需要维护k个有序的序列就可以了，
       所以使用优先级队列是最优的。
       
       此时要思考一下，是使用小顶堆呢，还是大顶堆？
       
       有的同学一想，题目要求前 K 个高频元素，那么果断用大顶堆啊。
       
       那么问题来了，定义一个大小为k的大顶堆，在每次移动更新大顶堆的时候，每次弹出都把最大的元素弹出去了，那么怎么保留下来前K个高频元素呢。
      
       而且使用大顶堆就要把所有元素都进行排序，那能不能只排序k个元素呢？
      
       所以我们要用小顶堆，因为要统计最大前k个元素，只有小顶堆每次将最小的元素弹出，最后小顶堆里积累的才是前k个最大元素。
      
       寻找前k个最大元素流程如图所示：（图中的频率只有三个，所以正好构成一个大小为3的小顶堆，如果频率更多一些，则用这个小顶堆进行扫描）
      
       347.前K个高频元素
      
       大家对这个比较运算在建堆时是如何应用的，为什么左大于右就会建立小顶堆，反而建立大顶堆比较困惑。
       
       确实 例如我们在写快排的cmp函数的时候，return left>right 就是从大到小，return left<right 就是从小到大。
       
       优先级队列的定义正好反过来了，可能和优先级队列的源码实现有关（我没有仔细研究），我估计是底层实现上优先队列队首指向后面，队尾指向最前面的缘故！
    */
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};


class Solution99 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/347.%20Top%20K%20Frequent%20Elements
    // heap
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        if (cnt.size() == k) {
            for (auto &[n, c] : cnt) ans.push_back(n);
            return ans;
        }
        auto cmp = [&](int a, int b) { return cnt[a] > cnt[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // keep a min-heap of size at most k
        for (auto &[n, c] : cnt) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        while (pq.size()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};


class Solution98 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/347.%20Top%20K%20Frequent%20Elements
    // make_heap and pop_heap
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> nums, ans;
        for (auto &[n, c] : cnt) nums.push_back(n);
        if (nums.size() == k) return nums;
        auto cmp = [&](int a, int b) { return cnt[a] < cnt[b]; };
        make_heap(begin(nums), end(nums), cmp);
        while (k--) {
            pop_heap(begin(nums), end(nums), cmp);
            ans.push_back(nums.back());
            nums.pop_back();
        }
        return ans;
    }
};


class Solution97 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/347.%20Top%20K%20Frequent%20Elements
    // quick sort
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (auto &[n, c] : cnt) ans.push_back(n);
        if (ans.size() == k) return ans;
        auto partition = [&](int L, int R) {
            int i = L, j = L, pivotIndex = L + rand() % (R - L + 1), pivot = cnt[ans[pivotIndex]];
            swap(ans[pivotIndex], ans[R]);
            for (; i < R; ++i) {
                if (cnt[ans[i]] > pivot) swap(ans[i], ans[j++]);
            }
            swap(ans[j], ans[R]);
            return j;
        };
        auto quickSelect = [&](int k) {
            int L = 0, R = ans.size() - 1;
            while (L < R) {
                int M = partition(L, R);
                if (M + 1 == k) break;
                if (M + 1 > k) R = M - 1;
                else L = M + 1;
            }
        };
        quickSelect(k);
        ans.resize(k);
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/347.%20Top%20K%20Frequent%20Elements
    // STL's nth_element
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (auto &[n, c] : cnt) ans.push_back(n);
        if (ans.size() == k) return ans;
        nth_element(begin(ans), begin(ans) + k - 1, end(ans), [&](int a, int b) { return cnt[a] > cnt[b]; });
        ans.resize(k);
        return ans;
    }
};


class Solution95 {
public:
    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0347/
    struct T {
        int num;
        int freq;
        T(int num, int freq) : num(num), freq(freq) {}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> count;
        auto compare = [](const T& a, const T& b) { return a.freq > b.freq; };
        priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

        for (const int num : nums)
        ++count[num];

        for (const auto& [num, freq] : count) {
            minHeap.emplace(num, freq);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        while (!minHeap.empty())
            ans.push_back(minHeap.top().num), minHeap.pop();

        return ans;
    }
};


class Solution94 {
public:
    // 2022.7.24, from https://www.guozet.me/leetcode/Leetcode-347-Top-K-Frequent-Elements.html?h=top%20k%20
    // Bucket sort
    // Runtime: 12ms > 99.14%
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m_;
        int max_freq = 1;
        for (int& num : nums) max_freq = max(++m_[num], max_freq);
        map<int, vector<int>> bucket;
        for (auto& val : m_) bucket[val.second].emplace_back(val.first);
        // Find the Top K frequent elements
        for (int i = max_freq; i >= 1; --i) {
            if (bucket.find(i) != bucket.end()) {
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
                if (ans.size() == k) return ans;
            } else
                continue;
        }
        return ans;
    }
};


class Solution93 {
public:
    // 2022.7.24, from https://www.guozet.me/leetcode/Leetcode-347-Top-K-Frequent-Elements.html?h=top%20k%20
    // Bucket sort
    // Runtime: 12ms > 99.14%
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m_;
        for (int& num : nums) ++m_[num];
        priority_queue<pair<int, int>> q;
        for (auto& val : m_) {
            q.emplace(-val.second, val.first);
            if (q.size() > k) q.pop();
        }
        // Find the Top K frequent elements
        while (k--) {
            ans.emplace_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};


class Solution92 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/top-k-frequent-elements.cpp
    // Bucket Sort Solution
    // Time:  O(n)
    // Space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& kvp : counts) {
            buckets[kvp.second].emplace_back(kvp.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = 0; j < buckets[i].size(); ++j){
                result.emplace_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};


class Solution91 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/top-k-frequent-elements.cpp
    // Quick Select Solution
    // Time:  O(n) ~ O(n^2), O(n) on average.
    // Space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }
        vector<pair<int, int>> p;
        for (const auto& kvp : counts) {
            p.emplace_back(-kvp.second, kvp.first);
        }
        nth_element(p.begin(), p.begin() + k - 1, p.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};


class Solution90 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/top-k-frequent-elements.cpp
    // Heap solution
    // Time:  O(nlogk)
    // Space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }
        priority_queue<pair<int, int>> heap;
        for (const auto& kvp : counts) {
            heap.emplace(-kvp.second, kvp.first);
            if (heap.size() == k + 1) {
                heap.pop();
            }
        }
        vector<int> result;
        while (!heap.empty()) {
            result.emplace_back(heap.top().second);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


class Solution89 {
public:
    // 2022.7.24, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/487547/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto x: nums) cnt[x] ++ ;
        int n = nums.size();
        vector<int> s(n + 1);
        for (auto [x, c]: cnt) s[c] ++ ;
        int i = n, t = 0;
        while (t < k) t += s[i -- ];
        vector<int> res;
        for (auto [x, c]: cnt)
            if (c > i)
                res.push_back(x);
        return res;
    }
};


class Solution88 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/347
    /*
        这道题给了我们一个数组，让统计前k个高频的数字，那么对于这类的统计数字的问题，首先应该考虑用 HashMap 来做，
        建立数字和其出现次数的映射，然后再按照出现次数进行排序。可以用堆排序来做，使用一个最大堆来按照映射次数从大
        到小排列，在 C++ 中使用 priority_queue 来实现，默认是最大堆，参见代码如下：

        解法一：
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/347
    /*
        当然，既然可以使用最大堆，还有一种可以自动排序的数据结构 TreeMap，也是可以的，这里就不写了，因为跟上面的
        写法基本没啥区别，就是换了一个数据结构。这里还可以使用桶排序，在建立好数字和其出现次数的映射后，按照其出现
        次数将数字放到对应的位置中去，这样从桶的后面向前面遍历，最先得到的就是出现次数最多的数字，找到k个后返回即可，
        参见代码如下：
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) {
            bucket[it.second].push_back(it.first);
        }
        for (int i = nums.size(); i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

