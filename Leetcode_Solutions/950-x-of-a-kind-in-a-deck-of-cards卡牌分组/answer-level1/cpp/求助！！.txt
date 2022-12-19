### 解题思路
为什么int count[10000]={0};如果不加=｛0｝
就是错的呢

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        else return gcd(b, a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int count[10000]={0};
        
        int n = deck.size();
        for(int i=0; i<n; ++i){
            count[deck[i]]++;
        }
        int g = -1;
        for(int n : count){
            if(n){
                if(~g){
                    g = gcd(g, n);
                }
                else{
                    g = n;
                }
            }
        }
        return g >= 2;

    }
};
```