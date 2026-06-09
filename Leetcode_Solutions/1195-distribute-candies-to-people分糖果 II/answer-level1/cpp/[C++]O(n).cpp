### 解题思路
数学题

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        long long end=(sqrt(1+8*double(candies))-1)/2;
        long long times=end/num_people,last=end%num_people;
        vector<int> ans(num_people,0);
        for(int i=0,finaltime=times*num_people+1,repeat=times+(long long)num_people*times*(times-1)/2;i<num_people;++i,repeat+=times,++finaltime){
            ans[i]+=repeat;
            if(i<last) ans[i]+=finaltime;
        }
        ans[last]=ans[last]-(1+end)*end/2+candies;
        return ans;
    }
};
```