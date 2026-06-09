思路和67题二进制求和一样，不要转成数字去做，内存吃不起，就用各个位累加前推方法
先补位，再依次相加，处理好进位关系即可。
```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> kk;
        while(K){
            kk.insert(kk.begin(),K%10);
            K/=10;
        }

        int a=A.size();int b=kk.size();
        while(a<b){
            A.insert(A.begin(),0);
            a++;
        }
        while(a>b){
            kk.insert(kk.begin(),0);
            b++;
        }

        int carry=0;
        for(int i=a-1;i>=0;i--){
            int sum=A[i]+kk[i]+carry;
            A[i]=sum%10;
            carry=sum/10;
        }
        if (carry>0) A.insert(A.begin(),carry);
        return A;
    }
};
```