/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

/*

https://leetcode.cn/problems/sliding-window-median/

480. 滑动窗口中位数
困难
408
company
亚马逊

中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口
移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

提示：

你可以假设 k 始终有效，即：k 始终小于等于输入的非空数组的元素个数。
与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。

*/

// @lc code=start
class Solution100 {
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/561474/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
public:
    int k;
    multiset<int> left, right;

    double get_medium() {
        if (k % 2) return *right.begin();
        return ((double)*left.rbegin() + *right.begin()) / 2;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int _k) {
        k = _k;
        for (int i = 0; i < k; i ++ ) right.insert(nums[i]);
        for (int i = 0; i < k / 2; i ++ ) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        vector<double> res;
        res.push_back(get_medium());
        for (int i = k; i < nums.size(); i ++ ) {
            int x = nums[i], y = nums[i - k];
            if (x >= *right.begin()) right.insert(x);
            else left.insert(x);
            if (y >= *right.begin()) right.erase(right.find(y));
            else left.erase(left.find(y));

            while (left.size() > right.size()) {
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }
            while (right.size() > left.size() + 1) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            res.push_back(get_medium());
        }
        return res;
    }
};


class Solution99 {
public:
    //2023.2.19, from https://walkccc.me/LeetCode/problems/0480/
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> window(begin(nums), begin(nums) + k);
        auto it = next(begin(window), (k - 1) / 2);

        for (int i = k;; ++i) {
            const double median = k & 1 ? *it : (*it + *next(it)) / 2.0;
            ans.push_back(median);
            if (i == nums.size())
                break;
            window.insert(nums[i]);
            if (nums[i] < *it)
                --it;
            if (nums[i - k] <= *it)
                ++it;
            window.erase(window.lower_bound(nums[i - k]));
        }

        return ans;
    }
};


class Solution98 {
public:
    // 2023.2.19, from https://github.com/wisdompeak/LeetCode/blob/master/Heap/480.Sliding-Window-Median/480.Sliding-Window-Median.cpp
    /*
        480.Sliding-Window-Median
        希望能够自动排序的容器，首选set或者multiset。对于这类非线性的容器，不能用+k或-k来实现迭代器的移动，必须用for循环不断++/--，
        或者使用next或prev。例如

        set<int>::iterator pos = next(Set.begin(),k); //从Set.begin()开始后移k个
        set<int>::iterator pos = prev(Set.end(),k);  //从Set.end()开始前移k个
        本题里设置一个multiset，初始化时用next命令把pos定位到最中间（Set容量为奇数）、或者中间靠右（Set容量为偶数）的那个迭代器。

        每次一进一出的操作如下。对于k奇偶性通用的代码比较难理解，那就索性分别讨论容易理清思路。

                for (int i=k; i<=nums.size(); i++)
                {
                    if (k%2==1) results.push_back(*pos);
                    else results.push_back(*pos/2.0+*prev(pos,1)/2.0);
                    
                    if (i==nums.size()) break;
                    
                    Set.insert(nums[i]);
                    
                    if (k%2==1)   // 当k为奇数时，Set内的排列为 OXO，X为pos指针
                    {
                        if (nums[i]>=*pos)
                            pos++;
                                        
                        // 加入一个元素后，此时阵型为 OOXO
                        if (nums[i-k]>*pos)
                            pos--;
                        else if (nums[i-k]<*pos)
                            ;
                        else if (nums[i-k]==*pos && *prev(pos,1)!=*pos)  
                            // 如果X左边是个重复元素，则无需改动；如果X左边不是重复元素，则X会被删除，指针需左移
                            pos--;                
                    }
                    else    // 当k为偶数时，Set内的排列为 OOXO，X为pos指针
                    {
                        if (nums[i]<*pos)
                            pos--;
                        
                        // 加入一个元素后，此时阵型为 OOXOO
                        if (nums[i-k]<*pos)
                            pos++;
                        else if (nums[i-k]>*pos)
                            ;
                        else if (nums[i-k]==*pos)
                            // 如果X左边是个重复元素，则会删除那个O；如果X左边不是重复元素，则会删除X。两种情况下指针都需右移
                            pos++;
                    }
                    
                    Set.erase(Set.lower_bound(nums[i-k]));     
                }
        每次内循环之后，pos的定义不变（最中间或者最中间靠右的迭代器）。    
    */
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int>Set;
        for (int i=0; i<k; i++)        
            Set.insert(nums[i]);
        
