```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::set<int> s1;
        int maxsizes = candies.size()/2;
        int maxsize = candies.size();
        int i = 0;
        while(s1.size() < maxsizes && i < maxsize) {
            s1.insert(candies[i]);
            ++i;
        }
        return s1.size();
    }
};
```
![image.png](https://pic.leetcode-cn.com/86a34c84a81e019e866b5ab946176877c57236a2f39c0b0c61b401b5fc6a3f1c-image.png)
不知道哪里不好 其实我是优化了的 希望大家给点建议!
