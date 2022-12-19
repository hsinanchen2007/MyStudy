### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int step=0;
        while(num>0)
        {
            if(num%2==1) 
            {
                --num;
            }else
            { 
                num=num>>1;
            }
            ++step;
        }
        return step;

    }
};
```