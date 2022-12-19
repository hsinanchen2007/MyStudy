# $O(N^2)$
## Brute-force
- chips.size() <= 100

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int min = 100;
        
        for (int i = 0; i < chips.size(); i++) {
            int c = 0;
            for (int j = 0; j < chips.size(); j++) {
                if (abs(chips[i] - chips[j]) % 2) {
                    c++;
                }
            }
            min = std::min(min, c);
        }
        return min;
    }
};
```
### Complextity
- Time: $O(N^2)$
- Space: $O(1)$

# $O(N)$
- 剖析题意，统计奇偶
```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;

        for (int i = 0; i < chips.size(); i++) {
            if (chips[i] % 2) {
                odd++;
            } else {
                even++;
            }
        }
        return std::min(odd, even);
    }
};
```

### Complexity
- Time: $O(N)$
- Space: $O(1)$

