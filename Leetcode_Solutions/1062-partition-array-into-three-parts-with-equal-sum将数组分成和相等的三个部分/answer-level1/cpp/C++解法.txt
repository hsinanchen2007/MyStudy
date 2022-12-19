1. 判断数组的和是否能被3整除，不能则直接返回false
2. 求数组和的三分之一为aver
3. 设置计数变量count，求和变量s
4. 遍历整个数组，将遍历的值累加到s上，判断s等于aver，则count加一，并清空s
5. 如果最后count为3，则能将数组分为和相等的三个部分
![Snipaste_2019-10-26_19-20-10.png](https://pic.leetcode-cn.com/f3a80b36f3bb70acf22fe2863cf57f1e7ae8d99723c6cf725472d561895fc65c-Snipaste_2019-10-26_19-20-10.png)

```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        bool ret=false;
        
        int sum=0;
        for(int &a:A){
            sum+=a;
        }
        if((sum%3)!=0){
            return ret;
        }
        
        int s=0,count=0;
        int aver=sum/3;
        for(int i=0;i<A.size();++i){

            s+=A[i];
            if(s==aver){
                s=0;
                ++count;
            }
        }
        if(count==3){
            ret=true;
        }
        return ret;


    }
};
```
