### 解题思路
本题采用95题的[@windliang](/u/windliang/)解法4思路
https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/
一开始直接调用原代码返回数组长度时超时了，所以本题解删去了节点的生成复制过程。

将n+1插入大小为n的某一搜索树时，可能的情况取决于原搜索树的右链长度（root->root.right->root.right.right....）。
![image.png](https://pic.leetcode-cn.com/0b547326033798bbbabbbaccc27990a14f2928243557c8999e3af6016f7bd63f-image.png)
一共有4种情况，3种情况分别替代右链的三个节点，最后一种情况插入了右链尾端的右子树。

再对生成的新搜索树进行观察，右链长度为3的搜索树可以分别生成右链长度为1,2,3,4的搜索树各一种。
n>3时，右链长度为n的搜索树只能由右链长度大于等于n-1的搜索树插入新节点构成。
由此可以得到dp数组
dp[1]:[1]
dp[2]:[1,1]
dp[3]:[2,2,1]
..........
其中dp[i][j]代表大小为i右链长度为j的搜索树的数量。
j<2时
dp[i+1][j]=sum(dp[i])
j>=2时
dp[i+1][j]=dp[i+1][j-1]-dp[i][j-2]


### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        if(!n||!(n-1))return 1;
        dp.push_back(1);
        int sum=1;
        for(int i=2;i<=n;i++)
        { 
            int tmp_sum=sum;
            vector<int> tmp;
            tmp.push_back(tmp_sum);
            tmp.push_back(tmp_sum);
            sum+=tmp_sum;
            for(int j=2;j<i;j++)
            {
                tmp_sum-=dp[j-2];
                tmp.push_back(tmp_sum);
                sum+=tmp_sum;
            }
            dp=tmp;
        }
        return sum;
    }
};
```