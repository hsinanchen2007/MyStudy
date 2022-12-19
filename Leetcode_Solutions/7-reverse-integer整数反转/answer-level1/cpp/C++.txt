### 解题思路
··············C++处理异常情况太蛋疼了

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
                   if (x == 0) return 0;
                   if(x == 0-INT_MAX-1) return 0;
        int result = 0;
        int temp = x;
        int length = 0;
        int is_fu = false;
        if (x < 0)
        {
            is_fu = true;
            x = 0-x;
        }
        while(temp)
        {
            temp /= 10;
            length++;
        }
        if (length == 10 && 2 > x % 10)
            return 0;
        for(int i=0;i<length;i++)
        {    
            if (INT_MAX - result < pow(10, length - 1 - i) * (x % 10))
                return 0;
            result += pow(10, length - 1 - i) * (x % 10); 
            //if (result < 0) return 0;
            x /= 10;
        }
        return result = is_fu?0-result:result;

    }
};
```