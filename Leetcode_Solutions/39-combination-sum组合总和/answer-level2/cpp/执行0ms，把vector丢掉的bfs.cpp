### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了38.72%的用户

题目没有说是不是正整数，也没有说这个数列是单调的。所以有些优化用不了。  

因为vector即使在后面加东西是很快，但是他超过容器的大小的时候会触发realloc。这里用了个deque把这个realloc的库调用给大大减少了。因为bfs中大部分时间都是在增减最后一个元素（如果不用dequeue，那么这题要4ms）。因为用了递归简化逻辑，内存不是怎么好，不过快就完事了。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums = candidates;
        deque<int> curr(0);
        helper(curr,nums.begin(),target);
        return ret; 
    }

    void helper(deque<int>& curr, vector<int>::iterator  it, int target){
        // for (auto &el: curr) cout << el << ", " ; cout << endl;
        if(target == 0) ret.emplace_back(curr.begin(), curr.end());
        // int i = *it;
        // cout << "imhere with " << i << endl;
        for (; it != nums.end(); it ++){
            if (*it > target) break; 
            curr.push_back(*it);
            helper(curr, it, target - *it);
            curr.pop_back();
        }
    }
private:
vector<int> nums;
vector<vector<int>> ret;
};
```