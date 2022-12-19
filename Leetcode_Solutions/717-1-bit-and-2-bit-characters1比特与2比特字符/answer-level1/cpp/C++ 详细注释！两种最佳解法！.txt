两种解法：
1. 从前往后
2. 从后向前

详细过程见注释！

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


```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 1. i 从倒数第 2 个元素开始，最终的 i 代表数组最后一个元素左边连续 1 的开头索引
        int i = bits.size() - 2;
        
        // 2. 从后往前寻找目标 i
        // 比如 0 1 1 1 1 0 序列，则最后的 i 指向第一个 1
        while (i >= 0 && bits[i] == 1) i--;

        // 3. 计算连续 1 的个数
        // bits.size() 是长度，而 i 是索引，长度比索引要大 1，这点要注意，不然这句代码不好理解
        // 0    1   1   1       1           0
        //      i          bits.size() - 1
        // 所以中间连续 1 的个数为：bits.size() - 1 - i + 1 = bits.size() - i
        return (bits.size() - i) % 2 == 0;
    }
};
```