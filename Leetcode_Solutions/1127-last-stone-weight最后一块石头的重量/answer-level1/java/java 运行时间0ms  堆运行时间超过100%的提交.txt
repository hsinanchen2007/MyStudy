其实也是和大家差不多的思路，不说那么复杂了。
1. 这里用到了Arrays.sort排序，得到了从小到大的数组。
2. 接下来用lastIndex指针指向未被粉碎的最后一个元素，取两个最大的石头，下标lastIndex,lastIndex-1。两者相减的差值赋给lastIndex-1,再移动下lastIndex指针就相当于删除了最后一个元素了
3. 也可以改写成递归，思路是一样的。

```
import java.util.Arrays;

class Solution {
//一堆石头 每一颗石头重量都是整数
// 每一回合 选出两颗重量最大的石头 x、y x<=y
// x==y 完全粉碎   x!=y y=y-x
//    最后最多会剩下一颗石头 返回该石头重量 如果没有剩下 则返回0
    private int lastIndex;
    private int left;
    public int lastStoneWeight(int[] stones) {
        lastIndex = stones.length-1;
        Arrays.sort(stones);
        while (lastIndex>=1){
            left = stones[lastIndex]-stones[lastIndex-1];
            if (left==0){
               lastIndex=lastIndex-2;
               if (lastIndex==-1){
                   return 0;
               }
            }else {
                stones[--lastIndex]=left;
                Arrays.sort(stones);
            }
        }

        return stones[lastIndex];
    }


   
}

```