这里用的动态规划和双指针的想法。我在本子上写了一个没过的测试条件
`[1,2,87,87,87,2,1]`

发现如果最左边和最右边无论如何都是最小的1。那么再往里面走一个人，如果比外面那个人分数高，那么这个人应该多分一个糖果。  
所以可以想像有两个老师，同时一个从左往右，一个往右往左分糖果。只需要看是不是比前面的人分数高，是就多分。右因为不能把分到的糖果拿回去，所以加个max。

```C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>candies(ratings.size());
        for (int i =1; i < candies.size()  ; i ++){
            int j = candies.size() - i - 1;

            if (ratings[i] > ratings[i - 1]) candies[i] = max(candies[i],candies[i - 1] + 1);
            if (ratings[j] > ratings[j + 1]) candies[j] = max(candies[j],candies[j + 1] + 1);
        }
        // for (auto & el: candies) cout << el << ", "; cout << endl;
        return accumulate(candies.begin(), candies.end(), candies.size());
    }
};
```

不着急写，先拿个笔和本子自己算一遍有时真有奇效。