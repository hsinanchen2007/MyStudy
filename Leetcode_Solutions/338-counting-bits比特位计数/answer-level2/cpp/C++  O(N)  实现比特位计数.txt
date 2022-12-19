### 解题思路
这道题目解出来很简单，只需要遍历每个数字，然后求出数字中1的个数就行了。比较难的是题目中要求的O(N)时间复杂度解出来。
这道题目想要实现O(N),就只能使用动态规划了，因为我们需要遍历每个元素，每个元素的结果需要在O(1)中解出来，只能借助dp数组，找到当前元素和之前已经求出的元素关系。

本题注重找规律，在访问到元素n时，怎么通过已知的dp[0...n-1]，直接得出dp[n]?我们通过观察二进制发现了一个规律：

(1)如果n为奇数，那么n的二进制中1的个数一定只比n-1(偶数)多一个,即dp[i]=dp[i-1]+1
(2)如果n为偶数，那么n的二进制个数和n/2(也是偶数)一样多,即dp[i]=dp[i/2];

发现这个规律，代码就很好写了。
![image.png](https://pic.leetcode-cn.com/7e99c471a653195811d512efd3e0143e261324951032cd07ddac2ed9b39406f0-image.png)



### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        /*基本算法很简单*/
        /*
        vector<int> res;
        for(int i=0;i<=num;i++){
            int count=0;
            int j=i;
            while(j !=0){
                if(j & 0x1)
                    count++;
                j>>=1; //j每次右移1位
            }
            res.push_back(count);
        }
        return res;
        */
        /*尝试O(N)算法*/
        /*i是奇数 dp[i]=dp[i-1],i是偶数dp[i]=[i/2]*/
        if(num==0)
            return vector<int>(1,0);
        vector<int> dp(num+1);
        /*初始化*/
        dp[0]=0;
        for(int i=1;i<=num;i++){
            if(i%2==0)
                dp[i]=dp[i/2];
            else
                dp[i]=dp[i-1]+1;
        }
        return dp;
    }
};
```