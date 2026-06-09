```
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int max_num=num+2;
        int a=1,b=1;
        for(int i=1;i*i<=num+2;i++){
            if((num+1)%i==0){
                if(abs(i-(num+1)/i)<max_num){
                    a=i,b=(num+1)/i;
                    max_num=abs(i-(num+1)/i);
                }
            }
            if((num+2)%i==0){
                if(abs(i-(num+2)/i)<max_num){
                    a=i,b=(num+2)/i;
                    max_num=abs(i-(num+2)/i);
                }
            }
        }
        return {a,b};
    }
};
```
