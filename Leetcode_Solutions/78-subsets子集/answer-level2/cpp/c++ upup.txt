### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.4 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
### 代码

```cpp
class Solution {
public:

vector<vector<int>> ans;

    void dps(vector<int>& nums, vector<int>& vec, int idx)
    {
        ans.push_back(vec);
        
        for (int i = pos; i<nums.size(); i++)
        {
            vec.push_back(nums[i]);
            dps(nums,vec,i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        dps(nums, vec, 0);
        return ans;
    }
};

90. 子集 II
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
===>
class Solution {
public:
vector<vector<int>> ans;
int N;
    void dps(vector<int>& nums, vector<int>& vec, int idx)
    {
        ans.push_back(vec);
        
        for (int i = idx; i<N; i++)
        {
            // add
            if (i>idx && nums[i]==nums[i-1]) continue;

            vec.push_back(nums[i]);
            dps(nums,vec,i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // add
        sort(nums.begin(), nums.end());
        
        vector<int> vec;
        this->N = nums.size();
        dps(nums, vec, 0);
        return ans;
    }
};

77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
===>
class Solution {
public:
vector<vector<int>> ans;
    void dps(vector<int>& vec, int n, int k, int idx)
    {
        if (vec.size() == k)
        {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i<=n; i++)
        {
            vec.push_back(i);
            dps(vec, n, k, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        dps(vec, n, k, 1);
        return ans;
    }
};


39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
===>
class Solution {
public:
vector<vector<int>> ans;
    void dps(vector<int>& candidates, int target, vector<int>& vec, int idx)
    {
        if (target == 0)
        {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i<candidates.size(); i++)
        {
            if (candidates[i] > target) continue;
            vec.push_back(candidates[i]);
            dps(candidates, target-candidates[i], vec, i);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        dps(candidates, target, vec, 0);
        return ans;
    }
};

40. 组合总和 II
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
===>
class Solution {
public:
vector<vector<int>> ans;
    void dps(vector<int>& candidates, int target, vector<int>& vec, int idx)
    {
        if (target == 0)
        {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i<candidates.size(); i++)
        {
            // add
            if (i>idx && candidates[i] == candidates[i-1]) continue;

            if (candidates[i] > target) break;
            
            vec.push_back(candidates[i]);
            dps(candidates, target-candidates[i], vec, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // add
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dps(candidates, target, vec, 0);
        return ans;
    }
};

216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
====>
class Solution {
public:
vector<vector<int>> ans;
    void dps(int k, int n, vector<int> vec, int idx)
    {
        if (vec.size() == k)
        {
            if (0 == n) ans.push_back(vec);
            return;
        }

        for (int i = idx; i<=9; i++)
        {
            if (i>n) break;
            
            vec.push_back(i);
            dps(k, n-i, vec, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        dps(k,n,vec,1);
        return ans;
    }
};

46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
====>
class Solution {
public:
vector<vector<int>> ans;
    bool checkExist(vector<int>& vec, int idx)
    {
        for (auto x : vec)
        {
            if (x == idx) return true;
        }
        return false;
    }

    void dps(vector<int>& nums, vector<int>& vec)
    {
        if (vec.size() == nums.size())
        {
            vector<int> tmp;
            for (auto x:vec) tmp.push_back(nums[x]);
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i<nums.size(); i++)
        {
            if (checkExist(vec, i)) continue;

            vec.push_back(i);
            dps(nums, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        dps(nums,vec);
        return ans;
    }
};

47. 全排列 II
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
===>
class Solution {
public:
vector<vector<int>> ans;
    bool checkExist(vector<int>& vec, int idx)
    {
        for (auto x : vec)
        {
            if (x == idx) return true;
        }
        return false;
    }

    void dps(vector<int>& nums, vector<int>& vec)
    {
        if (vec.size() == nums.size())
        {
            vector<int> tmp;
            for (auto x:vec) tmp.push_back(nums[x]);
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i<nums.size(); i++)
        {
            if (checkExist(vec, i)) continue;
            
            // add
            if (i>0 && nums[i]==nums[i-1] && checkExist(vec, i-1)) continue;

            vec.push_back(i);
            dps(nums, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // add
        sort(nums.begin(), nums.end());
        vector<int> vec;
        dps(nums,vec);
        return ans;
    }
};

93. 复原IP地址
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
====>
class Solution {
public:

int N;
vector<vector<int>> ans;

    void dps(vector<int> &vec, int idx)
    {
        if (3 == vec.size())
        {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i<N; i++)
        {
            if (vec.empty())
            {
                if (i>3) break;
            }
            else
            {
                if (i - vec[vec.size()-1] > 3) break;
            }

            if (2 == vec.size())
            {
                if (N - i > 3) continue;
            }

            vec.push_back(i);
            dps(vec, i+1);
            vec.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        this->N = s.length();
        vector<int> vec;
        dps(vec, 1);
        vector<string> vecstring;
        for (int i = 0; i<ans.size(); i++)
        {
            int a = atoi(s.substr(0, ans[i][0]).c_str());
            int b = atoi(s.substr(ans[i][0], ans[i][1]-ans[i][0]).c_str());
            int c = atoi(s.substr(ans[i][1], ans[i][2]-ans[i][1]).c_str());
            int d = atoi(s.substr(ans[i][2], N-ans[i][2]).c_str());
            if (a<=255 && b<=255 && c<=255 && d<=255)
            {
                string str = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
                if (str.size() == N+3) vecstring.push_back(str);
            }
        }
        return vecstring;
    }
};

方法2 =====>
class Solution {
public:
vector<string> ans;

    void dps(string s, vector<string> &vec)
    {
        if (4 == vec.size())
        {
            if (s.empty())
            {
                string str;
                for (auto x: vec)
                {
                    if (str.empty()) str += x;
                    else str += '.' + x;
                }
                ans.push_back(str);
            }
            return;
        }

        for (int i = 1; i<=s.length(); i++)
        {
            if (i>3) break;
            string subs = s.substr(0, i);
            int isubs = atoi(subs.c_str());
            string subs2 = to_string(isubs);
            if (isubs>255) break;
            if (subs != subs2) break;

            vec.push_back(subs);
            dps(s.substr(i), vec);
            vec.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> vec;
        dps(s, vec);
        return ans;
    }
};

491. 递增子序列
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
====>
class Solution {
public:

vector<vector<int>> vecs;
int N;

    void recurive(vector<int>& nums, vector<int>& vec, int idx)
    {
        if (vec.size()>1)
        {
            vecs.push_back(vec);
        }

        set<int> sets;
        for (int i = idx; i<N; i++)
        {
            if (!vec.empty() && nums[i]<vec.back()) continue;

            if (sets.find(nums[i]) != sets.end()) continue;
            sets.insert(nums[i]);

            vec.push_back(nums[i]);
            recurive(nums, vec, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->N = nums.size();
        vector<int> vec;
        recurive(nums, vec, 0);
        return vecs;
    }
};

131. 分割回文串
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

=====>
class Solution {
public:
vector<vector<string> > ans;

    bool isEcho(string & s)
    {
        return s==string(s.rbegin(), s.rend());
    }

    void dps(string s, vector<string> & vec)
    {
        if (s.empty())
        {
            ans.push_back(vec);
            return;
        }

        for (int i = 1; i <= s.length(); i++)
        {
            string subs = s.substr(0, i);
            if (!isEcho(subs)) continue;
            
            vec.push_back(subs);
            dps(s.substr(i), vec);
            vec.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> vec;
        dps(s, vec);
        return ans;
    }
};

```

