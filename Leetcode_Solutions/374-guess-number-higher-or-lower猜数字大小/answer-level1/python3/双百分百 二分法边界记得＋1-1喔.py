![捕获.PNG](https://pic.leetcode-cn.com/2e75831e5b9394f2400e7d80e105b6e7343975df8d39928a1fb8c29f1be8b092-%E6%8D%95%E8%8E%B7.PNG)
题目意思有点坑，不小心就理解错了是它的小了，还是你小了。
def guessNumber(self, n: int) -> int:
        left=1
        right=n`定下左右边界`
        while 1:
          
            mid=(left+right)//2`取中位数`
            if guess(mid)==-1:right=mid-1`小了，缩小右边`
            elif guess(mid)==1:left=mid+1`大了，缩小左边`
            else:return mid



