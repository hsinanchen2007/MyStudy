```python3
class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        if a == 0:
            if b >= 0:
                return [b*i + c for i in nums]
            else:
                return [b*i + c for i in nums][::-1]
        ## 针对二次函数，我们讨论两种情况，a>0是最小值在两边，a<0是最小值在中间，分两个列表计算合并。
        gradient_zero_point = -b/(2*a)
        index = self.find(nums, gradient_zero_point)
        if a > 0:
            l1 = nums[:index][::-1]
            l2 = nums[index:]
        else:
            l1 = nums[:index]
            l2 = nums[index:][::-1]
        res = []
        while l1 and l2:
            if a*l1[0]**2 + b*l1[0] + c < a*l2[0]**2 + b*l2[0] + c:
                res.append(a*l1[0]**2 + b*l1[0] + c)
                l1.pop(0)
            else:
                res.append(a*l2[0]**2 + b*l2[0] + c)
                l2.pop(0)
        tmp = l1 or l2
        for x in tmp:
            res.append(a*x**2 + b*x + c)
        return res

    # O(logn) time complexity
    def find(self, nums, point):
        l, r = 0, len(nums)-1 
        while l <= r:
            mid = (l+r)//2
            if nums[mid] > point:
                r = mid - 1
            elif nums[mid] < point:
                l = mid + 1
            else:
                return mid 
        return l 