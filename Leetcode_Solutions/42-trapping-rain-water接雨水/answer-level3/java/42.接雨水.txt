一、我的思路：
1.通过找到能够装雨水的最底部，即height[k]<height[k-1] && height[k+1]>height[k]
2.遍历最底部左右两侧，找到左右方向的最值left_index和right_index并记录下标。（两个for实现）
3.比较左右最大值取其中较小值保存到max_min；（因为水只能装到较小的边界处）
4.根据left_index和right_index下标遍历height数组，<max_min的值保存在sum中。
问题：
在12步骤中会出现底部不唯一的问题，即装水的柱子间的底部不平整，有多个值，比如[5,2,1,2,1,5]，存在两个底部。故思路不正确。
二、题解思路：
宏观考虑整个数组中每一个柱子的左右边界，计算该柱子所能装的水。
1.定义两指针max_left和max_right，来找到每个柱子的左右最值。
2.求出左右边界最大值中的较小值max-min。
3.max-min与当前柱子作差，若差值大于0，则加在sum。
优点：比自己的思路更为宏观，自己所考虑的边界太局限，没有考虑整个数组的边界。

```
class Solution {
    public int trap(int[] height) {
        // int sum=0;
        // int k=1;
        // while(k<height.length-1){
        //     //max_left、max_right不能放外面，因为计算当前k的最大最小，不是全局,需要更新
        //     int max_left=0;
        //     int max_right=0;
        //     for(int i=k-1;i>=0;i--){
        //         max_left=Math.max(max_left,height[i]);
        //     }
        //     for(int j=k+1;j<height.length;j++){
        //         max_right=Math.max(max_right,height[j]);
        //     }
        //     int max_min = Math.min(max_left,max_right);
        //     if(max_min>height[k])
        //         sum+=max_min-height[k];

        //     k++;
        // }
        // return sum;
        int k = 1;
        int sum=0;
        while(k<height.length){
            if(k+1<height.length && height[k]<height[k-1] && height[k+1]>height[k]){
                //先将临近左右值保存，并记录下标
                int max_left =height[k-1];
                int max_right =height[k+1];
                int left_index =k-1;
                int right_index =k+1;
                //访问左边，找出最大值。
                for(int i=k-1;i>=0;i--){
                    if(height[i]>max_left){
                        max_left=height[i];
                        left_index=i;
                    }else if(height[i]<max_left)
                        break;
                }
                // 访问右边，找出最小值
                for(int j=k+1;j<height.length;j++){
                    if(height[j]>max_right){
                        max_right=height[j];
                        right_index=j;
                    }else if(height[j]<max_right)
                        break;
                }
                //找到最大中的较小值
                int max_min = Math.min(max_left,max_right);
                for(int m = left_index+1;m<right_index;m++){
                    if(height[m]<max_min)
                        sum+=max_min-height[m];
                }
            }
            k++;
        }
        return sum;
    }

}
```
