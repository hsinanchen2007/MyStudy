### 解题思路
1.用m数组来计数出现过的元素，并且发现相对应的数字时增加b值并消除计数。

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0,b = 0,m[256] = {0};
        for(int i = 0;i <  secret.size();i++){
            if(secret[i] == guess[i]) a++;
            else{
                if(m[secret[i]]++ < 0) b++;
                if(m[guess[i]]-- > 0) b++;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
```