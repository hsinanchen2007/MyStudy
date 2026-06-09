### 解题思路
用于熟悉Leetcode界面的一道题。将猜对的次数翻译为guess[i]与answer[i]相等的次数即可。

### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int sum = 0;
		for (int i = 0; i < guess.size(); i++) {
			sum += (guess[i] == answer[i]);
		}
		return sum; 
    }
};
```