比赛时没想出来...纠结重复浇水区域。比赛后借鉴了别人的答案，自己理解后写了注释以供交流。
我认为...这道题考察的是在动态规划中如何解决重复覆盖区间问题。
简单的区域加减无法解决这个问题，必须要用到动态规划的思想。即转态的转变。
我们在每一次循环中用left表示当前浇水的开始边界，right表示此次浇水的右边界。
在开始时，我们用right=left;让right用于下面判定当前水龙头是否能在当前区域内浇水。即right=max(right,i+ranges[i]);
在循环末尾时，用left=right;用于下一次循环前的边界判定。
在循环中，遍历每一次水龙水数组。当前水龙头覆盖区域若能覆盖左边界，即进入判定。

```
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int left=0,right=0,ans=0;
        while(left<n){
            right=left;
            for(int i=0;i<n+1;i++){
                if((i-ranges[i]<=left)&&(i+ranges[i]>left)){
                    right=max(right,i+ranges[i]);
                }
            }
            if(right==left)return -1;
            ans++;
            left=right;
            
        }
        return ans;
    }
};
```
