

### 代码

```cpp
class Solution {
public:
    int count[10000];
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==0||deck.size()==1)
            return false;
        for(int n:deck)
            ++count[n];
        int g=0;
        for(int i=0;i<10000;i++){
            if(count[i]>0){
                if(g){
                    g=gcd(g,count[i]);
                    if(g<2) return false;
                }
                else g=count[i];
            }
        }
        return true;
    }
};
```