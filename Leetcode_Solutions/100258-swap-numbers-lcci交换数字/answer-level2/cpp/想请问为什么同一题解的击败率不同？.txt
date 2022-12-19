### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/4447a262f27462e52a10689106d674ff607ef772a87f70b472bc6d19fd76e079-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        return {numbers[1],numbers[0]};
    }
};
```