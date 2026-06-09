
### 代码1

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxn=0,tmp=0;
        for(size_t i=0;i<height.size()-1;++i)
        {
            for(size_t j=i+1;j<height.size();++j)
            {
                tmp=(j-i)*min(height[i],height[j]);
                maxn=max(maxn,tmp);
            }
        }
        return maxn;
    }
};
```

### 代码2
```cpp
class Solution
{
public:
    int maxArea(vector<int>& height){
        int maxn=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int tmp=(j-i)*min(height[i],height[j]);
            maxn=max(maxn,tmp);
            if(height[i]<height[j])
                ++i;
            else --j;
        }
        return maxn;
    }
};
```