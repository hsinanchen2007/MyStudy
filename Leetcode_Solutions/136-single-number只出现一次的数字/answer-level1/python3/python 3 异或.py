### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums):
        x = 0
        for i in nums:
            x^=i 
            #  nums= [4,1,2,1,2]
            # x^i 运算：((((0^4)^1)^2)^1)^2
        return x

```
1. 1.最简单的方式是 通过2* sum(set(nums)) - sum(nums)的方法；
2.  这个方法增加了一个一个变量set(nums), 时间复杂度应该是
3.  2*O(n)
4. 2. 通过异或的方式 
5.  增加一个变量x;
6. 时间复杂读是： O(n)
7. 
![屏幕快照 2019-12-29 12.27.03.png](https://pic.leetcode-cn.com/22fd2824192b0795e2e366c90f13a1f7a7605f2ab627e7fcb845998723bba970-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-29%2012.27.03.png)

4. 