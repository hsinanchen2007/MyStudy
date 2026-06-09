### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int nSize=height.size();
        if(nSize<=0)
        {
            return 0;
        }
        int nLeft=0;
        int nRight=nSize-1;
        int nSum=0;
        //当左右靠一起的时候，空间为0
        while(nLeft<nRight)
        {
            if(height[nLeft]<=0)
            {
                ++nLeft;
                continue;
            }
            if(height[nRight]<=0)
            {
                --nRight;
                continue;
            }
            if(height[nLeft]<=height[nRight])
            {
                //那么移动左边算面积
                int i=nLeft+1;
                for(;i<nRight;++i)
                {
                    if(height[nLeft]<height[i])
                    {
                        //找到了更高的柱子，这次搜索结束
                        nLeft=i;
                        break;
                    }
                    else
                    {
                        nSum+=height[nLeft]-height[i];
                    }
                }
                if(i==nRight)
                {
                    //搜索完了，让循环退出
                    nLeft=nRight;
                }
            }
            else 
            {
                //移动右边
                int i=nRight-1;
                for(;i>nLeft;--i)
                {
                    if(height[nRight]<height[i])
                    {
                        //找到了更高的柱子，这次搜索结束
                        nRight=i;
                        break;
                    }
                    else
                    {
                        nSum+=height[nRight]-height[i];
                    }
                }
                if(i==nLeft)
                {
                    //搜索完了，让循环退出
                    nRight=nLeft;
                }
            }
        }
        return nSum;
    }
};
```
从矮的一头开始，往另外一头开始搜索，假设第一次迭代左边矮
发现不必最左边高的，高度差距就是这一个位置能装的水
直到找到个比他高的，
拿着这个柱子进行第二次迭代，跟另外一头比哪边矮，然后从这头开始继续遍历
如此反复
一次扫描算完所有