给定一个整数 n，返回 n! 结果**尾数中零的数量**。

示例 1:

```
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
```

示例 2:

```
输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
```
说明: 你算法的时间复杂度应为 O(log n) 。

<hr>

##  解法1：
判断乘数中是否有2,5因子，没有则跳过，有则乘上sum中。再判断sum尾数是否有0
```
class Solution {
public:
    int trailingZeroes(int n) {
        long sum=1;
        int count=0;
        string s=to_string(n);
        int temp;
        for(int i=n;i>0;i--)
        {
            if(i%2!=0 && i%5!=0)
                continue;
            else temp=i%int(pow(10,s.size()));
            sum*=temp;
            while(sum%10==0)
            {
                count++;
                sum/=10;
            }
            s=to_string(n);
            sum%=int(pow(10,s.size()));
        }
        return count;
    }
};
```

此方法到大数据时计算速度慢，还是不够好。

##  解法2：
思路：
 * n! = x * (10)^k^ = x * (2 ^k^ \* 5^k^)
  * k即为末尾0的个数
   * 其中x可能是2的倍数, 所以2的个数一定比5多
   * 而n!为递减相乘, 只需要统计n中5的个数
  
  

### 解：

```
class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n>=5)
        {
            count+=n/5;
            n/=5;
        }
        return count;
    }
};
```

  ###   递归解法：
  

```
class Solution {
public:
    int trailingZeroes(int n) {
        return n>=5?n/5+trailingZeroes(n/5):0;
    }
};
```

