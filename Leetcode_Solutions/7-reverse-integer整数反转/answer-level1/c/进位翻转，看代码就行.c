
感觉思路比较清晰 没写注释


```cpp
class Solution {
public:
    int reverse(int x) {
        long ans=0;
        int max=0x7fffffff;
        int min=0x80000000;
        while(x!=0){
            ans=ans*10+x%10;
            x/=10;
        }
        if(ans>max||ans<min) 
        return 0;
        return ans;
    }
};
```