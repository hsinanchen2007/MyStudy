```
class Solution {
public:
    int tribonacci(int n) {
        int l0 = 0;
        int l1 = 1;
        int l2 = 1;
        int l3 = 0;
        
        if(n == 0){
            return l0;
        }else if(n == 1){
            return l1;
        }else if(n == 2){
            return l2;
        }else{
            for(int i = 3;i <= n; ++i){
                l3 = l0 + l1 + l2;
                l0 = l1;
                l1 = l2;
                l2 = l3;
            }
        }
        
        return l3;
    }
};
```