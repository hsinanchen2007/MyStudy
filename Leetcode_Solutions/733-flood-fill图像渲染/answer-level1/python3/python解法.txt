### 解题思路
注意判断原颜色和现有颜色相同的时候可以直接返回，不然会一直递归从而报错

### 代码

```python3
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if not image or image[sr][sc] == newColor:
            return image
        row = len(image)
        col = len(image[0])        
        moveset = {(0,1),(1,0),(-1,0),(0,-1)}
        print("--",row, col)
        def search(image, i, j, newColor, oldColor):
            if i<0 or j<0 or i>=row or j>=col or image[i][j]!=oldColor:
                return
            print(i, j)
            image[i][j] = newColor
            for cood in moveset:
                search(image, i+cood[0], j+cood[1], newColor, oldColor)
            return 

        oldColor = image[sr][sc]
        search(image, sr, sc, newColor, oldColor)
        return image
```