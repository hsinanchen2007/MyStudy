先排序，统计负数，0，正数个数。
之后嘛，枚举所有的情况即可。
看程序吧

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size()<1){
            return 0;
        }
        sort(A.begin(),A.end());
        int one = 0;
        int zeros = 0;
        int neg = 0;
        for(int i=0;i<A.size();i++){
            if(A[i]>0){
                one++;
            }else if(A[i]==0){
                zeros++;
            }else{
                neg++;
            }
        }
        if(zeros!=0){
            if(neg!=0){
                if(K<=neg){
                    fun(A,K);
                }else{
                    fun(A,neg);
                }
            }
        }else{
            if(neg!=0){
                if(K<=neg){
                    fun(A,K);
                }else{
                    fun(A,neg);
                    K = K -neg;
                    if(K%2==0){
                        K = K;
                    }else{
                        if(A[neg]-A[neg-1]>0){
                            A[neg-1]=-A[neg-1];
                        }else{
                            A[neg]=-A[neg];
                        }
                    }
                }
            }else{
                if(K%2!=0){
                    A[0]=-A[0];
                }
            }
        }
        return accumulate(A.begin(),A.end(),0);
    }
    void fun(vector<int>& A,int end){
        for(int i=0;i<end;i++){
            A[i]=-A[i];
        }
    }
};
```


![图片.png](https://pic.leetcode-cn.com/45cec803f3c29a47ce9dcd5f4a20d440fe23a2fa73fc57e493e2f00b9cb2a991-%E5%9B%BE%E7%89%87.png)
