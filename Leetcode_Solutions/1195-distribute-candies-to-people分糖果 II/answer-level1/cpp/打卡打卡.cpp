### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int num = 1;
        int i=0;
        vector<int> ans;
        for(int j=0;j<num_people;j++){
            ans.push_back(0);
        }
        while(candies-num >=0){
            ans[i] += num;
            i = (i+1)%num_people;
            candies-=num;
            num++;
        }
        ans[i] += candies;
        return ans;
    }
};
```