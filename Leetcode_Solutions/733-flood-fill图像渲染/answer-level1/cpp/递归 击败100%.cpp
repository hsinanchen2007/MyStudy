### 解题思路
利用vector<vector<int>> 建一个队列list，将符合条件的点的坐标值加进去，首先将初始坐标加进去
利用递归将list里的上下左右四个方向符合条件的点都加进去，在加的同时把访问过的点修改值并删除，直到list没有元素

![A\[AN4~SY\[V6VWGF3\]AB4PPI.png](https://pic.leetcode-cn.com/5ec49327b2415bd78bdf58f0dbc33d98860a89c2f259e9a71b6e58ffbf85a57c-A%5BAN4~SY%5BV6VWGF3%5DAB4PPI.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int temp=image[sr][sc];
        if(newColor==temp)
            return image;
        vector<vector<int>> list;
        vector<int> v;
        v.push_back(sr);
        v.push_back(sc);
        list.push_back(v);
        updateNum(image,newColor,list,temp);
        return image;
    }
    void updateNum(vector<vector<int>>& image,int newColor,vector<vector<int>> &list,int temp)
    {
        if(list.size()==0)
            return;
        int i=list.front()[0],j=list.front()[1];  //i是image的坐标，j是image[i]的坐标
        list.erase(list.begin()+0,list.begin()+1);
        image[i][j]=newColor;
        cout<<image.size()<<" "<<image[0].size()<<endl;;
        if(i-1>-1&&image[i-1][j]==temp)
        {
            vector<int> v;
            v.push_back(i-1);
            v.push_back(j);
            list.push_back(v);
        }
        if(i+1<image.size()&&image[i+1][j]==temp)
        {
            vector<int> v;
            v.push_back(i+1);
            v.push_back(j);
            list.push_back(v);
        }
        if(j-1>-1&&image[i][j-1]==temp)
        {
            vector<int> v;
            v.push_back(i);
            v.push_back(j-1);
            list.push_back(v);
        }
        if(j+1<image[0].size()&&image[i][j+1]==temp)
        {
            vector<int> v;
            v.push_back(i);
            v.push_back(j+1);
            list.push_back(v);
        }
        updateNum(image,newColor,list,temp);
    }
};
```