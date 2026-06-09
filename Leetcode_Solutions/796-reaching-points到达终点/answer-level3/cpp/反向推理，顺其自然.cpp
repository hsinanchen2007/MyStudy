### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        if( sx>tx || sy>ty )    return false;
        while( sx<tx && sy<ty )
        {
            if( tx<ty ) ty=ty%tx;
            else        tx=tx%ty;
        }
        if( sx==tx && (ty-sy)%tx==0 )   return true;
        if( sy==ty && (tx-sx)%ty==0 )   return true;
        return false;

    }
};
```