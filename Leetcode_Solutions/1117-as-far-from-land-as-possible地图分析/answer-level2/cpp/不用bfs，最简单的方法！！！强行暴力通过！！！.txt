### 解题思路
![image.png](https://pic.leetcode-cn.com/eb0b6f7e46a7521aa2fe3c010a19a05eb0b5dda28b5cfe04d2dad5014144c6b7-image.png)
两步剪枝1、当前海洋到陆地的最小距离小于max1就直接break
       2、陆地从后往前找，处于矩阵右下方的海洋会更快的找到最小值而break！！！



### 代码

```cpp
class Solution {
public:
    int max1=INT_MIN;
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        vector<pair<int,int>> vc1;
        vector<pair<int,int>> vc0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==0)
                    vc0.push_back(make_pair(i,j));
                else
                    vc1.push_back(make_pair(i,j));
            }
        }
        if(vc0.size()==0||vc1.size()==0)
            return -1;
        int max1=INT_MIN;
        for(int i=0;i<vc0.size();++i)
        {
            int count=INT_MAX;pair<int,int> tp=vc0[i];
            for(int j=vc1.size()-1;j>=0;--j)
            {
                pair<int,int> tp1=vc1[j];
                int now=abs(tp1.first-tp.first)+abs(tp1.second-tp.second);
                if(now<count)
                    count=now;
                if(count<max1)
                    break;
            }
            if(count>max1)
                max1=count;
        }
        return max1;
        // for(int i=0;i<m;++i)
        // {
        //     for(int j=0;j<m;++j)
        //         // if(grid[i][j]==0)
        //         // {
        //         //     int flag=0;int temp=INT_MAX;
        //         //     for(int k=0;k<m;++k)
        //         //     {
        //         //         for(int l=0;l<m;++l)
        //         //         {
        //         //             if(grid[k][l]==1)
        //         //             {
        //         //                 flag=2;
        //         //                 int now=abs(i-k)+abs(j-l);
        //         //                 temp=min(temp,now);
        //         //                 if(temp<max1)
        //         //                 {
        //         //                     flag=1;break;
        //         //                 }
        //         //             }
        //         //         }
        //         //         if(flag==1)
        //         //             break;
        //         //     }
        //         //     if(flag==2)
        //         //         max1=temp;
        //         // }
        // }
        // if(max1==INT_MIN)
        //     return -1;
        // return max1;
    }
};
```