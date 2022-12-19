### 解题思路
1.首先数组里面的数小于三个，直接返回false；
2.对数组里面的数求和，和不是3的整数倍，直接返回false；
3.从左往右遍历，如果s为和的1/3，就让cnt++，s=0；

在第三步考虑到如果你求出来三个区间满足但是最后还有剩余怎么办？
没关系，我们接着加，最后只要判断cnt==3并且剩余的几个数的和s等于0就可以了。

这个思路非常直接，也不用考虑什么细节，适合新手学习，如果有问题在下方留言，欢迎交流！

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size()<3)  return false;
        int sum=accumulate(A.begin(),A.end(),0);
        if(sum%3)   return false;
        int cnt=0,s=0;
        for(int i=0;i<A.size();i++)
        {
            s+=A[i];
            if(s==sum/3&&cnt<3)    {cnt++;s=0;}
        }    
        if(cnt==3&&!s)  return true;
        return false;
    }
};
```