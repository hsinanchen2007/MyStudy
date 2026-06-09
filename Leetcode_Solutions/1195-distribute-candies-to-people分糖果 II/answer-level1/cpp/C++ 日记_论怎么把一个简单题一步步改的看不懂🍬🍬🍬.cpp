// ### 解题思路
// &emsp; 今天快快乐乐的来打卡，一眼看过去今天的题目确实比较简单，数学方法我就不多提了，各位大佬们已经写的很好了，我来记录下我如何把一个暴力法慢慢的变得看不懂

// ### 法一
// &emsp; 法一很常规，唯一的优点是把官方题解的`candies != 0` $\rightarrow$ `candies > 0`，这样之后就不用判断$candies$需要减多少了。
// ```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 0;
        vector<int> ans(num_people, 0);
        while (candies > 0){
            ans[i % num_people] += candies - i - 1 >= 0 ? i + 1 : candies;
            candies -= (i + 1);
            ++ i;
        }

        return ans;
    }
};i
// ```

// ### 法二
// &emsp; 法二就是觉得每次分配糖果的时候都要判断，太麻烦啦。我就先假装我恰好有这么多糖果，分完他们，然后发现多分了就找他们要(自己也要吃饭的嘛，🤸‍♂️)然后优化了下，在分完之后找那个倒霉的小孩把糖果🍬拿过来(小孩:就很倒霉TAT)

// ```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 0;
        vector<int> ans(num_people, 0);
        while (candies > 0){
            ans[i % num_people] += (i + 1);
            candies -= (i + 1);
            ++ i;
        }
        ans[(i - 1) % num_people] += candies;

        return ans;
    }
};
// ```

// ### 法三
// &emsp; 好不容易到了能够虐水题的时候，千万不能轻易放过，一定得装X，怎么装怎么装，想来想去爷觉得代码短，看不懂就够装，于是继续优化下，~~压缩代码~~，~~加上std~~，把代码整的自己也看不懂就对了！！！  然后就好了🍬🍬🍬(如果能把代码压缩成一行，我将绝杀，可惜使不得)
// ```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        std::size_t i = 0;
        std::vector<int> ans(num_people, 0);
        do{ans[i % num_people] += (i + 1);}while ((candies -= (i++ + 1)) > 0);
        return (ans[(i - 1) % num_people] += candies) > 0 ? ans : ans;
    }
};
// ```
// &emsp;一次完美的分糖果🍬🍬日记 🌶💩💉💦🐮🍺