使用递归，同时为了避免无限递归，当需要渲染的颜色与原颜色一致时直接返回原值。
```
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        t = image[sr][sc]
        if t==newColor:
            return image
        image[sr][sc]=newColor
        if sr-1>=0 and image[sr-1][sc]==t:
            self.floodFill(image,sr-1,sc,newColor)
        if sr+1<len(image) and image[sr+1][sc]==t:
            self.floodFill(image,sr+1,sc,newColor)
        if sc-1>=0 and image[sr][sc-1]==t:
            self.floodFill(image,sr,sc-1,newColor)
        if sc+1<len(image[0]) and image[sr][sc+1]==t:
            self.floodFill(image,sr,sc+1,newColor)
        return image
```
