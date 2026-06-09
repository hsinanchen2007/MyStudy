### 解题思路
我的思路,是利用排序后,相邻的两个数,前面的必定小于或等于后一个数的特性解答题.
具体思路可以看我代码中的解题思路.
本人小白,如果代码中有什么可改进地方,请多加提醒,必万分感激

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] arr) {
       int move = 0;
        // 先进行排序
        Arrays.sort(arr);
        //排序后,相邻的两个数的只会大于或等于相邻的
        for(int i = 0;i < arr.length -1;i++){
            // 如果两个相等,则将后面的自增,
            // 操作数目也自增,并结束本次循环
            if(arr[i] == arr[i+1]){
            arr[i+1]++;
            move++;
            continue;
            }
            //如果相邻的两个,后面的小于前面的,
            // 必定是前面自增导致前面的大于后面的
            //所以将后面的增加到前面的多1;并增加操作数
            if(arr[i] > arr[i+1]){
                int c = arr[i] - arr[i + 1];
                move += ++c;
                arr[i+1] += c;
            }
        }
        return move;
    }
}
```