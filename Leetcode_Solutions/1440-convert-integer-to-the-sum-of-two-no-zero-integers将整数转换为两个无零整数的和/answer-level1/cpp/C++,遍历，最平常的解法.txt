```
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        //int a,b,c,d;
        vector<int>ans;
        for(int i=1;i<=n;i++){
            int a,b,c,d,e;
            e=c=i;
            while(e){
                a=e%10;
                e=e/10;
                if(a==0)break;
            }
            int j=n-c;
            d=j;
            //cout<<d;
            while(j){
                b=j%10;
                j=j/10;
                if(b==0)break;
            }
            if(a!=0&&b!=0){
                ans.push_back(c);
                ans.push_back(d);
                break;
            }
        }
        return ans;
    }
};
```
