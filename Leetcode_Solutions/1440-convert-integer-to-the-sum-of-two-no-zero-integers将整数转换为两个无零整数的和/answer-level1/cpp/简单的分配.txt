尽量平分，为了保证无0，每一位至少是2，不足2的从高位取。
```
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> digits;
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        for(int i=0;i<digits.size()-1;i++){
            if(digits[i]<2){
                digits[i+1]-=1;
                digits[i]+=10;
            }
        }
        int x=0,y=0;
        for(auto it=digits.rbegin();it!=digits.rend();it++){
            x=x*10+*it/2;
            y=y*10+(*it+1)/2;
        }
        return {x,y};
    }
};
```

精简一下

```
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int x=0,y=0,k,m=1;
        while(n){
            k=n%10;n/=10;
            if((k<2)&&(n>0)){k+=10;n--;}
            x=x+(k/2)*m;
            y=y+((k+1)/2)*m;
            m*=10;
        }
        return {x,y};
    }
};
```

