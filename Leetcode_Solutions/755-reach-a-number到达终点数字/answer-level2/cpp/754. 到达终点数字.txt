```
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int k=0;
        int sum=0;
        while(sum<target)
        {
            sum+=(++k);
        }
        while((sum-target)%2==1)
        {
            sum+=(++k);
        }
        return k;
    }
};
```
