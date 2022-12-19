这道题可以暴力解决。。

想要快一些的话，既然已经排序，使用二分搜索即可，时间复杂度可以做到 O(mlogn) （假设 m<n）（不知时间复杂度分析的对不对，希望各位大佬指正）
在第一行二分查找 0 的位置，logn，假设为i
在第二行的 (0, i) 范围内查找 0 的位置， logi
依次类推直到行的第一个数字为 0 或者全部行遍历结束，时间复杂度最坏情况下 O(mlogn)

bisect 没找到可以用于降序的方法，虽然不情愿（简称，懒），但还是手动写一个吧

``` python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        def bfind(ll, l, r, k):   # 二分查找的函数
            while l < r:
                c = (l+r)//2
                if ll[c]<k:
                    r = c
                else:
                    l = c+1
            return l
        i = len(grid[0])  # 每次查找的末尾位置
        for ll in grid:
            i = bfind(ll,0,i,0)   # 在每行中查找0的位置，查找范围为0到上一行的0的位置
            ans += len(ll) - i   # 对负数个数累加
        return ans
```


python3 一行版（这版和上面的居然运行时间都一样，数据弱吧）
``` python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum([x<0 for y in grid for x in y])
```

C嘎嘎版
``` C++
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto k:grid) for(auto i:k) if(i<0)
            ans++;
        return ans;
    }
};
```
