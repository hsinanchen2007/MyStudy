### 解题思路
733. 图像渲染
题目一毛一样
### 代码

```python3
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        length=len(image[0])
        width=len(image)
        def my_flood(sr,sc):
            old_color=image[sr][sc]
            if old_color==newColor:
                return image
            image[sr][sc]=newColor
            if sr>0 and image[sr-1][sc]==old_color:
                my_flood(sr-1,sc)
            if sc>0 and image[sr][sc-1]==old_color:
                my_flood(sr,sc-1)
            if sr<width-1 and image[sr+1][sc]==old_color:
                my_flood(sr+1,sc)
            if sc<length-1 and image[sr][sc+1]==old_color:
                my_flood(sr,sc+1)
            return image
        return my_flood(sr,sc)
```