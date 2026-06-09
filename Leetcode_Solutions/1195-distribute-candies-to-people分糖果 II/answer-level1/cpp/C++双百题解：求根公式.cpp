### 解题思路

利用求根公式求出可以完整地发多少次糖果，还剩下多少糖果，依次分发即可。


### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        //利用求根公式，算出糖果完整地发可以发多少轮，int向下取整即可。
        int round = (int)(sqrt(2*candies + 0.25) - 0.5); 
        ////发完round轮之后还剩下left个糖果
        int left = candies - round * (round + 1) * 0.5;
        //利用round轮数对小朋友个数取模，依次把糖果发给小朋友，每次比上次多发一个。
        for(int i = 0; i < round; i++){
            res[i % num_people] += i+1;
        }
        //把剩下的糖果给最后一个小朋友
        res[round % num_people] += left;
        return res;
    }
};
```