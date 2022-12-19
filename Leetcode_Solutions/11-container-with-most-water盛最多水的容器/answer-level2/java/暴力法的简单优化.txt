首先这个算法并不像大佬们的双指针法效率那么高，只是在暴力法上做一点简单的优化，获取稍好的时间复杂度。
暴力法就是做一次遍历，将所有的面积全部算出来，求最大值。
在此基础上，对每一个高度，假设它就是容器的高度，那么离他最远的边形成的容器，容积也必定是最大的。
设i为高度的下标，我们将i分成两种情况：
1.i <= length / 2    此时应当从数组的末尾开始寻找能与它组成容器的边。
2.i >= length / 2    此时应当从数组的头部开始寻找
寻找过程也可以分为两种情况：
1.当找到距离最远的边时，就相当于获取了该高度最大的容积，就可直接跳出。
2.当查找到i位置时，停止查找。
2这种情况相当于目前i对应的高度是唯一最高的，无法与其它边组成以它为高度的容器。但这一条高度仍能作为其它高度的边。
最后附上代码：
```
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for(int i = 0;i < height.length;i++){
            if(i <= height.length / 2){
                for(int j = height.length - 1;j > i;j--){
                    if(height[j] >= height[i]){
                        int volume = height[i] * (j - i);
                        max = volume > max ? volume : max;
                        break;
                    }
                }
            }
            if(i >= height.length / 2){
                for(int j = 0;j < i;j++){
                    if(height[j] >= height[i]){
                        int volume = height[i] * (i - j);
                        max = volume > max ? volume : max;
                        break;
                    }
                }
            }
        }
        return max;
    }
}
```
Java下我的运行时间为161ms，比起暴力法的800ms进步还是挺大的。
虽然时间比起双指针法还是差点意思，但毕竟是自己思考得到的，还是挺开心的，分享一下。