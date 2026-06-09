```
class Solution {
public:
    bool isPerfectSquare(int x) {
        float rt = x,xhalf = 0.5f*rt; 
        int i = *(int*)&rt; 
        i = 0x5f375a86- (i>>1); 
        rt = *(float*)&i; 
        rt *= (1.5f-xhalf*rt*rt); 
        rt *= (1.5f-xhalf*rt*rt); 
        int ans = 1.0f/rt+0.01f;
        return ans*ans==x;
    }
};
```
卡马克快速平方根