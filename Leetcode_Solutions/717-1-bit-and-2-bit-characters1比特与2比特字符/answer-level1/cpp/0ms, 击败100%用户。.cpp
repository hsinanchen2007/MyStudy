### 解题思路
我们观察可以发现两位10，11满足前一位为1，那么我们可以根据这个性质来判断当前这位是否可以和前一位配对。
### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1)
            return true;
        for(int i = 1 ; i < bits.size() ; ++i)
        {
            if(bits[i - 1] == 1)
            {
                if(i == bits.size() - 1)    //如果最后一位可以和前一位配对
                    return false;
                bits[i] = 0;    //配对之后置0
                i++;
            }
        }
        return true;
    }
};
```