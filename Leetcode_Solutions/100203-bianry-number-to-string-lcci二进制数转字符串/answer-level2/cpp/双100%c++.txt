### 解题思路
只要判断边界为2的-31次方即可

### 代码

```cpp
class Solution {
public:
    string printBin(double num) {
        double temp=0.5;
        string res="0.";
        while(num)
        {
            if(num>=temp)
            {
                res+="1";
                num-=temp;
            }
            else
                res+="0";
            temp/=2.0;   
            if(temp<pow(2,-31))
                return "ERROR";
        }
        return res;
    }
};
```