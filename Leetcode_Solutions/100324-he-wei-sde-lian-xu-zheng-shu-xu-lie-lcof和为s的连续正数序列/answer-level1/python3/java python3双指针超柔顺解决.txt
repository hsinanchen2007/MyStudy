# 解题思路
借助双指针，初始l = 1和r = 2。连续数组的和就是等差数列的求和，即sum =(l+r)*(r-l+1)/2，判断sum与target的大小，
当l<r，进行循环：
1. 当sum>target的时候，将l加1.
2. 当sum<target的时候，将r加1.
3. 当两者相等时，将这个数组依次加入，同时将l与r加1，进行下个循环，直至l>r.

**需要注意在Java中要转换数组，借助列表的toArray(),即可。详见下面代码**

```
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int l = 1;
        int r = 2;
        while(l < r) {
            int sum = (l + r)*(r - l + 1)/2;
            if(sum < target) {
                r++;
            }
            else if(sum > target) {
                l++;
            }
            else {
                int[] a = new int[r - l + 1];
                for(int i = l; i < r + 1; i++) {
                    a[i - l] = i;
                }
                res.add(a);
                l++;
                r++;
            }
        }
        return res.toArray(new int[0][]);
    }
}
```
# python3
```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        l = 1
        r = 2
        res = []
        while l < r:
            a = []
            sum = (l + r)*(r - l + 1)/2
            if sum > target:
                l += 1
            elif sum < target:
                r += 1
            else:
                for i in range(l, r + 1):
                    a.append(i)
                res.append(a)
                l += 1
                r += 1
        return res
```
