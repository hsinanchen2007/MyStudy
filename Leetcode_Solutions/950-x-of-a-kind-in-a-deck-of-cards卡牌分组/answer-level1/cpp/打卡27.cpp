### 解题思路
  这里用的是排序后对每个相同的个数进行gcd，也就是找到这些数字的最大公共约数。如果这个公约数是小于2的肯定是不符合的。当然期间，统计出的个数如果小于2也直接可以结束。
  这题之前我是用map做的，思路是一样的。发现空间和时间都还是map来的少。

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        if(n <= 1)return false;
        sort(deck.begin() , deck.end());
        int c = 1;
        int t = 0;
        for(int i = 1 ; i < n ; i++){
            if(deck[i] == deck[i - 1]){
                c++;
            }
            else{
                if(c < 2)return false;
                if(t == 0)t = c;
                t = gcd(t , c);
                if(t < 2)return false;
                c = 1;
            }
        }
        if(t == 0)return c >= 2;
        return gcd(t , c) >= 2;
    }

    int gcd(int x , int y){
        if(y == 0)return x;
        return gcd(y , x%y);
    }
};
```