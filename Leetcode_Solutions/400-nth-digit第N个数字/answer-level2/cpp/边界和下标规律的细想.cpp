### 解题思路
这种题其实思路完全没有什么好讲的，但是在实现中，就是很费劲，因此在这里将思路进行一些强化。

1.首先找大区间，也就是n处于10的i次方与i-1次方之间。这里用了前缀和，preSum[i]表示10的i次方之前所有数字个数之和，这里边界条件是不包括10的i次方这个数的，这里要想清楚。

2.找到大体区间之后，要计算当前n所需要的数字在哪个位置。这最开始没想明白，后来发现是一个行列桶的模型，即x/n是行号，x%n是列号，在这里就是差值（n-start）/i是所在数字（当然还要加上基准的pow(10,current-1），那么（n-start）%i就是当前所在数字中数字位置，都是从0开始的。

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        vector<long> preSum(12,0);
        int current;
        //找大体区间
        for(int i=1;i<=11;i++){
            preSum[i]=preSum[i-1]+(pow(10,i)-pow(10,i-1))*i;
            current=i;
            if(n<=preSum[i]&&n>preSum[i-1]) break;
        }
        //这里的start+1是为了满足后边桶思想的从0开始的下标
        int start=preSum[current-1]+1;
        //数字中区间
        int finalNum=pow(10,current-1)+(n-start)/(current);
        //数字内位置
        int pos=(n-start)%(current);
        string ans=to_string(finalNum);
        return ans[pos]-'0';
    }
};
```