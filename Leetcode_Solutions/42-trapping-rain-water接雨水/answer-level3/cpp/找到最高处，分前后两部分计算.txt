### 解题思路
calc函数：
是计算start和end之间可以存储多少的雨水：
先计算如果start和end之间没有高度，可以存多少雨水；
然后用上述计算结果依次减去start和end之间的高度，得到二者之间可以存的实际雨水量。

主函数：
先计算最高处mid；
首先从左往右：i从第一个不为0的数字开始，直到mid，如果j处高度大于等于i处，就计算i到j之间可以存多少雨水，然后i=j；
然后从右往左：i从最后一个不为0的数字开始，直到mid，同上。

### 代码

```cpp
class Solution {
public:
    int calc(vector<int>& height,int start,int end){
        int ans = 0,low;
        if(end-start == 1)
            return ans;
        
        low = height[start] < height[end] ? height[start] : height[end];
        ans = low * (end - start - 1);
        for(int i=start+1;i<end;i++){
            ans -= height[i];
        }

        return ans;
    }

    int trap(vector<int>& height) {
        if(height.size() <= 1)
            return 0;

        int res = 0,i = 0,j,mid;

        mid = 0;
        for(int k=0;k<height.size();k++){
            if(height[k] >= height[mid])
                mid = k;
        }

        while(height[i++] == 0 && i<height.size());
        if(i == height.size())
            return 0;
        --i;
        while(i<mid){
            for(j = i+1;j<height.size();j++){
                if(height[j] >= height[i]){
                    res += calc(height,i,j);
                    break;
                }
            }
            i = j;
        }

        i = height.size()-1;
        while(height[i--] == 0);
        ++i;
        while(i>mid){
            for(j = i-1;j>=0;j--){
                if(height[j] >= height[i]){
                    res += calc(height,j,i);
                    break;
                }
            }
            i = j;
        }

        return res;
    }
};
```