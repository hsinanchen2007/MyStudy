    本题思路很简单，只需要判断糖果的种类是否大于糖果数量的一半，如果大于糖果数量的一半，则妹妹能分到的糖果种类为糖果数量的一半，如果糖果种类小于等于糖果数量的一半，则妹妹能分到的糖果种类即为糖果的种类。代码如下：
```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        vector<int> tmp = candies;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end()); //保留糖果的种类
        if (tmp.size() > candies.size()/2)  //判断糖果种类是否大于糖果数量的一半
            return candies.size()/2;
        return tmp.size();
    }
};
```
