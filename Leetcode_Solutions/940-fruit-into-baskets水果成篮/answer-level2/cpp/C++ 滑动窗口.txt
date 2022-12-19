### 解题思路
实际上是找包含最多两个不同数字的最长连续子序列，因此
- 用滑动窗口 [l, r) 表示当前连续子序列
- type1/2分别指示当前窗口内的两种类型的水果
- idx1/idx2表示窗口内两种类型水果最新出现的索引值
- r从左向右遍历遍历tree按规则更新其他参数即可

### 代码

```cpp
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        if(n == 2) return n;
        int l = 0;//左端点
        int type1 = tree[l];
        int idx1 = l;
        while(idx1 < n && tree[idx1] == type1)//找第二个数，同时更新idx1
            idx1++;
        if(idx1 == n) return n;//只有一种数
        int r = idx1;//第二种数
        idx1--;//减回去以维持正确
        int type2 = tree[r];
        int idx2 = r;
        int ans = -1;
        while(r < n){
            if(tree[r] == type1){
                idx1 = r;
                r++;
            }
            else if(tree[r] == type2){
                idx2 = r;
                r++;
            }
            else{//出现第三种数
                ans = max(ans, r-l);//更新答案
                if(tree[r-1] == type1)//前一个出现的是第一种数
                    l = idx2 + 1;//去掉第二种数，idx2之后的一定都是第一种数
                else{//前一个出现的是第二种数
                    l = idx1 + 1;//去掉第一种数，idx1之后的一定都是第二种数
                    type1 = type2;//把第二种数交换到第一种数的位置去
                    idx1 = idx2;
                }
                type2 = tree[r];//第二种数用来记录新出现的数
                idx2 = r;
            }
        }
        ans = max(ans, r-l);//再次更新最后一个连续子区间值，在while种没能计算
        return ans;
    }
};
```