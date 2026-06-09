### 解题思路
c++, 击败95.65%和100%，先统计位置和数字都相等的个数，再用数组统计数字相等位置不等的个数

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int m1[10] = {0};
        int m2[10] = {0};
        int co1 = 0;
        for (int i=0; i<secret.size(); i++){
            if (secret[i] == guess[i]){
                co1++;
                continue;
            }
            m1[secret[i] - 48]++;
            m2[guess[i] - 48]++;
        }
        int cou2 = 0;
        for (int i=0; i<10; i++){
            cou2 += min(m1[i], m2[i]);
            // cout<<m1[i]<<" "<<m2[i]<<endl;
        } 
        return to_string(co1) + 'A' + to_string(cou2) + 'B';
    }
};
```