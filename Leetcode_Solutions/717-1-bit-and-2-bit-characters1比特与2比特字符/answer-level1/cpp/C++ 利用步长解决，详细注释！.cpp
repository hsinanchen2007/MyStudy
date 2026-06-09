### 解题思路
见注释

### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 用来记录每个字符的开头索引
        int index = 0;

        // 10 或 11：index += 1 + 1 = 前进 2 步
        // 0：index += 0 + 1 = 前进一步
        while (index < bits.size() - 1)
            index += bits[index] + 1;
        
        // 如果数组内部都是 2 字节字符，则数组长度必为偶数，则 index 不可能指向最后一个元素
        return index == bits.size() - 1;
    }
};
```