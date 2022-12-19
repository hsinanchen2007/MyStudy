### 解题思路
所有数的异或和xor中，从右向左搜索第一个1出现的位置mask，重新遍历 ，数组被分成num & mark == 0 , num & mark ！= 0 两类，再异或一遍，得到结果
![截屏2020-03-05下午9.28.50.png](https://pic.leetcode-cn.com/ec834ec5d38ef00a459122aafb4317bb5aae381fcd33eee0e139c8efc1f92972-%E6%88%AA%E5%B1%8F2020-03-05%E4%B8%8B%E5%8D%889.28.50.png)


### 代码

```python []
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        xor = 0
        for i in nums:
            xor ^= i
        nums1, nums2 = 0, 0
        mask = 1 
        while xor & mask == 0:
            mask <<= 1
        for num in nums:
            if num & mask == 0:
                nums1 ^= num 
            else:
                nums2 ^= num 
        return [nums1, nums2]
```
## 调试复现代码执行过程
![截屏2020-03-07上午10.09.38.png](https://pic.leetcode-cn.com/4ae77b4583b17730dfcf58207c3ab49ec4b61f2ec5aca85dc56fe82a1616e595-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8810.09.38.png)
## 调试代码
``` python []
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        xor = 0
        for i in nums:
            xor ^= i
        nums1, nums2 = 0, 0
        mask = 1 
        while xor & mask == 0: #从右向左搜索第一个1出现的位置mask
            print(f"mask is {bin(mask)}")
            mask <<= 1   # 0b100 
        print(f"mask is {bin(mask)}")
        for num in nums:
            s = f"{bin(num)} & {bin(mask)} == {bin(num & mask)} -----{num & mask} "
            print(s)
            if num & mask == 0: #等于0
                nums1 ^= num 
            else:               #非0
                nums2 ^= num 
        return [nums1, nums2]
```
## 调试结果
![截屏2020-03-07上午10.09.55.png](https://pic.leetcode-cn.com/8479c7e979d76c9cd6b4e3c8d85e06b095b0ba3857672ce95e3ab404265d37f1-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8810.09.55.png)


