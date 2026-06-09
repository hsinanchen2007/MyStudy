### 解题思路
每位都和1做异或即可

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        int tmp=num;
        int cnt=0;
        while(tmp){
            tmp>>=1;cnt++;
        }
        return num^(int)(pow(2,cnt)-1);
    }
};
```