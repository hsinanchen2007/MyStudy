### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        for(int i=0;i<height.size();++i)
        {
            if(height[i]==0) continue;
            int afterimax = 0;
            for(int k=i+1;k<height.size();++k)
            if(height[k]>afterimax) afterimax = height[k];
            for(int j=i+1;j<height.size();++j)
            {
                if(height[j]<height[i]&&height[j]==afterimax) //if j  是后面最高的一个 并且比 i 小 也要考虑到
                {
                    int temp=0;
                    for(int q=i+1;q<j;++q) temp+=afterimax-height[q];
                    sum+=temp;
                    i=j-1;
                    break;
                }
               
                if(height[j]>=height[i]) 
                {
                    int temp=0;
                    for(int q=i+1;q<j;++q) temp+=height[i]-height[q];
                    sum+=temp;
                    i=j-1;
                    break;
                }
            }
        }
        
        return sum;
    }
};
```