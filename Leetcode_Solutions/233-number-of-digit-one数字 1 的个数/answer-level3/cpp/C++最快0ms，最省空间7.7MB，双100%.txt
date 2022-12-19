### 解题思路
这个题目主要运用到了数学知识，任意一个数字n=n1n2n3...nk,可以把n分解为n1x10^(k-1)...nkx10^0,共k个数,对于分解后的任何一个数m，我们可以用公式求出从0到m之间的数字1的个数（详见代码中的num(int,int)函数）,然后把它们加起来。但是仍然不够，举个例子，13可分解为10，3，用这种方法得出的结果是2+1=3，但是结果是6，那么问题出在哪儿？经过分析我们可以发现，0-3之间1的个数不等于11-13之间1的个数因而我们还要对这种特殊情况做处理，我们可以用一个int变量temp记录ni之后的n(i+1)...nk(我的代码是由低位向高位遍历的)，在这个的例子中，temp=3，再加上temp即可得到6.
!(https://pic.leetcode-cn.com/b6d7db78c00c5f569c4cf689caf5cae539e1d179859569d0cbda13089d1bbd56-%E6%8D%95%E8%8E%B7.JPG)(第一写题解，不知道怎么放图)

### 代码

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        if(n<1)
            return 0;
        vector<int> nums;
        for(int i=0;n!=0;i++)
        {
            nums.push_back((n%10));
            n/=10;
        }
        int size=nums.size(),temp=0;
        int result=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==1)
                result+=temp;
            result+=num(nums[i],i);
            temp+=int(nums[i]*pow(10.,i));
        }
        return result;
    }

    int num(int m,int n){
        if(m==0)
            return 0;
        else if(m==1)
            return int(1+n*pow(10.,n-1));
        else
            return int(pow(10.,n)+m*n*pow(10.,n-1));
    }

    
};
```