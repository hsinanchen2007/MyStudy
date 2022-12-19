```
class Solution {
public:
    int uniquePaths(int m, int n) {
        int total=m+n-2;
        long ans=1;
        int temp=1;
        int go=min(m-1,n-1);
        //计算组合数
        while(go>0){
            ans*=total;
            if(ans%go==0)
                ans/=go;
            else
                //处理不能整除的数
                temp*=go;
            total--;
            go--;
        }
        return (int)(ans/temp);
    }
};
```
