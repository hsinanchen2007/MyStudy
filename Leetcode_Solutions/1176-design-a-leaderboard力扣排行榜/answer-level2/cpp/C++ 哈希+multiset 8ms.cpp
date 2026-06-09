![image.png](https://pic.leetcode-cn.com/62a344c0903768724a434eed4c191fa51f83347ef1d96b8f7632a2b9ca9420f7-image.png)


# 思路：
**对于topk，实际上不需要关注分数对应的playerId**

1.用一个array作为哈希表保存映射，id和score；
2.用一个multiset排序当前的分数

**addScore：**
1.array的分数加上score
2.如果array之前的分数为0，插入score，否则从rank删掉之前的分数重新插入

**top:**
最后k个求和

**reset:**
rank中删掉当前的score即可

```
class Leaderboard {
public:    
    void addScore(int playerId, int score) {
        auto& num = record[playerId];
        if (num == 0) {
            rank.emplace(score);
        } else {
            rank.erase(rank.find(num));
            rank.emplace(score + num);
        }
        num += score;
    }
    
    int top(int K) {
        int result = 0;
        auto iter = --rank.end();
        while (K--) {
            result += *iter--;
        }
        return result;
    }
    
    void reset(int playerId) {
        auto& num = record[playerId];
        rank.erase(rank.find(num));
        num = 0;
    }

private:
    multiset<int> rank;
    array<int, 10001> record{};
};
```
