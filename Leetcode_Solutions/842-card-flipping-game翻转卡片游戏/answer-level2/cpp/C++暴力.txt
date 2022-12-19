### 解题思路


### 代码
暴力遍历，不费脑子

```cpp
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int len=fronts.size(),ans=INT_MAX;
        for(int i=0;i<len;i++){
            bool negf=0,negb=0;
            for(int j=0;j<len;j++){
                if(negf||(fronts[i]==fronts[j]&&fronts[i]==backs[j]))negf=1;
                if(negb||(backs[i]==fronts[j]&&backs[i]==backs[j]))negb=1;
                if(negf&&negb)break;
            }
            if(!negf)ans=min(ans,fronts[i]);
            if(!negb)ans=min(ans,backs[i]);
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};
```