- 借用桶的概念。
- 1.一个数组N个数,准备N+1个桶
- 2.遍历整个数组找到最小值min,最大值max
  - 如果最小值与最大值相等,return 0

- 如果最小值与最大值不等
  - 最小值放在0号桶里,最大值放在N号桶里
  - 将最小值到最大值这个范围等分成N+1份,这个数属于哪个范围就放在哪个桶里
    - 一个数组9个数
    - 准备10个桶(0,1,2...9)
    - 假设最小值为0,最大值为9->0放在0号桶,9放在9号桶
    - 0-9分成10份，那么5就放在5号桶里
- N个数字N+1个桶,那么**中间必定存在一个空桶**
  - **最大差值 = 右非空桶的最小值 - 左非空桶的最大值**（错误思想-非常的错误-错的就你吗离谱）比如:
    - {19(10-19)}
    - {空}
    - {30(30-39)}
    - {49(40-49)}
    - ->最大差值是49-19而不是30-19
  - **非空桶只是为了否到最大差值来自于桶内部**
    - 只需要找进每一个桶的最大值和最小值即可
    - 每个桶的三个值:boolean(该桶是否有元素),min(进过桶的最小值),max(进过桶的最大值)。
    - **每一个非空桶的最小值都找该桶左边最近的非空桶的最大值相减记录最大差值。**

```
package cn.cqu.ccc1z.week1;

/**
 * 给定一个数组,求排序之后,相邻两数的最大差值,要求时间复杂度O(N),
 * 且要求不能用非基于比较的排序。([3,1,6,2,7]->返回3)
 */
public class MaxGap {
    public static int maxGap(int[] arr){
        if(arr == null || arr.length < 2){
            return 0;
        }
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            max = Math.max(max,arr[i]);
            min = Math.min(min,arr[i]);
        }
        if(min == max){
            return 0;
        }
        boolean[] hasNum = new boolean[len+1];
        int[] maxs = new int[len+1];
        int[] mins = new int[len+1];
        int bid = 0;
        for(int i = 0; i < len ;i++){
            bid = bucket(arr[i],len,min,max);
            mins[bid] = hasNum[bid] ? Math.min(mins[bid],arr[i]) : arr[i];
            maxs[bid] = hasNum[bid] ? Math.max(maxs[bid],arr[i]) : arr[i];
            hasNum[bid] = true;
        }
        int res = 0;
        int lastMax = maxs[0];
        int i = 1;
        for(;i<=len;i++){
            if(hasNum[i]){
                res = Math.max(res,mins[i] - lastMax);
                lastMax = maxs[i];
            }
        }
        return res;
    }

    public static int bucket(long num,long len,long min,long max){
        return (int)((num - min) * len / (max-min));
    }
}

```
