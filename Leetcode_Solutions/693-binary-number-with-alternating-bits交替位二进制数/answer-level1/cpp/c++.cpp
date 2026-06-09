### 解题思路
右移之后与自身异或得全一，随后与自身加一进行与操作即可得0
注意：
1.左右移问题，因为存在两种二进制类型如 0101&1010左移再异或不能得出全一，所以只能右移
2.注意长度溢出 

### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long temp;
        temp = n^(n>>1);
        return temp&(temp+1)?false:true;
    }
};
```