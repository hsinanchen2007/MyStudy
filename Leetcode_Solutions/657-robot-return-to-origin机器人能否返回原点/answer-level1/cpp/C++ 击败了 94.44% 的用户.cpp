### 解题思路
![1 (2).png](https://pic.leetcode-cn.com/2a63fbc1a834ff1462d057bfb6b641e35d991902b322cb78682ae90366bb48d4-1%20\(2\).png)

### 代码

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0,y = 0;
        for(auto ch : moves){
            switch(ch){
                case 'L':x--;break;
                case 'R':x++;break;
                case 'U':y++;break;
                case 'D':y--;break;
            }
        }
        return !x&&!y;
    }
};
```