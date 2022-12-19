### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size()) {
            return "";
        }
        unordered_map<char, vector<int>> dict;
        for (int i = 0; i < secret.size(); ++i) {
            if(dict[secret[i]].empty()) {
                dict[secret[i]].resize(2,1);
                dict[secret[i]].push_back(i);
            } else {
                dict[secret[i]][0] += 1;
                dict[secret[i]][1] += 1;
                dict[secret[i]].push_back(i);
            }
        }
        
        int total = 0, right = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (dict[guess[i]].size() && dict[guess[i]][0] > 0) {
                // dict[guess[i]][0] -= 1;
                if (dict[guess[i]][1] > 0) {
                    total += 1;
                    dict[guess[i]][1] -= 1;
                }
                if (Guess(dict[guess[i]], i, right)) {
                    dict[guess[i]][0] -= 1;
                }
            }
        }
        return to_string(right) + "A" + to_string(total - right) + "B";
    }
    bool Guess(const vector<int>& nums, int index, int& right) {
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] == index) {
                right += 1;
                return true;
            }
        }
        return false;
    }
};
```