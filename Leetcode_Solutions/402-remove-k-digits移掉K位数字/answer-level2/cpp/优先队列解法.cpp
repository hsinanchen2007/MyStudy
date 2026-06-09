代码写的很糟糕，如果有需要可以私信我，我重新写一遍
```
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0)
            return num;
        int idx = 0, j;
        bool flag = true;
        while (k > 0 && idx < num.size() && flag) {
            flag = false;
            for (int i = idx; i < num.size() && i <= idx + k; i++) {
                if (num[i] == '0') {
                    j = i + 1;
                    for (; j < num.size(); j++) {
                        if (num[j] != '0') {
                            break;
                        }
                    }
                    k -= i - idx;
                    idx = j;
                    flag = true;
                    break;
                }
            }
        }

        if (k <= 0 || idx >= num.size() - 1) {
            if (j < num.size())
                return num.substr(j, num.size() - j);
            return "0";
        }
        
        // 用 lambda 比较元素。
        auto cmp = [](auto& left, auto& right) { return left.first > right.first; };
        std::unique_ptr<std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(cmp) >> q = std::make_unique<std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(cmp) >>(cmp);
        std::set<int> filter;
        int left = idx;
        for (int i = idx; i < num.size(); i++) {
            if (q->size() >= k) {

                if (q->top().first <= num[i]) {
                    int r = q->top().second;
                    q->pop();
                    
                    decltype(q) tmp = std::make_unique<std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(cmp) >>(cmp);
                    while (!q->empty()) {
                        if (q->top().second > r)
                            tmp->push(std::pair<char, int>(q->top().first, q->top().second));
                        else {
                            filter.insert(q->top().second);
                        }
                        q->pop();
                    }
                    
                    k = tmp->size();
                    q = std::move(tmp);
                    
                    q->push(std::pair<char, int>(num[i], i));
                } else {
                    break;
                }
            } else {
                q->push(std::pair<char, int>(num[i], i));
            }
        }
        
        std::string res;
        
        
        while (!q->empty()) {
            filter.insert(q->top().second);
            q->pop();
        }
        
        for (int i = idx; i < num.size(); i++) {
            if (filter.count(i) > 0)
                continue;
            res.append(1, num[i]);
        }
        
        if (res.empty())
            return "0";
        return res;
    }
};
```
![Screen Shot 2019-12-01 at 9.35.17 PM.png](https://pic.leetcode-cn.com/f29b3e79793390949ba4c3c9cd968f9e8fe95640006aa2fb6e6fca9132a2c9cd-Screen%20Shot%202019-12-01%20at%209.35.17%20PM.png)
