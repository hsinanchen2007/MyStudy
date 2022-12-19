## 逐轮对比即可，记录猜对的次数
```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans = 0;
        for(int i = 0; i < 3; ++ i){
            if(guess[i] == answer[i])    ++ ans;
        }
        return ans;
    }
};
```