        auto pos=Set.begin();
        for (int i=0; i<k/2; i++)
            pos=next(pos,1);
        
        vector<double>results;
        
        for (int i=k; i<=nums.size(); i++)
        {
            if (k%2==1)
                results.push_back(*pos);
            else
                results.push_back(*pos/2.0+*prev(pos,1)/2.0);
            
            if (i==nums.size()) break;
            
            Set.insert(nums[i]);
            
            if (k%2==1)   // OXO
            {
                if (nums[i]>=*pos)
                    pos++;
                                
                // OOXO
                if (nums[i-k]>*pos)
                    pos--;
                else if (nums[i-k]<*pos)
                    ;
                else if (nums[i-k]==*pos && *prev(pos,1)!=*pos)  
                    // 如果X左边是个重复元素，则无需改动；如果X左边不是重复元素，则X会被删除，指针需左移
                    pos--;                
            }
            else    // OOXO
            {
                if (nums[i]<*pos)
                    pos--;
                
                // OOXOO
                if (nums[i-k]<*pos)
                    pos++;
                else if (nums[i-k]>*pos)
                    ;
                else if (nums[i-k]==*pos)
                    // 如果X左边是个重复元素，则会删除那个O；如果X左边不是重复元素，则会删除X。两种情况下指针都需右移
                    pos++;
            }
            
            Set.erase(Set.lower_bound(nums[i-k]));     
        }
        
        return results;
        
    }
};


class Solution97 {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sliding-window-median.cpp
    // Time:  O(nlogk)
    // Space: O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> min_bst(cbegin(nums), cbegin(nums) + k);
        auto mid = next(cbegin(min_bst), k / 2);
        vector<double> result = {((*mid) + *prev(mid, 1 - k % 2)) / 2};
        for (int i = k; i < size(nums); ++i) {
            min_bst.emplace(nums[i]);
            if (nums[i] < *mid) {
                --mid;
            }
            if (nums[i - k] <= *mid) {
                ++mid;
            }
            min_bst.erase(min_bst.lower_bound(nums[i - k]));
            result.emplace_back(((*mid) + *prev(mid, 1 - k % 2)) / 2);
        }
        return result;
    }
};


class Solution96 {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sliding-window-median.cpp
    // Time:  O(nlogk)
    // Space: O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int, less<int>> min_bst;
        multiset<int, greater<int>> max_bst;

        vector<double> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (max_bst.find(nums[i - k]) != max_bst.cend()) {
                    max_bst.erase(max_bst.find(nums[i - k]));
                } else {
                    min_bst.erase(min_bst.find(nums[i - k]));
                }
            }

            if (max_bst.empty() || nums[i] > *max_bst.cbegin()) {
                min_bst.emplace(nums[i]);
                if (min_bst.size() > max_bst.size() + 1) {
                    max_bst.emplace(*min_bst.cbegin());
                    min_bst.erase(min_bst.cbegin());
                }
            } else {
                max_bst.emplace(nums[i]);
                if (max_bst.size() > min_bst.size()) {
                    min_bst.emplace(*max_bst.cbegin());
                    max_bst.erase(max_bst.cbegin());
                }
            }

            if (i >= k - 1) {
                result.emplace_back(min_bst.size() == max_bst.size() ?
                                 *max_bst.cbegin() / 2.0 + *min_bst.cbegin() / 2.0 : *min_bst.cbegin());
            }
        }

        return result;
    }
};


