### 解题思路
最大公约数

### 代码

```cpp
class Solution {
    int cnt[10000] = {0};
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for(auto data:deck){
            cnt[data]++;
        }
        int g = -1;
        for(int i=0;i<10000;i++){
            if(cnt[i]>0){
                if(g != -1){
                    g = gcd(g,cnt[i]);
                }else{
                    g = cnt[i];
                }
            }
        }

        return g >= 2 ? true : false;
    }
};
```