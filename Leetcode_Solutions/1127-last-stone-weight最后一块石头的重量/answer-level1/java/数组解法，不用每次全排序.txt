
![1576639489(1).png](https://pic.leetcode-cn.com/927b5b520a7c80d50b2e6e7945689891eeb3b945f6d72b4ce08f10ecd912c679-1576639489\(1\).png)

这里没有使用堆，直接用的原数组。
借鉴了前几天看另外一道题，有位同学用的冒泡排序的想法。

可以得知：如果从小到大排序后，石头最终一直从右往左进行粉碎，最终返回结果就是stones[0]
利用冒泡排序每次获取最大的两个值，没必要进行整个的排序，进行粉碎处理后，处理下标往左移动

比如 [9,3,2,10]，此时下标index为3
一次粉碎时，排序后[2,3,9,10]-> 粉碎后[2,3,1,10]，index变成了2
二次粉碎时，排序后[1,2,3,10]-> 粉碎后变成[1,1,3,10]，index变成了1
三次粉碎时，排序后[1,1,3,10]-> 粉碎后变成[0,1,3,10]，index变成了0
不满足循环条件，返回stones[0]，即0
stones[index]的值不用管，后面用不到
```
class Solution {
    public int lastStoneWeight(int[] stones) {
        int index = stones.length-1;
        while(index > 0){
            int max = 0;
            for(int j=0;j<2;j++){
                max = 0;
                for(int i=1;i<=index-j;i++){
                    if(stones[i]>stones[max]){
                        max = i;
                    }
                }
                if(max < index-j){
                    int temp = stones[max];
                    stones[max] = stones[index-j];
                    stones[index-j] = temp;
                }
            }
            stones[index-1] = stones[index] - stones[index-1];
            index--;
            if(stones[index] == 0){
                 index--;
            }
        }
        return stones[0];
    }
}
```
