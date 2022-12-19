```c++
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        stack=[];
        l1,l2=len(image),len(image[0]);
        me=image[sr][sc];
        image[sr][sc]=newColor
        def change(image,stack,r,c):
            for rx,cy in [(r-1,c),(r+1,c),(r,c-1),(r,c+1)]:
                if 0<=rx<l1 and 0<=cy<l2 and image[rx][cy]==me and image[rx][cy]!=newColor:
                    image[rx][cy]=newColor;
                    stack+=[(rx,cy)];
        change(image,stack,sr,sc);
        while stack:
            sr,sc=stack.pop();
            change(image,stack,sr,sc);
        return image
```
