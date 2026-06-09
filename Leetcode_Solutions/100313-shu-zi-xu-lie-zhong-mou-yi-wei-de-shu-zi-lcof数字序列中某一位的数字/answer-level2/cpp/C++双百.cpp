```
class Solution {
public:
    int findNthDigit(int n) {
        long a=9;
        long tmp = n;
        long count = 2;
        if(tmp <= 9)
            return n;
        tmp -= 9;
        while(tmp>a*count){
            tmp -= a*count;
            count++;
            a *= 10;
        }
        long ans = pow(10,count-1)+(tmp/count)-1;
        if(tmp%count == 0){
            string a = to_string(ans);
            return a[a.size()-1]-'0';
        }else{
            ans++;
            string a = to_string(ans);
            return a[tmp%count-1]-'0';
        }
    }
};
```
