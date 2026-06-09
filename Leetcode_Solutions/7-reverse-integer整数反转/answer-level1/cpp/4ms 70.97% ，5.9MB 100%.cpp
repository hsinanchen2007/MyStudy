### 解题思路


### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        if(x < 10 && x>-10 ) //正负10以内返回
            return x;

        int temp = x%10;
        x = x/10;

        while(x>=10||x<=-10)
        {
            temp = temp*10 + x%10;
            x = x/10;
            if(temp > INT_MAX/10 || temp < INT_MIN/10)  //检查溢出
                return 0; 
        }
        temp =temp*10 + x;


          
      return temp;
    }
};
```