### 解题思路
同时遍历两个数组，依次比较对应元素是否相等，若相等，则猜对次数+1

### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int rightNum=0, i;
        for(i=0;i<guess.size();i++){
            if(guess[i]==answer[i]) rightNum++;
        }
        return rightNum;
    }
};
```