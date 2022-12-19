### 解题思路
中心思想就是一直除235，能除到变1就完事，用求余来避免不能整除。 写的时候注意一下！%的优先级，！优先级高于%。

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
        if(num==1) return true;

        while(num!=1)
        {
            if(!(num%2))
            {
                num=num/2;
                
            }
            else if(!(num%3))
            {
                num=num/3;
            }
            else if(!(num%5))
            {
                num=num/5;
            }
            else 
            {return false;}
        }

        return true;

    }
};
```