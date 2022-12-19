
求和令为sum。若 sum % 3
- 0 
- 1：减去余 1 的最小值；或者，减去两个余 2 的最小值
- 2：减去余 2 的最小值；或者，减去两个余 1 的最小值

```
class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    const int inf = 5e5;
    int sum = accumulate(nums.begin(),nums.end(),0);
    int d = sum%3;
    if(!d) return sum;
    vector<int>h[3];
    for(int i = 0;i < 3;++i) for(int j = 0;j < 3;++j) h[i].push_back(inf);
    for(auto i : nums){
      if(i%3){
        if(h[i%3][0] >= i) h[i%3][1] = h[i%3][0],h[i%3][0] = i;
        else if(h[i%3][1] >= i) h[i%3][1] = i;
      }
    }
    int delta = inf;
    if(d == 1) delta = min(h[1][0],h[2][0]+h[2][1]);
    else delta = min(h[1][0] + h[1][1] ,h[2][0]);
    if(delta >= inf) return 0;
    return sum-delta;
  }
};
```
