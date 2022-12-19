### 解题思路
此处撰写解题思路
注意n很大(10^9)，而reservedSeats所影响的行数不超过10^4。所以不要把n个状态直接用vector表示出来。那些没有被影响的状态可以直接用减法计算出来
### 代码

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 0;
        map<int, char> s; // 0 for blank/available
        for (int k =0; k< reservedSeats.size(); k++){
            int i = reservedSeats[k][0];
            int j = reservedSeats[k][1];
            if (j>=2 && j <=9){

                if (s.count(i-1) == 0){
                    s[i-1] = 0;
                }

                s[i-1] |= (1 << (j-2));
            }
        }

         char b0 = 0xff; // 0b 1111 1111 = 0xff
        char b1 = 0x3c; // 0b 0011 1100 = 0x3c
        char b2 = 0xf0; // 0b 1111 0000 = 0xf0
        char b3 = 0x0f;

        // printf("s.size()=%d\n", s.size());
        for (pair<const int, char>& p: s){
            char a = p.second;
            // printf("%0#X\n", a);
           
            if ( a == 0){
                res += 2;
            }
            else if ((a & b1) == 0 || (a & b2) == 0 || (a & b3) == 0){
                //0b01 1110 0000 = 0x1e0
                res += 1;
            }            
        }
        return res + 2 * (n-s.size());
    }
};
```