### 解题思路
![image.png](https://pic.leetcode-cn.com/c437fe7126387944568ad302b9c1a59956c932ccbe437d0e422ede2902cf689f-image.png)
首先距离至少大于等于3才有可能出现凹点,
其次i>i+1,才会以i开始到j存在凹点
逐一计算每一个出现的面积

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int result=0;
        //因为至少需要三个所以循环到height.length-2
        for(int i=0;i<height.length-2;i++){
            //如果height[i]<=height[i+1]必然不满足跳出此次循环
            if(height[i]<=height[i+1]){
                continue;
            }
            //从i开始到j结束中间存在的最高点max<height[i]&&max<height[j]
            int max=height[i+1];
            for(int j=i+2;j<height.length;j++){
                //如果找到height[j]>=height[i] 说明height[j]是以i为起始点,最远距离,计算面积,跳出循环,因为不会存在height[i]到height[j+1]
                if(height[j]>=height[i]){
                    result=result+(height[i]-max)*(j-i-1);
                    break;
                }else if(height[j]>max){
                    //如果height[j]>max但是height[j]<height[i],并且已经到达边界了那么计算面积跳出循环,因为j是数组的边界位置
                    if(j+1>=height.length){
                        result=result+(height[j]-max)*(j-i-1);
                        break;
                    }else{
                        //如果只是height[j]>max,计算i到j面积
                        result = result + (height[j] - max) * (j - i - 1);
                        //重新赋值max继续寻找最大的height[j]
                        max=height[j];
                    }
                }
            }
        }
        return result;
    }
}
```