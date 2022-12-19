
### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int sum=0;

        while(num!=0)
        {
            if(num%2==1) num--;
            else num>>=1;//等同于num=num/2;
            sum++;
        }

        return sum;
    }
};
```