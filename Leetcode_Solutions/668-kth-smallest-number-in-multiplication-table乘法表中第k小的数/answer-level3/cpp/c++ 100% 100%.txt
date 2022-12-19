和[[https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/](有序矩阵中第k小的元素)]是一样的题，但是多了一个规则：乘法表。因此最好把乘法表的规则用上，而不是简单的有序表。
```

class Solution {
public:
    int count(int m,int n,int num){
        int ret=0;
        for(int i=0;i<m;i++){
            if((i+1)*n<=num){
                ret+=n;
            }else{
                ret+=(num/(i+1));
            }
        }
        return ret;
    }
    
    int findKthNumber(int m, int n, int k) {
        if(k==1)return 1;
        if(k==m*n)return m*n;
        int left=0,right=m*n;
        int c=0;
        while(left<right){
            int mid=left+(right-left)/2;
            c=count(m,n,mid);
            //cout<<"mid "<<mid<<" c "<<c<<endl;
            if(c<k){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};

```
