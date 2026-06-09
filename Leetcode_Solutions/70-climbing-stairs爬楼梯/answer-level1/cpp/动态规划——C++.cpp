```
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n <= 2)   
            return n;
        int num1 = 1, num2 = 2;
        int sum;
        for(int i = 2; i < n; i++) //大于2时，每一项都等于前两项的和
        {
            sum = num1 + num2;
            num1 = num2;
            num2 = sum;
        } 
        return sum;
    }
};
```
