（1）从左向右遍历，左指针记录左侧挡板，右指针递增，直到右指针挡板高度大于等于左指针，此时计算两个指针中间位置的水量。然后从右指针开始继续遍历。如此循环直到数组结尾。
（2）如果最后右指针高度未能大于等于最指针，只需将这一部分翻转，再遍历这一部分即可。
```
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = 1;
        res += Calcu(height, l, r);
        if(l < r) {
            reverse(height.begin() + l, height.end());
            r = l + 1;
            res+=Calcu(height, l, r);
        }

        return res;
    }
private:
    int Calcu(vector<int>& height, int &l, int &r){
        int res = 0;
        while(r < height.size()) {
            for(; r < height.size(); r++) {
                if(height[l] <= height[r]) {
                    for(int i = l + 1; i < r; i++) {
                        res += height[l] - height[i];
                    }
                    l = r;
                    r++;
                    break;
                }
            }
        }
        return res;
    }
};
```
