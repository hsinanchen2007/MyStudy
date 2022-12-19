### 解题思路
输入两个数组通过一一对比来判定猜对个数

### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int a=0;
        for(int i=0;i<3;i++){
            if(guess[i]==answer[i]){a++;}
        }
        return a;
    }
};
```