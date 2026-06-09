### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num + 1;
        int num2 = num + 2;
        vector<int> ans;
        int abso = num2;
        int a, b;
        for(int i = (int)sqrt(num2) ; i >= 1 ; i--)
        {
            if(num1 % i == 0)
            {
                int temp = num1 / i;
                if(abs(temp - i) < abso)
                {
                    abso = abs(temp - i);
                    a = i;
                    b = temp;
                }
            }
            else if(num2 % i == 0)
            {
                int temp = num2 / i;
                if(abs(temp - i) < abso)
                {
                    abso = abs(temp - i);
                    a = i;
                    b = temp;
                }
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
```