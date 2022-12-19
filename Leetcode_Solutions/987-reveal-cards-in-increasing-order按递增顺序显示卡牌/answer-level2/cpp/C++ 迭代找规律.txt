在剩余的空位中找到第二个空位放下一个较大的数即可
```
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int N = deck.size();
        vector<int> res(N, 0);
        res[0] = deck[0];
        int i = 0;
        int j = 1;
        while (j < N) {
            int empty = 0;
            while (empty < 2) {
                i = (i + 1) % N;
                if (res[i] == 0) ++empty;
            }
            // 在剩余的空位中找到第二个空位放下一个较大的数即可
            res[i] = deck[j++];
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/cd012269df6631a3939e5d01762dddae9183fe17a5a1a46131b8c3a1f6711a47-image.png)
