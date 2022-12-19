```
class Solution {
public:
    bool isHappy(int n) {
        map<int,bool> mp;
        
        while(true){
            if(mp[n])
                break;
            
            mp[n] = true;
            int tp = 0;
            while(n != 0){
                tp += pow((n%10),2);
                n /= 10;
            }
            if(tp == 1)
                return true;
            
            n = tp;
        }
        
        return false;
    }
};
```
