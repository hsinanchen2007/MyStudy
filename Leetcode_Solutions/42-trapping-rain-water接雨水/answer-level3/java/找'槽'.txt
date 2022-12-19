回归本质，只有'槽'能装住水
找出所有水槽即可
思路是：
从第一个柱子开始，寻找第一个比它高的柱子，即可组成一个槽。
如果后面没有更高的柱子，就找到后面最高的柱子，这时也可以组成一个槽
```java
    public int trap(int[] height) {
        int len = height.length;
        int rainCount = 0;//雨量
        for (int i=0;i<len-1;i++){
            if (height[i+1]>height[i])continue;//如果这个柱子比下一个低，跳过。
            int higher = height[i];//后面更高的柱子高度
            int higherIndex = i;//后面更高的柱子下标
            int max = height[i+1];//后面的最高柱子
            int maxIndex = i+1;
            boolean hasHigher = false;//后面是否存在比当前柱子更高的柱子
            for (int j=i+1;j<len;j++){
                if (height[j]>=higher){//找到不低于当前柱子的柱子
                    higherIndex = j;
                    hasHigher = true;
                    break;
                }
                if (height[j]>max){//计算后面最高的
                    max = height[j];
                    maxIndex = j;
                }
            }
            if (!hasHigher) {//如果后面没有更高的柱子，就是用后面的最高柱子
                higherIndex = maxIndex;
                higher = max;
            }
            for (int j=i+1;j<higherIndex;j++){//计算这个槽可以几类的雨量
                rainCount+=higher-height[j];
            }
            i=higherIndex-1;//跳到这个槽的右边柱子
        }
        return rainCount;
    }
```
时间复杂度：O(N)，虽然看似有来两个循环，但是他们是线性的
空间复杂度: O(1),只使用了几个变量而已
击败java提交99.98%