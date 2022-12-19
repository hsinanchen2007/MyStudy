```python
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
```c++
class Solution {
public:
int l1,l2,me;
stack<vector<int>> stacky;
 void change(vector<vector<int>>& image, int sr, int sc, int newColor){
     vector<int> l={sr-1,sr+1,sr,sr},r={sc,sc,sc-1,sc+1};
     for (int t=0;t<4;t++){
         int p1=l[t],p2=r[t];
         if (p1>=0 && p1<l1 && p2>=0 && p2<l2 && image[p1][p2]==me && image[p1][p2]!=newColor){
             image[p1][p2]=newColor;
             vector<int> temp={p1,p2};
             stacky.push(temp);
         }
     }
 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        l1=image.size(),l2=image[0].size();
        me=image[sr][sc];
        image[sr][sc]=newColor;
        change(image,sr,sc,newColor);
        while (!stacky.empty()){
            vector<int> p=stacky.top();
            stacky.pop();
            change(image,p[0],p[1],newColor);
        }
        return image;
    }
};
```

