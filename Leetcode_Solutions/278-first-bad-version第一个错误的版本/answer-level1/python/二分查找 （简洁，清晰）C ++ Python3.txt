# 二分查找
## 模板一： if 答案在右边: l = m    else r = m -1

![](https://pic.leetcode-cn.com/34dcfddd456b8322e9ae45843a826941eb6aaed9345cb32dc2e8f50e8ce4b947.png)

```
Template 1 code 

int binary_search1(int l, int r) {
    while ( l < r )
    {
        int m = l + (long long)r >> 1
        if (f(m)) //答案在右边
            l = m 
        else
            r = m -1
    }
    return l;    // or return r     
}


```

## 模板二： if 答案在左边: r = m     else l = m + 1
![](https://pic.leetcode-cn.com/83e50ac2fda428bb7430ae27984a9fd0dcb762e86fee2acde3df2f1b40af6168.png)

```
Template 2 code 

int binary_search2(int l, int r) {
    while ( l < r )
    {
        int m = l + (long long)r >> 1
        if (f(m)) //答案在左边
            r = m 
        else
            l = m + 1
    } 
    return l;    // or return r 
}
```
### 解题思路

不难看出，这道题可以用经典的二分查找算法求解。我们通过一个例子，来说明二分查找如何在每次操作中减少一半的搜索空间，以此减少时间复杂度。

![](https://pic.leetcode-cn.com/a132814d4bb34312180bff5da701460584f297f39cf6ddc085de9046627c6901.png)
场景一中，isBadVersion(mid) 返回 false，因此我们知道 mid 左侧（包括自身）的所有版本都是正确的。所以我们令 left=mid+1，把下一次的搜索空间变为 [mid+1,right]。


![](https://pic.leetcode-cn.com/1dddd6afd347d19a01d2ea10628ffedd7be153283f7b73264e7f487c02ee247b.png)

场景二中，isBadVersion(mid) 返回 true，因此我们知道 mid 右侧（不包括自身）的所有版本的不可能是第一个错误的版本。所以我们令 right=mid，把下一次的搜索空间变为 [left,mid]。

在二分查找的每次操作中，我们都用 left 和 right 表示搜索空间的左右边界，因此在初始化时，需要将 left 的值设置为 1，并将 right 的值设置为 n。当某一次操作后，left 和 right 的值相等，此时它们就表示了第一个错误版本的位置。可以用数学归纳法 证明 二分查找算法的正确性。
![](https://pic.leetcode-cn.com/6f89250782301083460b518e12dfa5a4e46c07459a63c1b8113166184615db9e.png)

复杂度分析
时间复杂度：O(logn)。搜索空间每次减少一半，因此时间复杂度为 O(logn)。
空间复杂度：O(1)。

![截屏2020-03-16上午6.24.50.png](https://pic.leetcode-cn.com/c032f9981016e6020fbd399988b4d039a41f88adf94851f3b550571e2538860e-%E6%88%AA%E5%B1%8F2020-03-16%E4%B8%8A%E5%8D%886.24.50.png)


### 代码

```cpp []
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //模板二
        int l = 1, r = n;
        while (l < r) {
            int m = l + (long long) r >> 1; // 右移等价于  /2
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
        
    }
};


```
```python []
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 0, n
        while l < r:
            m = (l + r) >> 1 # 右移==  //2
            if isBadVersion(m):
                r = m
            else:
                l = m + 1
        return l  # l == r
```

