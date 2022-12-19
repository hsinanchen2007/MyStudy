### 解题思路
从后往前遍历，最后两个0之间有偶数个一时为真

### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int num=0;
        if(bits.size()==1) return 1;
        for(int i=bits.size()-2;i>=0;i--)
        {
            if(bits[i]==1) num++;
            else break;
        }
        if(num%2==0) return 1;
        else return false;
    }
};
```