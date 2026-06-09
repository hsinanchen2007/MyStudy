### 解题思路
做的时候首先忽略了此题目是任意位置交换，除此之外，还需要注意交换的话，一定是和位数最小的进行交换。

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string realStr = to_string(num);
        string maxStr(realStr);
        sort(maxStr.begin(), maxStr.end(), [](char a, char b){
            return a > b;
        });
        for (int i = 0; i < realStr.size(); i++) {
            if (realStr[i] != maxStr[i]) {
                char temp = realStr[i];
                int index = realStr.rfind(maxStr[i]);
                realStr[i] = maxStr[i];
                realStr[index] = temp;
                break;
            }
        }
        return stoi(realStr);
    }
};
```