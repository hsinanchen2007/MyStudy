### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        while(a){//用a保存进位，若a==0，说明没有进位了
        int temp=a^b;
           a=(unsigned int )(a&b)<<1;
           b=temp;
        }
        return b;
    }
};
```