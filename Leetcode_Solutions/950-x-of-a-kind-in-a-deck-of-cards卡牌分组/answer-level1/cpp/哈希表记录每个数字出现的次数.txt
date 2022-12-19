### 解题思路
用哈希表记录每个数字出现的次数
然后从2开始依次增加，用哈希表中不为0的数字看是否能整除，来判断是否选定的X

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        int max = 0;

        if(len<2)
            return false;
        
        int arr[10010] = {0};
        for(int i = 0;i<len;i++){
            arr[deck[i]] ++;
            max = arr[deck[i]] > max ? arr[deck[i]] : max;
        }
        
        int i,j;
        for(i = 2;i <= max+1;i++){
            for(j = 0;j <= 10000;j++){
                if(arr[j] != 0)
                    if(arr[j] % i != 0)
                        break;
            }

            if(j == 10001)
                return true;
        }

        return false;
    }
};
```