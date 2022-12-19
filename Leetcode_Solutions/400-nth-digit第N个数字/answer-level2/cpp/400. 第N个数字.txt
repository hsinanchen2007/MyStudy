### 解题思路

![QQ图片20200320181330.png](https://pic.leetcode-cn.com/46bfbf41011a93ead92edafbb4bf88b2177cec6a2c871ecd1f673de3eb069105-QQ%E5%9B%BE%E7%89%8720200320181330.png)

先计算n位于哪个区间
[1,9]
[10,99]
[100,999]
[1000,9999]
...
记录下区间的位数i
比如 11位于[10,99],用 n- 区间[1,9]的位数总和，差值为[10,99]的位数总和，为2，再从10开始累加到2即可
### 代码

```cpp
class Solution {
public:
    int res;
    void str(int n,int m){
        stringstream ss;
        ss<<n;
        string s;
        ss>>s;
        res=s[m-1]-'0';
    }
    int findNthDigit(int n) {
        if(n<10) return n;
        long pre=1,tmp=10;
        int i=1;
        long sum=9,psum; 
        while(sum<n){
            i++;
            pre=tmp;
            tmp=pow(10,i);
            psum=sum;
            sum+=i*(tmp-pre);
        }
        sum=n-psum;
        int k=sum/i;
        int t=sum%i;
        if(t==0){
            k--;t=i;
        }
        str(pre+k,t);
        return res;
    }
};
```