### 解题思路
不要想太复杂了

### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int mi=2;
        if(a>b)swap(a,b);
        if(b>c)swap(b,c);
        if(a>b)swap(a,b);
        if(a+1==b&&b+1==c)mi=0;
        else if(a+1==b||b+1==c||a+2==b||b+2==c)mi=1;
        return {mi,c-a-2};
    }
};
```