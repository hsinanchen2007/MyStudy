假设k行， 1 + 。。。+ k = k ( k + 1 ) / 2;
解不等式 k (k + 1) / 2 <= n;
k^2 + k ＜＝ n　×　２；
配方　４ｋ＾２　＋　４ｋ　＋　１　＜＝　８ｎ　＋　１； 
２ｋ　＋　１　＜＝　ｓｑｒｔ（８ｎ　＋　１）；
ｋ　＜＝　（ｓｑｒｔ（８ｎ＋１）－１）／２；
```
class Solution {
public:
    int arrangeCoins(int n) {
       return (sqrt(n * 8.0 + 1) - 1) / 2;
    }
};
```