class Solution95 {
public:
    // 2023.2.19, from https://github.com/grandyang/leetcode/issues/480
    /*
        这道题给了我们一个数组，还是滑动窗口的大小，让我们求滑动窗口的中位数。我想起来之前也有一道滑动窗口的题Sliding Window Maximum，
        于是想套用那道题的方法，可以用deque怎么也做不出，因为求中位数并不是像求最大值那样只操作deque的首尾元素。后来看到了史蒂芬大神的
        方法，原来是要用一个multiset集合，和一个指向最中间元素的iterator。我们首先将数组的前k个数组加入集合中，由于multiset自带排序
        功能，所以我们通过k/2能快速的找到指向最中间的数字的迭代器mid，如果k为奇数，那么mid指向的数字就是中位数；如果k为偶数，那么mid指
        向的数跟前面那个数求平均值就是中位数。当我们添加新的数字到集合中，multiset会根据新数字的大小加到正确的位置，然后我们看如果这个
        新加入的数字比之前的mid指向的数小，那么中位数肯定被拉低了，所以mid往前移动一个，再看如果要删掉的数小于等于mid指向的数(注意这里
        加等号是因为要删的数可能就是mid指向的数)，则mid向后移动一个。然后我们将滑动窗口最左边的数删掉，我们不能直接根据值来用erase来删
        数字，因为这样有可能删掉多个相同的数字，而是应该用lower_bound来找到第一个不小于目标值的数，通过iterator来删掉确定的一个数字，
        参见代码如下：    
    */
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k /  2);
        for (int i = k; ; ++i) {
            res.push_back((*mid + *prev(mid,  1 - k % 2)) / 2);        
            if (i == nums.size()) return res;
            ms.insert(nums[i]);
            if (nums[i] < *mid) --mid;
            if (nums[i - k] <= *mid) ++mid;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
    }
};


class Solution94 {
public:
    // 2023.2.19, from https://github.com/grandyang/leetcode/issues/480
    /*
        上面的方法用到了很多STL内置的函数，比如next，lower_bound啥的，下面我们来看一种不使用这些函数的解法。这种解法跟Find Median from 
        Data Stream那题的解法很类似，都是维护了small和large两个堆，分别保存有序数组的左半段和右半段的数字，保持small的长度大于等于large
        的长度。我们开始遍历数组nums，如果i>=k，说明此时滑动窗口已经满k个了，再滑动就要删掉最左值了，我们分别在small和large中查找最左值，
        有的话就删掉。然后处理增加数字的情况（分两种情况：1.如果small的长度小于large的长度，再看如果large是空或者新加的数小于等于large的
        首元素，我们把此数加入small中。否则就把large的首元素移出并加入small中，然后把新数字加入large。2.如果small的长度大于large，再看
        如果新数字大于small的尾元素，那么新数字加入large中，否则就把small的尾元素移出并加入large中，把新数字加入small中）。最后我们再计算
        中位数并加入结果res中，根据k的奇偶性来分别处理，参见代码如下：    
    */
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> small, large;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k])) small.erase(small.find(nums[i - k]));
                else if (large.count(nums[i - k])) large.erase(large.find(nums[i - k]));
            }
            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= *large.begin()) small.insert(nums[i]);
                else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            } else {
                if (nums[i] >= *small.rbegin()) large.insert(nums[i]);
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if (i >= (k - 1)) {
                if (k % 2) res.push_back(*small.rbegin());
                else res.push_back(((double)*small.rbegin() + *large.begin()) / 2);
            }
        }
        return res;
    }
};


class Solution93 {
public:
    // 2023.2.19, from https://zxi.mytechroad.com/blog/?s=LeetCode+480.
    // Author: Huahua
    // Running time: 99 ms
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
        vector<double> ans;
        if (k == 0) return ans;
        vector<int> window(nums.begin(), nums.begin() + k - 1);
        std::sort(window.begin(), window.end());
        for (int i = k - 1; i < nums.size(); ++i) {
            window.push_back(nums[i]);
            auto it = prev(window.end(), 1);
            auto const insertion_point = 
                    std::upper_bound(window.begin(), it, *it);      
            std::rotate(insertion_point, it, it + 1);          
            ans.push_back((static_cast<double>(window[k / 2]) + window[(k - 1) / 2]) / 2);
            window.erase(std::find(window.begin(), window.end(), nums[i - k + 1]));      
        }
        return ans;
    }
};


class Solution {
public:
    // 2023.2.19, from https://zxi.mytechroad.com/blog/?s=LeetCode+480.
    // Author: Huahua
    // Running time: 84 ms
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
        vector<double> ans;
        if (k == 0) return ans;
        vector<int> window(nums.begin(), nums.begin() + k - 1);
        std::sort(window.begin(), window.end());
        for (int i = k - 1; i < nums.size(); ++i) {
            window.push_back(nums[i]);
            auto it = prev(window.end(), 1);
            auto const insertion_point = 
                    std::upper_bound(window.begin(), it, *it);      
            std::rotate(insertion_point, it, it + 1);          
            ans.push_back((static_cast<double>(window[k / 2]) + window[(k - 1) / 2]) / 2);
            window.erase(std::lower_bound(window.begin(), window.end(), nums[i - k + 1]));      
        }
        return ans;
    }
};


// @lc code=end

