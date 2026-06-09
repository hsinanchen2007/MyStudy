### 解题思路
1\滑动窗口,先作差,然后转化为和最大的子序列
2\也可以考虑用动态规划,待完善
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num=prices.size();
        if(num==0||num==1) return 0;
        vector<int> diff(num-1);
        for(int i=0;i<num-1;++i){
            diff[i]=prices[i+1]-prices[i];
        }
        int ans=0;
        int tmp=0;
        for(int i=0;i<num-1;++i){
            tmp+=diff[i];
            if(tmp<0){
                tmp=0;
            }
            else{
                if(tmp>ans){
                    ans=tmp;
                }
            }
        }
        return ans;
    }
};
```