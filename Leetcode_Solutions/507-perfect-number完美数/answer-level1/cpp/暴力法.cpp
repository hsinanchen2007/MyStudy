

### 代码

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return 0;
        int sum=1;
        for(int i=2;i<sqrt(num);i++)
            if(num%i==0) sum+=(i+num/i);
        return num==sum;
    }
};
```