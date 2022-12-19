
```python []
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if (oldColor := image[sr][sc]) == newColor:
            return image
        m, n = len(image), len(image[0])
        d = ((1, 0), (0, 1), (-1, 0), (0, -1))
        q = [(sr, sc)]
        while q:
            for i, j in q:
                image[i][j] = newColor
            q = [
                (x, y)
                for i, j in q
                for di, dj in d
                if 0 <= (x := i + di) < m and 0 <= (y := j + dj) < n and image[x][y] == oldColor
            ]
        return image
```