![image.png](https://pic.leetcode-cn.com/53f4b15e08b48b5b26fe81672dcd80f9e0947135c5fd5841a550c98031d0ae3b-image.png)

### 解题思路
返回三个比较判断的求和

### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return (guess[0] == answer[0]) + (guess[1] == answer[1]) + (guess[2] == answer[2]);
    }
};
```