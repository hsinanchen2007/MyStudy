双指针，只需要扫描一次
根据每次寻边界只需找左右边界最小的那个
所以使用指针l,r从左右两边遍历，lmax用来标记从左边遍历的最大值，rmax用来标记从右边遍历的最大值

如果lmax > rmax
说明右边r指向的元素，最小的左右边界是rmax，然后可以进行累加和计算

如果rmax >= lmax
说明左边l指向的元素，最小的左右边界是lmax，然后可以进行累加和计算


```
class Solution {
    public int trap(int[] height) {
        // 解法是按块进行求面积，使用双指针
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = height.length - 1;
        int sum = 0;
        while(l <= r){
            // 说明最小的左右边界就是lmax
            if(lmax <= rmax){
                if(height[l] <= lmax){
                    sum += lmax - height[l];
                }else{
                    lmax = height[l];
                }
                l++;
            }else{
                // 说明最小的左右边界就是rmax
                if(height[r] <= rmax){
                    sum += rmax - height[r];
                }else{
                    rmax = height[r];
                }
                r--;
            }        
        }
        return sum;
    }
}
```
