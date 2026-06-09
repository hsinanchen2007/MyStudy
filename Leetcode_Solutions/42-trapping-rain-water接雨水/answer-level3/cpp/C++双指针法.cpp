

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int res=0;
        int last=0;
        while(left<right){
            while(left<right&&height[left]<=last) left++;
            while(left<right&&height[right]<=last) right--;
            int tmp=min(height[left],height[right]);
            for(int i=left+1;i<right;i++){
                if(height[i]<last) res+=((tmp-last>0)?(tmp-last):0);
                else res+=((tmp-height[i]>0)?(tmp-height[i]):0);
            }
            if(height[left]<height[right]) left++;
            else right--;
            last=tmp;
        }
        return res;
    }
};
```