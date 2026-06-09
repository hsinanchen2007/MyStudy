### 解题思路
简单粗暴的思路...啥时候能想到好点的算法呢

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) 
    {
        while(num)
        {
            if(num%2==0)
            {
                num=num/2;
            }
            if(num%3==0)
            num=num/3;
          
            if(num%2!=0 && num%3!=0)
            {
                if(num%5==0)
                num=num/5;
                else
                break;
            }

        }
        if(num==1)
        return true;
        else
        return false;
    }
};
```