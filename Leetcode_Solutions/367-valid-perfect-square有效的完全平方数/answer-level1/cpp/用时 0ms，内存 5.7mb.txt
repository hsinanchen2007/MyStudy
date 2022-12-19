### 解题思路
若num等于1或0直接返回true。若完全平方数为偶数，其开根号结果也为偶。若完全平方数为奇数，其开根号结果也为奇数。所以我们只需要判断num的奇偶性。接着利用循环在i∈[2,√num]中的所有奇数或偶数中找是否有i*i=num。

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1 || num==0)
        {
            return true;
        }
        
        long long int i;
        if(num%2==0)
        {
           i=2; 
        }
        else
        {
            i=3;
        }
        
        for( ; i*i<=num ; i+=2)
        {
            if(i*i==num)
            {
                return true;
            }
        }
        return false;

    }
};
```