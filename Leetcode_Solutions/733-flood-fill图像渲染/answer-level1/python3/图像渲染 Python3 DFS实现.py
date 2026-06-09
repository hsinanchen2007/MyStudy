这道题我个人感觉跟岛屿数量那个题很像，代码主要还是用`DFS`的方法。我是将需要改变的点先用字符串占位，避免出现重复遍历的情况，最后再将字符串统一替换。提供个思路，可能有点笨，嘻嘻。

```
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        def dfs(image, sr, sc, cnt):
            if 0 <= sr < len(image) and 0 <= sc < len(image[sr]) and cnt == image[sr][sc]:
                image[sr][sc] = 'newColor'
                dfs(image, sr-1, sc, cnt)
                dfs(image, sr+1, sc, cnt)
                dfs(image, sr, sc-1, cnt)
                dfs(image, sr, sc+1, cnt)
        cnt = image[sr][sc]
        dfs(image, sr, sc, cnt)
        for i in range(len(image)):
            for j in range(len(image[i])):
                if image[i][j] == 'newColor':
                    image[i][j] = newColor
        return image
```

