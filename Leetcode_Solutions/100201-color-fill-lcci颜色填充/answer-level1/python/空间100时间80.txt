
```python3
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        path_list = [(sr, sc)]
        visited = []
        origin_color = image[sr][sc]
        while(path_list!=[] and len(image)!=0 and len(image[0])!=0):
            p = path_list.pop()
            print(p)
            image[p[0]][p[1]] = newColor
            visited.append(p)
            if p[0]-1>=0 and (p[0]-1, p[1]) not in visited and image[p[0]-1][p[1]]==origin_color:
                path_list.append((p[0]-1, p[1]))
            if p[0]+1<len(image) and (p[0]+1, p[1]) not in visited and image[p[0]+1][p[1]]==origin_color:
                path_list.append((p[0]+1, p[1]))
            if p[1]-1>=0 and (p[0], p[1]-1) not in visited and image[p[0]][p[1]-1]==origin_color:
                path_list.append((p[0], p[1]-1))
            if p[1]+1<len(image[0]) and (p[0], p[1]+1) not in visited and image[p[0]][p[1]+1]==origin_color:
                path_list.append((p[0], p[1]+1))
        return image
```