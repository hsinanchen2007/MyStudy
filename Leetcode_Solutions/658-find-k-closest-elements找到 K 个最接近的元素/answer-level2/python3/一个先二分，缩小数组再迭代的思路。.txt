### 思路1
* 先把数组缩小，因为找到离 x 最近的k个元素。
* 通过二分查找，找到 min(|nums[m]-x|),m则为距离x最近的元素。(nums[m]-x==0,就可以停止查找）
* 使得原数组[m-(k-1),m+k-1]，k个数必然在这个子数组中。
* 再对这 2k-1个数做计算，得到最终的k个数
```
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        length = len(arr)
        left = 0
        right = length-k
        while left<right:
            mid = (left+right)>>1
            # 让X收缩在区间内          
            if x-arr[mid] >arr[mid+k]-x:
                # x距离左边界远，收缩左边界
                left=mid+1
            else:
                # x距离右边界远，收缩右边界
                right=mid
        
        return arr[left:left+k]
```
