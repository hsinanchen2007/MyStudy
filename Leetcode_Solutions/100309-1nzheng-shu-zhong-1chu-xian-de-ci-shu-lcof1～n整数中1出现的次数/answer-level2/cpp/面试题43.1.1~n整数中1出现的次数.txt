### 解题思路
- 常规做法：对小于n的所有正整数，利用string str=to_string(num)**转换为字符串**，然后count(str.begin(),string.end(),'1')即可**计算出含有1的个数**，这样的时间复杂度是*nlog(10)n*，即对每个数转字符串需要log(10)n时间，即数的位数。
- 优化方案：可以考虑按个位、十位、百位…计算对应位上共出现多少个1，对于数位i，1的个数=n/(10\*i)\*i+min(max(i\*10-i+1,0),i)
- 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
- 内存消耗 :5.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
    int min(int a,int b){
        return a<=b?a:b;
    }
public:
    int countDigitOne(int n) {
        int count=0;
        for(long long i=1;i<=n;i*=10){
            long long add=i*10;
            count+=n/add*i+min(max(n%add-i+1,0LL),i);
        }
        return count;
    }
};
```