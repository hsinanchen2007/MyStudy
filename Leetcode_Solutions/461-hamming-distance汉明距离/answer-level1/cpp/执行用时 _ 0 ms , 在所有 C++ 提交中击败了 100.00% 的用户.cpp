### 解题思路
此处撰写解题思路
整数%2即可求二进制
### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int output=0;
        while(x!=0||y!=0){
            if(x%2 != y%2)output++;
            x/=2;
            y/=2;
        }
        return output;
    }
};
```