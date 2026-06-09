### 解题思路
  从左往右扫，找到对于当前来说的左边的最大值。从右往左扫，找到对于当前开说右边的最大值。根据最小板来说，两个最大值中的最小值，对于当前来说的高度差，就是水的高度（类似于一个坑）。当然，最左边和，最右边是不需要考虑的，但是超时了。
  因此，就直接从两头找过去，找到左边的最大值和右边的最大值。根据之前的原理，如果左边的小于右边的，那就取左边的高度差，否则就取右边的高度差即可。

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int s = 0;
        int l = 0 , r = height.size() - 1;
        int lm = 0 , rm = 0;
        while(l < r){
            lm = max(lm , height[l]);
            rm = max(rm , height[r]);
            if(lm < rm){
                s += lm - height[l++];
            }
            else s += rm - height[r--];
        }
        return s;
    }
};
```