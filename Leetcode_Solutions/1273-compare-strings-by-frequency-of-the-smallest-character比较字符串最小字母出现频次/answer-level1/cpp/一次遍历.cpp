### 解题思路
此处撰写解题思路

### 代码

```cpp
//我们来定义一个函数 f(s)，其中传入参数 s 是一个非空字符串；该函数的功能是统计 s  中（按字典序比较）最小字母的出现频次。
//例如，若 s = "dcce"，那么 f(s) = 2，因为最小的字母是 "c"，它出现了 2 次
//现在，给你两个字符串数组待查表 queries 和词汇表 words，请你返回一个整数数组 answer 作为答案，
//其中每个 answer[i] 是满足 f(queries[i]) < f(W) 的词的数目，W 是词汇表 words 中的词。

//输入：queries = ["cbd"], words = ["zaaaz"]
//输出：[1]
//解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。

//输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
//输出：[1,2]
//解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> ans;
        arr1 = statistic(queries);
        arr2 = statistic(words);

       // for(int i = 0 ; i<arr1.size();i++) cout << arr1[i];
       // cout << endl;
       // for(int i = 0 ; i<arr2.size();i++) cout << arr2[i];
        //cout << endl;
        for(int i = 0; i < arr1.size(); i++)
        {
            int k = 0;
            for(int j = 0; j < arr2.size(); j++)
            {
                if(arr1[i] < arr2[j]) k++;
            }
            ans.push_back(k);
        }
        return ans;
    }
    vector<int> statistic(vector<string> nums)//一次遍历 时间复杂度O(n)
    {
        vector<int> res;
        char min_ = nums[0][0];
        int min_nums = 1;
        for(int i = 0; i < nums.size(); i++)//依次对vector中的每一个string统计最小字母出现次数
        {
            char min_ = nums[i][0];
            int min_nums = 1;
            if(nums[i].size() == 1)
            {
                res.push_back(1);
                continue;
            }
            for(int j = 1; j < nums[i].size(); j++)
            {
              //  cout << nums[i][j]<< ' ' << min_nums<<' '<< min_ <<"qq" <<endl;
                if(nums[i][j] < min_)
                {
                    min_nums = 1;
                    min_ = nums[i][j];
                }
                else if(nums[i][j] == min_)
                {
                    min_nums++;
                }
            }
            res.push_back(min_nums);
        }
        return res;
    }
};


```