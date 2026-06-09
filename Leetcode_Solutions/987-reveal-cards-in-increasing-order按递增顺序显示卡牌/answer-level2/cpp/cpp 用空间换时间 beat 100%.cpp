![image.png](https://pic.leetcode-cn.com/d6d712a45be20535a9c1667cdd4912cbde56b47f92da0922f8e4dafb46d572d6-image.png)

```
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.begin(), deck.end(), [] (int a, int b) { return a > b; });
        for (int num : deck) {
            if (!temp_.empty()) {
                temp_.push_front(temp_.back());
                temp_.pop_back();
            }
            temp_.push_front(num);
        }

        std::transform(temp_.begin(), temp_.end(), deck.begin(), [] (auto num) { return num; } );
        return deck;
    }
private:
    list<int> temp_;
};
```

list能够高效地两端插入删除，因此用list作中转
