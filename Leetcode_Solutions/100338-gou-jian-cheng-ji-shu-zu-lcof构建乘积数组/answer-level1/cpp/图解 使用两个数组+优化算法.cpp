// ### 方法一：左右数组
// 使用两个数组 $L$ 和 $R$，$L[i]$ 表示 $a[i]$ 左边的乘积，而 $R[i]$ 表示 $a[i]$ 右边的乘积，那么 $L$ 和 $R$ 对应位置的乘积就是所求结果。
// 具体来说，我们可以使用三趟遍历完成：
// 1. 👉 正向遍历，$L[i]=L[i-1]\times a[i-1]$；
// 2. 👈 反向遍历，$R[j]=R[j+1]\times a[j+1]$；
// 3. 👉 正向遍历，$result[i]=L[i]=L[i]\times R[i]$；

// 注：当 $i=0$ 时，$result[0]=L[0]=1\times R[0]$。即 $L[0]=1$，同理 $R[n-1]=1$。

// <![幻灯片1.JPG](https://pic.leetcode-cn.com/9df3900b24f606686c7593ccc792af296cbb92cf73f94ff627a1d68f0ac11463-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/1aabb0c9017cd15ca79ca845bf9145fb511a941d308c21203c4a060ec2612efe-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/40e16b384e4a68a3fecd874aa8a0c3c5f604e368b390aae90442e18db7db4bec-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/745092563858b1dde8cb681a145190eed58e2b4385b30adeae3c0b3f4595578d-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/361a10b7cf1e854a4168da14c72f44a51d0a1bbaa0c6b6de421d829be28b423d-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/ae0d690d72f9c085d9000c9915b4d1336da4e35f546651b046aa5ce1a94f53e3-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/9608f526de95a643eb51220555b7ced730025c62429a8e7c562106293ce29221-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/e9d974b715b4f26f50ccad9f687acfa020fae4791ae7dacf165fc448100b3b7d-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/8bf8db614c487ba8fd81dcff4b88e672a9260d68c60bbd96caaccbd29db28157-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/9cbd9b6091ddb9a899afc9e1eeea755eda8d8191837f2d7a4a4dad3b3b80b722-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/6703a909993f55184d871556db3aaf4059b0148155d2a6de08adc17eca5d5a29-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/1b3eb9f4081618d78aa8e4f7ea48ed6d68d3d8c9d82a5bb718c01d190d5ff056-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/0268b46c8435ed1e80475bb95bf9a27acb121be9bba424c777f4c22d30603254-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/57e2d05d7a147908ace0c5dc1933af5ff11368e2f5ce1b9dc2d4380f3a08539c-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG),![幻灯片15.JPG](https://pic.leetcode-cn.com/51056fe35fd846021a32338f61da02423929294d97980e2551da5ddcbc496403-%E5%B9%BB%E7%81%AF%E7%89%8715.JPG),![幻灯片16.JPG](https://pic.leetcode-cn.com/e60b9178491d9ce5206237ce9a1fbcd56f0da42e58a47277408dbf52cd70a62a-%E5%B9%BB%E7%81%AF%E7%89%8716.JPG)>

// #### 代码

// ```python []
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        n = len(a)
        L, R = [1] * n, [1] * n
        for i in range(1, n):
            L[i] = L[i - 1] * a[i - 1]
        for j in reversed(range(n - 1)):
            R[j] = R[j + 1] * a[j + 1]
        for i in range(n):
            L[i] = L[i] * R[i]
        return L
// ```
// ```C++ []
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> L (n, 1);
        vector<int> R (n, 1);
        for(int i = 1; i < n; i++)
            L[i] = L[i - 1] * a[i - 1];
        for(int j = n - 2; j > -1; j--)
            R[j] = R[j + 1] * a[j + 1];
        for(int i = 0; i < n; i++)
            L[i] = L[i] * R[i];
        return L;
    }
};
// ```
// #### 复杂度分析
// - 时间复杂度：$O(3N)～O(N)$，遍历了三次数组。
// - 空间复杂度：$O(2N)～O(N)$，使用了两个数组。
// ### 方法二：左（或右）数组
// 思路与方法一类似，不同的是不需要 $R$ 数组，只需在第二步 👈 反向遍历 过程中直接计算出结果即可。
// #### 代码

// ```python []
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        if not a: return []
        n = len(a)
        res = [0] * n
        res[0] = 1
        for i in range(1, n):
            res[i] = res[i - 1] * a[i - 1] # a[i] 左边的乘积现在保存在了res
        R = 1
        for i in reversed(range(n)):
            res[i] = res[i] * R
            R *= a[i]
        return res
// ```
// #### 复杂度分析
// - 时间复杂度：$O(2N)～O(N)$，遍历了两次数组。
// - 空间复杂度：$O(N)$，使用了一个数组。

// 欢迎分享c++ 代码
// 如有问题，欢迎讨论~