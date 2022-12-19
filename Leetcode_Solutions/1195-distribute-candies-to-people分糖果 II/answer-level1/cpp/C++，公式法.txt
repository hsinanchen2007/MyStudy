### 解题思路
暴力法，while循环发糖果，直到发完
公式法，先算出一共能发多少次，然后利用等差数列公式直接求得每个小孩得到的糖果

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int n = 0;

        while((n*(n+1)/2) <= candies){
            ++n;
        }
        --n;

        for(int i = 0; i < num_people; ++i){
            if(i < n%num_people) ans[i] = ((i*2 + 2 + num_people * (n/num_people))*(n/num_people + 1))/2;
            else ans[i] = ((i*2 + 2 + num_people * (n/num_people - 1))*(n/num_people))/2;
        }

        ans[n%num_people] += candies - (n*(n+1)/2);

        return ans;
    }
};
```