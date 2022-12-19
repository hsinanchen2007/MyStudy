# 最朴素的方法，O(n^3) 暴力枚举：
首先枚举起点，对于每个起点枚举所有终点，然后计算区间内的和能否被 K 整除。

## 通过前缀和优化，降到 O(n^2)：
首先预处理前缀和。为便于理解，假设下标从 1 开始。
prefix(i) 表示 nums[1, i] 的累加和。特别的，prefix(0) 表示一个空的前缀。
那么，显然有:
* prefix(0) = 0;
* prefix(i) = prefix(i-1) + nums[i];

则对于任意的起点 i 和终点 j，其区间和为 prefix(j) - prefix(i-1)。
故可以优化掉方法一的一层遍历，时间复杂度降到 O(n^2)。

## 利用同余定理优化，降到 O(n):
**同余定理：如果两个整数 a, b 满足 (a-b)%K == 0，那么有 a%K == b%K。**
由此可知,如果 i，j 满足 (prefix(j) - prefix(i-1))%K == 0，那么有 prefix(i)%K == prefix(i-1)%K。
故，可以扫描一遍前缀和 prefix，利用 unordered_map 统计所有余数出现的次数，然后遍历 unordered_map 利用组合公式C(n,m) = n!/((n-m)!*m!) 来计算答案。
此时时间复杂度降到了 O(n)。

**代码如下**

```
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for(int i = 0, n = A.size(), sum = 0; i < n; i++) {
            sum = ((sum + A[i])%K + K)%K;
            ++ cnt[sum];
        }
        int anw = 0;
        for(auto p : cnt) {
            anw += p.second*(p.second-1)/2;
        }
        return anw;
    }
};
```

## 整理了两个重要同余式，供小伙伴们品尝~ 🐳
### 威尔逊定理
$(p−1)!≡p−1≡−1(mod p)$ p 是一个素数。

### 费马小定理
假如p是质数，且a 与 p 互质，即 $gcd(a,p)=1$，那么$a(p−1)≡1(mod p)$。

### 欧拉函数
对于正整数n，欧拉函数是小于或等于n的正整数中与n互质的数的数目。比如：
与 1 互质且小于等于 1 的正整数只有 1 本身，故 φ(1)=1。
与 8 互质且小于等于 8 的正整数有 1，3，5，7，故 φ(8)= 4。

### 欧拉定理
欧拉定理：若n,a为正整数，且n,a互质，则: a^φ(n)≡1(mod n)。

**对证明过程有兴趣的小伙伴，可以关注👏HelloNebula👏，回复 "初等数论" 获得大神教程！🐳**

****
****

# 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
* **分享周赛题解**
* **分享计算机专业课知识**
* **分享C++相关岗位面试题**
* **分享专业书籍PDF**

## 著名油画《欧拉的微笑》镇楼！

![image.png](https://pic.leetcode-cn.com/d8be6db750855bdca454b32da12834b28c3080d4b5360ee445497423aeeb9e5a-image.png)
