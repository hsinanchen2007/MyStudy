![截屏2019-12-04上午9.06.03.png](https://pic.leetcode-cn.com/1f7d7df2afe5c1ac04c0ca9c559d70695d11d15cc2d1f508a9243799c7880245-%E6%88%AA%E5%B1%8F2019-12-04%E4%B8%8A%E5%8D%889.06.03.png)

class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        return A.index(max(A))