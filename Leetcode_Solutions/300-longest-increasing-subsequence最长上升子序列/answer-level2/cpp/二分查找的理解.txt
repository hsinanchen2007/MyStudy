受到[原作者](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-e)的启发，谈谈我的理解。

![444.jpg](https://pic.leetcode-cn.com/dbebb626a4ac80d215fcfad3a1f9354fce76939d1f43bc19afcc9f06625e6a09-444.jpg)


我们如何得到一个上升子序列呢？这里不严谨的用连续图像代替离散点，只供理解。
                      
+ 首先我们考察一个典型的递增序列，在情况一中，我们只需要一直向结果向量(后文以res标识)
尾部插入元素就可以得到最终的结果，并且不仅长度正确，甚至元素也是正确的。

 然而数据是波动的，不会这么理想，它可能出现以下两种情况。
+ 在情况二中，上一个的方法相同，只要元素比res的尾端元素大，就可以插入到res的尾部。这样的结果依旧是长度正确，元素正确。
+ 在情况三中，我们发现，只是推入比末端大的元素会得到错误的答案，它与正确答案的差别是在前半段不同，所以我们需要做的是更新前半段(用二分查找)，具体实现是遇到比res小的数，就用它覆盖那个在res中比它大的最小值。在这种情况下，得到的结果依然是长度正确，元素正确。
+ 在情况四中，和情况二并无太大区别，唯一的区别是结果长度相同，但是元素不对。

这里使用了STL的lower_bound实现二分查找
4ms 96.04%
```c++
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1;
        if(n==0)return 0;
        vector<int> a;
        
        a.push_back(INT_MIN);
        for(auto p:nums){
            if(p>a.back()) a.push_back(p);
            else {
                auto k=lower_bound(a.begin(),a.end(),p);
                *k=p;
            }
        }
        
        return a.size()-1;
    }
};
```

不得不说二分查找O(NlogN)真狠奥，用常规的动态规划O(n^2)要100ms左右，这直接缩到了4ms就nm离谱