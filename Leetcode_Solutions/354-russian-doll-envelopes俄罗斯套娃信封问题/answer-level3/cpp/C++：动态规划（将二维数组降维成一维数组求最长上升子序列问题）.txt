**题解：**

* 本题属于[300. 最长上升子序列](https://blog.csdn.net/qq_43152052/article/details/104090137)的子题，难点在于如何处理`envelopes`数组？解决方法当然是排序了，然而这个排序还是比较难想的，我讲一下吧。

* **排序：排序的主要作用是降维，将二维数组转换为一维数组，然后进行寻找最长上升子序列。**

* 1）若w不相同，则按w由小到大进行排序。这样做的好处是：由于w由小到大进行排序了，那么只有h是上升的才能构成上升的子序列（**即w已经可套娃了，判断h是否可套娃即可**）。比如`[1,1]、[2,0]、[3,1]、[4,2]`，降维之后的数组为`[1,0,1,2]`，这里可套娃的子序列有`[1,1]、[4,2]`对应`[1,2]`，还有`[2,0]、[3,1]、[4,2]`对应`[0,1,2]`等。
* 2）若w相同，则按h由大到小排序进行排序。这样做的好处是：由于w相等，那么只有h由大到小排序才不会计算重复的子序列（**即w相等，只有h由大到小排序才不会重复计算套娃信封**）。比如`[3,4]、[4,6]、[4,7]`，若按h由小到大排序降维之后的数组为`[4,6,7]`，这样形成的可套娃的序列长度为3，这个是不正确的，因为只有`(w2>w1,h2>h1)`才能进行套娃。若我们按h由大到小排序之后降维之后的数组为`[4,7,6]`，这样可形成两个长度为2的可套娃子序列`[3,4]、[4,7]`和`[3,4]、[4,6]`，这样便满足条件了。

* 注：由于目前 lc 对 markdown 语法支持不全，大家可以看我的博客，这样颜色标记会好一点。

* 我的博客地址：[354. 俄罗斯套娃信封问题题解](https://blog.csdn.net/qq_43152052/article/details/104099612)。

**补充：**
同样的做法也适用于[646. 最长数对链](https://leetcode-cn.com/problems/maximum-length-of-pair-chain/solution/cdong-tai-gui-hua-er-fen-fa-tan-xin-fa-yi-ti-duo-j/)。

**代码如下：**
```cpp
class Solution {
public:
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int maxEnvelopes_1(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        int n=envelopes.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

    //优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes){
        if(envelopes.empty())return 0;
      //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<int> dp;
        for(auto& en:envelopes){
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();
            if(idx>=dp.size()){
                dp.emplace_back(en[1]);
            }
            else{
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};
```
