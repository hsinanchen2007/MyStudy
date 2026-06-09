### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        long long a=0,b=0;
        long long count=0,tmp=0;
        if(x+y<z)return false;
        while(true){
            tmp=a*x-b*y-z;
            count++;
            if(count>250000)break;
            if(tmp<0)   a++;
            else if(tmp>0)  b++;
            else {
                return true;
            }
        }
        return false;
    }
};
```