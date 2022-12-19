### 解题思路
由于不知道逻辑执行次数，所以用while循环做
### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int times=0;
        while(num!=0)
        {
            if(num%2==0){num/=2;}
            else{num=num-1;}
            times++;
        }
        return times;
    }
};
```