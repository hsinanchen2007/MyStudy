### 解题思路
首先要分析出一个格子是否能存水取决于其左边的格子存在一个高度大于他的格子，
右边也存在一个格子大于该格子的高度
可以想到从左右两边开始遍历，寻找第一个大于0的格子作为左右两边的最高的格子。
然后依次或从左开始往右遍历，或从右往左遍历。
通过分析可以得出，如果右边当前格子大于左边的格子，只要当前左格子大于最大格子，则该格子存水量为最大左边格子减去当前左格子高度;
反之亦然。


### 代码

```java
class Solution {
    public int trap(int[] height) {
        //从左到右两边开始遍历，在遍历左边的时候，只要右边的高度大于当前高度说明该格子可以存水
        int left=0,right=height.length-1,maxLeft=0,maxRight=0;
        int counts=0;
        while (left<right){
            if(height[left] < height[right]){
                //右边的高度大于左边高度，说明这个格子可能能存水
                if (height[left] >= maxLeft) {//这个格子能存水的第二个条件，要小于最大左边的高度。
                    maxLeft = height[left];
                } else {
                    counts += (maxLeft - height[left]);
                }
                left++;
            }else {
                //同理
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    counts += (maxRight - height[right]);
                }
                --right;
            }

        }
        return counts;
    }
}
```