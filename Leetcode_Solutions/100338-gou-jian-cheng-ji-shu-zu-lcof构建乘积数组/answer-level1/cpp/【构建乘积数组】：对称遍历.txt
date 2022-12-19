#### 解题思路

通过 $B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]$ ，我们发现 $B[i]$ 就是 $A[i]$ 左边所有元素的积 乘 $A[i]$ 右边所有元素的积。

这和[分发糖果](https://leetcode-cn.com/problems/candy/)的操作思想一样，都是利用对称关系，经过两遍对称运算就能得到最终的结果。



#### 对称遍历

- 从左往右遍历累乘，结果保存在数组 $ret$ 中，此时 $ret[i]$ 表示，$A[i]$ 左边所有元素的乘积
- 然后从右往左遍历累乘，获取$A[i]$ 右边所有元素的乘积
- 两边遍历之后得到的 $ret$，就是最终结果

 

#### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ret(n, 1);
        int left = 1;
        for (int i = 0; i < n; i ++) {
            ret[i] = left;
            left = left * a[i];
        } 
        int right = 1;
        for (int i = n-1; i >= 0; i --) {
            ret[i] *= right;
            right *= a[i];
        }
        return ret;
    }
};
```



#### 最后

感谢您的观看！

至此，您已经掌握了使用对称遍历解决此题的方法，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)