```python
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if image[sr][sc] != newColor:
            old, image[sr][sc], m, n = image[sr][sc], newColor, len(image), len(image[0])
            for i, j in zip((sr, sr+1, sr, sr-1), (sc+1, sc, sc-1, sc)):
                if 0 <= i < m and 0 <= j < n and image[i][j] == old:
                    self.floodFill(image, i, j, newColor)
        return image
```