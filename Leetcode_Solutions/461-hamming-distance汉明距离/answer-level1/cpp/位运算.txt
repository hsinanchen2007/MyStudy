### 解题思路
按位异或来判断两个整数有多少个位相同；
用按位与来判断这个数字是多少

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int i=0;
        int j= 0;
        int f = 1;
        while(j<31){
            if((z&f)!=0)
            {
                i++;
            } 
            f = f<<1;
            j++;
        }
        return i;
        
    }
};
```