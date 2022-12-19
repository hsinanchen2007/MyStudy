### 解题思路
传统if语句解决，0ms。

### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) { // e 0~9 +- .  -3.2e-4
        enum {SPACE1, INT1HEAD, INT1, INT2HEAD, INT2, SPACE2} stat = SPACE1;
        bool havenotdot=true, havenumber=false;
        for( auto& c : s )
        {
            if( ('e'==c || 'E'==c) && havenumber && INT2HEAD>stat )
            {
                stat = INT2HEAD;
                havenumber = false;
            }
            else if( '+'==c || '-'==c )
            {
                if( INT1>stat )    stat = INT1;
                else if( INT2HEAD==stat )   stat = INT2;
                else    return false;
            }
            else if( '.'==c && havenotdot && INT1>=stat )
            {
                stat = INT1;
                havenotdot = false;
            }
            else if( '0'<=c && '9'>=c && SPACE2>stat )
            {
                if( INT1>stat  )    stat = INT1;
                else if( INT2HEAD==stat )   stat = INT2;
                havenumber = true;
            }
            else if( ' '==c )
            {
                if( stat!=SPACE1 )  stat=SPACE2;
            }
            else
                return false;
        }
        return havenumber;
        
    }
};
```