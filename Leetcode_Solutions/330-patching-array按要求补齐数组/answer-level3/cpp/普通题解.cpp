### 解题思路
因为这道题好几次都想放弃了，但是最后还是坚持下来了，所以写个题解。
我添加数的原则只有一个，当我目前可以组合出1-k的所有数，而数组中的下一个数t大于k+1，这样起码k+1这个数我们就表示不出来了
就要加数了，加多少就是关键，应该加k+1（不管加不加其它的数，k+1必加，不然k+1就表示不出了）
加上k+1之后我们就可以表示出1-k+k+1之间的所有数了，k=k+k+1
当k>=t-1就可以看下个数了，同时我们可以表示的数的范围变为1-k+t,k=k+t。



### 代码

```cpp
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m=nums.size();
        int res=0;
        int st=1;
        if(m==0||nums[0]!=1){
            res++;
            st=0;
        }
       long long now=1;//目前可以表示1-now范围的所有数
        for(int i=st;i<m;i++)
        {
            if(nums[i]>n)break;
            while(now<nums[i]-1)
            {
                long long val = now+1;
                now += val;
                res++;
            }
            now+=nums[i];
        }
        cout<<now<<" "<<res<<endl;
        long long end=now;
        while(end<n)
        {
            long long val = end+1;
            end +=val;
            res++;
        }
        return res;

    }
};
```