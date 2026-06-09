```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[5] = {0};
        for(auto ch:text)
            switch(ch){
                case 'b': ++cnt[0];break;
                case 'a': ++cnt[1];break;
                case 'l': ++cnt[2];break;
                case 'o': ++cnt[3];break;
                case 'n': ++cnt[4];break;
            }

        cnt[2] /= 2;cnt[3] /= 2;
        int ans = 10000;
        for(auto c:cnt)
            ans = min(ans,c);
        
        return ans;   
    }
};
```