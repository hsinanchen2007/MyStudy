给我20块钱，有十块的可以找，就不用三张五块的。这算不算贪心？
```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0,c=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                a++;
            }else if(bills[i]==10){
                b++;
                if(a==0){
                    return false;
                }
                a--;
            }else{
                c++;
                if(b>0&&a>0){
                    b--;
                    a--; 
                }else if(a>=3){
                    a=a-3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
```
