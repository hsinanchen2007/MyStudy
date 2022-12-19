### 解题思路
时空双100%

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int i=0;
        for(i;num!=0;i++){
            if(num%2==0) num=num/2;
            else num--;
        }
        return i;
    }
};
```