### 解题思路
暴力循环，有糖果就分

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> child(num_people);
        cout<<child.size();
        if((candies==0)||(num_people==0))
            return  child;
        int n =1;  //记录当前分发糖果数
        int i =0;  //记录当前小朋友
        while(candies>=n){
            child[i] += n;
            candies -= n;
            i = (i+1)%num_people;
            n++;
        }
        if(candies)
            child[i] += candies;
        return child;
    }
};
```