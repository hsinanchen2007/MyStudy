### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=0,tmparea=0;
        int l=0,r=n-1;  /*从中间向两端收缩，先从容器最长的底开始*/
        if(n==2) return height[0]<height[1]? height[0]:height[1];
        while(l<r){
            int lower=(height[l]<height[r])? height[l]:height[r];
            tmparea=lower*(r-l);
            if(tmparea>maxarea) maxarea=tmparea;
            if(height[l]<height[r]) ++l;    /*判断哪边高，较矮的边再向前继续搜索*/
            else --r;
            }
        return maxarea;
        }
};
```