思路：将字符串转为数字，取n次根进行计算求解。
1. 易知，该数k = 1+ 进制+ 进制^2 +······+进制^n;
2. 最坏情况就是k-1进制，表示为11；
3. 若表示为111，那么即进制^2+进制+1 = k,进制^2 < k,即进制 < pow(k,1/2);
4. 题目说取值范围大于3，所以最小为2进制，判断(int)pow(k,1/n)>1即可。
所以做成代码如下：
```
class Solution {
public:
    string smallestGoodBase(string n) {
        stringstream ss;
        unsigned long res;
        ss<<n;
        ss>>res;
        int k = 2; 
        long jinzhi;
        while((int)pow(res-1,1.0/k) > 1){
            jinzhi = pow(res-1,1.0/k);
            if(res == cal(jinzhi,k)) return to_string(jinzhi);
            ++k;
        }
        return to_string(res - 1);
    }
    unsigned long cal(long jinzhi,int k){
        int n = 0;
        unsigned long sum = 1;
        unsigned long ress = 1;
        while(n < k){
            ress *=jinzhi;
            sum+=ress;
            ++n;
        }
        return sum;
    }
};
```
