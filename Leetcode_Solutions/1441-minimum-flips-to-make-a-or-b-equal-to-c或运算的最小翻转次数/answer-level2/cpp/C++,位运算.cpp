```
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        while(a>0||b>0||c>0){
            int m=a&1,n=b&1,k=c&1;
            if((m|n)!=k){//注意优先级，所以要加上括号。。。
                if(k==1){
                    cnt++;
                    //cout<<cnt<<endl;
                }else{
                    if(m==1&&n==1)cnt+=2;
                    else cnt++;
                    //cout<<cnt;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return cnt;
    }
};
```
