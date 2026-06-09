### 解题思路
顺着思路走。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);//创建返回数组，并初始化
        int cur=1;//游标，记录当前需要分配的糖果个数
        while(candies!=0){
            int t=(cur-1)%num_people;//定位当前小朋友
            if(candies>=cur) {//如果糖果个数足够，则按需分配
                ans[t]+=cur;
                candies-=cur;
            }
            else if(candies<cur){//不够就给剩下全部糖果，然后糖果清零。
                ans[t]+=candies;
                candies=0;
            }
            ++cur;//增加游标
        }
        return ans;
    }
};
```