### 解题思路
从后往前扫描，数最后一个0之前有多少个连续的1，偶数个（包括0个）为true，奇数个为false

### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=bits.size()-2;

        int one_counter=0;

        while(i>=0)
        {
            if(bits[i--]==1){++one_counter;}
            else if(one_counter%2==0){return true;}
            else {return false;}
        }
        if(one_counter%2==0){return true;}
        else {return false;}
    }
};
```