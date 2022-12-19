### 解题思路
半暴力求解，先挑出数列中的递增递减子列，递增列作为候选左板，递减列作为候选右板，然后暴力求解，复杂度O(n^2)，但随机情况下实际效率较高，平均执行用时8ms

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int Length=height.size();
        int inc[Length];
        int dec[Length];
        int Max=-1,Min=-1,ic=0,dc=0;
        for(int i=0;i<Length;i++){
            int inv=Length-i-1;
            if(height[inv]>=Min){
                dec[dc]=inv;
                Min=height[inv];
                dc++;
            }
            if(height[i]>=Max){
                inc[ic]=i;
                Max=height[i];
                ic++;
            }
        }
        if(dc<Length)dec[dc]=-1;
        if(ic<Length)inc[ic]=-1;
        int ou=0;
        for(int i=0;i<Length&&inc[i]!=-1;i++){
            for(int j=0;j<Length&&dec[j]>inc[i]&&dec[j]!=-1;j++){
                int vol=(dec[j]-inc[i])*
                min(height[inc[i]],height[dec[j]]);
                ou=max(vol,ou);
            }
        }
        return ou;
    }
};
```