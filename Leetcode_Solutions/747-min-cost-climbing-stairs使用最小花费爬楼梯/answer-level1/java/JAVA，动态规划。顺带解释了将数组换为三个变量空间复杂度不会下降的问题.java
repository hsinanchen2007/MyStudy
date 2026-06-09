如需提交请自行去掉static，注释，与main函数
```
package leetCodeTest;

import java.util.Arrays;

public class 使用最小花费爬楼梯 {
    public static void main(String[] args) {
        int[] cost = new int[]{0,0,0,1};
        int i = minCostClimbingStairs(cost);
        System.out.println("i = " + i);
    }

    /**
     * 传统动态规划方法，使用数组存储，每一位与之前两位之和的最小值
     * （判断当前走一步花费大还是走两步花费大，相当于从现在位置向后倒），
     * 作为当前位的最佳步长，
     * 然后得到sum数组，判断最后两位值那个最小，
     * 最小的值就是最小的花费（因为最后一步可以走一步或者两步）
     * @param cost
     * @return
     */
//    public static int minCostClimbingStairs(int[] cost) {
//        if (cost.length == 0)
//            return 0;
//        if (cost.length == 1)
//            return cost[0];
//        int i;
//        int[] sum = new int[cost.length];
//        sum[0] = cost[0];
//        sum[1] = cost[1];
//        for (i=2;i<cost.length;i++){
//            sum[i] = Math.min(sum[i-2] + cost[i],sum[i-1] + cost[i]);
//        }
////        System.out.println(Arrays.toString(sum));
//        return Math.min(sum[sum.length-1],sum[sum.length-2]);
//    }

    /**
     * 使用三个变量去存储我们所需要的值，由于我们
     * 运算的时候只需要之前两个位置的最小花费
     * 即可计算出当前位置的最小花费，所以取三个变量
     * 存储当前位置的最小花费与之前两个位置的最小花费即可。
     *
     * 注意：此方法并不能使内存效率提升，原因是，
     * 使用传统的sum数组方法的时候，我们JVM虚拟机会在堆空间
     * 中直接开辟一组内存，然后在栈空间中由一个指针指向该内存的初始地址，
     * 当操作的时候可以直接通过指向地址加上数组下标得到数据存储位置。
     * 但是如果使用三个变量存储的话，就会随机开辟堆中的三个空间来存放数据，
     * 然后在栈空间中开辟三个指针指向这三个地址，当你改变其中的某一个变量
     * 的值的时候不仅仅改变了指针指向，还会导致在堆空间中重新开辟一组新的变量值。
     * 所以这种情况下，使用三个变量存储效率并不会提升。
     * @param cost
     * @return
     */
    public static int minCostClimbingStairs(int[] cost) {
        if (cost.length == 0)
            return 0;
        if (cost.length == 1)
            return cost[0];
        int i,Si_1,Si_2,temp;
        int[] sum = new int[cost.length];
        Si_1 = cost[0];
        Si_2 = cost[1];
        for (i=2;i<cost.length;i++){
            temp = Math.min(Si_1 + cost[i],Si_2 + cost[i]);
            Si_1 = Si_2;
            Si_2 = temp;

        }
//        System.out.println(Arrays.toString(sum));
        return Math.min(Si_1,Si_2);
    }
}

```
