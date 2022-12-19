### 解题思路
我们可以想象成怎么找到这些方块所组成的所有容器，再去计算这些容器的容量即可。那么要怎么找呢？首先要有一个底部，接着往左右两边向上延伸，直到到达左右两边所能达到的最大高度，便可以计算该容器两个边界之间的容量了。容量的计算也很简单，遍历容器两侧中间的方块，用较低的边界高度减去当前方块的高度即可。

![image.png](https://pic.leetcode-cn.com/6bcd5ce6cd59b213d765f96b12ae31bada5c70df7cddbab290d1b0b4d2854a04-image.png)

#### 注意
- 由于我们是从左往右寻找容器的，因此要注意在寻找当前容器的左边界时，不能越过上一个容器的右边界。
- 在确定了容器两侧的边界后，若左侧高度低于右边高度，则在计算容量的过程中可能需要更新左侧高度。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        //定义寻找左右边界的指针
        int i=1,j=0,res=0;
        int leftBound=i,rightBound=j;
        for(int k=1;k<height.length-1;k++){
            //定义左右最大高度的边界
            int curr = height[k],leftTop=curr,rightTop=curr;
            i=k-1;
            j=k+1;
            leftBound=k;
            //寻找左界
            while(i>=rightBound){
                if(height[i]>leftTop) {
                	leftTop=height[i];
                	leftBound=i;
                }
                    i--;
            }
            //若找不到左界，则寻找下一个容器底部
            if(height[k]>=height[leftBound])continue;
            rightBound=j;
            while(j<height.length){
                if(height[j]>rightTop) {
                	rightTop=height[j];
                	rightBound=j;
                }
                    j++;
            }
            //若找不到右界，则寻找下一个容器底部
            if(height[k]>=height[rightBound]) {
            	//恢复右界
                rightBound=k;
            	continue;
            }
            //确定下一个容器开始查找的底部
        	k=rightBound;
            //得到高度较低的边界
            int bound=Math.min(leftTop,rightTop);
            //计算容量
            for(int x=leftBound+1;x<rightBound;x++) {
            	if(height[x]<bound)
                    res+=bound-height[x];
                //更新边界的高度
            	else if(bound<rightTop) bound=height[x];
            }
        }
        return res;
    }
}
```