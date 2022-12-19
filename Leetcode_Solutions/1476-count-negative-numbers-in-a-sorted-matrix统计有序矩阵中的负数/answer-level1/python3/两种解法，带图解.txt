### 解题思路
第一种：全部遍历，没什么技巧。
第二种：从右上到左下下梯子。
![WeChat Image_20200308103704.jpg](https://pic.leetcode-cn.com/c36a985d3721dd31f157fdeef8a3cf38a40481e5e6bd71ff216ce938ad6600bf-WeChat%20Image_20200308103704.jpg)

### 代码
第一种：
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        total = 0
        for item in grid:
            for num in item:
                if num < 0 :
                    total += 1
        
        return total
            
```

第二种：
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        total = 0
        i, j = 0, len(grid[0])-1

        while i < len(grid) and j>=0:
            if grid[i][j] >= 0:
                i += 1
            else:
                total += len(grid) - i
                j -= 1
        return total
```
