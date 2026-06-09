# 固定二进制的位数t，对二进制的进制k进行二分查找
class Solution {
public:
    int process(long int k,long int t,long int m){
        long int base=1,sum=1,max=0x7fffffffffffffff;    
        for(long int i=1;i<=t;i++){
            //如果下一轮需要加的数已经溢出
            if(max/base<k)return 1;
            //如果加上下一轮的数会溢出
            else if(max-sum<base*k)return 1;
            base*=k;
            sum+=base;
            if(sum>m)return 1;
        }
        return m==sum? 0:-1;
    }
    string smallestGoodBase(string n) {
        long int m = stol(n);
        for(long int t=(long int)(log(m)/log(2))+1;t>=1;t--){
            long int l=2,r=m-1;
            //二分查找
            while(l<=r){
                long int mid=(l+r)/2;
                int res=process(mid,t,m);
                if(res==0)return to_string(mid);
                else if(res>0)r=mid-1;
                else l=mid+1;
            }
        } 
        return to_string(2);      
    }
};
```
