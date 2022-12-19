```cpp
class Solution {
public:
    int addDigits(int num) {
        int slow = num,fast = num;
        do{
            slow = newNum(slow);
            fast = newNum(fast);
            fast = newNum(fast);
            
        }while(slow != fast);
        return slow;
    }
    int newNum(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
```
