### 解题思路
python

### 代码

```python
class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        def dfs(image,r,c,color,newcolor):
            if image[r][c]==color:
                image[r][c]=newcolor
                if r>=1 :dfs(image,r-1,c,color,newcolor)
                if c>=1:dfs(image,r,c-1,color,newcolor)
                if r<len(image)-1:dfs(image,r+1,c,color,newcolor)
                if c<len(image[0])-1:dfs(image,r,c+1,color,newcolor)
        if image[sr][sc]!=newColor:
            dfs(image,sr,sc,image[sr][sc],newColor)
        return image
```