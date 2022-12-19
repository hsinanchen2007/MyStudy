### 解题思路
与其他人不同的是把比较判断换成了异或判断，内存消耗降了0.2M
![image.png](https://pic.leetcode-cn.com/1d5cbb1db6fdde033e6f5ec4370bf171d0203bfa206484e40618a33430d88523-image.png)


### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return !(guess[0]^answer[0]) + !(guess[1]^answer[1]) + !(guess[2]^answer[2]);
    }
};
```