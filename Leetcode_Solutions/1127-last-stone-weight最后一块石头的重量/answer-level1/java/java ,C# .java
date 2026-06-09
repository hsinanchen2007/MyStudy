### 解题思路
相同的代码，C#需要112MS,jave需要1MS， 平台优化下C#把。。。

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
         if (1 > stones.length || stones.length > 30) return 0;
            if (stones.length == 1) return stones[0];
            if (stones.length == 2) return Math.abs(stones[0]-stones[1]);

            while (true)
            {
                 Arrays.sort(stones); 
                 stones = reverseArray(stones);
                if (stones[0] == 0 || stones[1] == 0) return Math.abs(stones[0] - stones[1]);

                int y = Math.abs(stones[0] - stones[1]);
                if (y == 0)
                {
                    stones[0] = 0;
                    stones[1] = 0;
                }
                else
                {
                    stones[0] = 0;
                    stones[1] = y;
                }
            }
    }
     public static int[] reverseArray(int[] arr){
        // 遍历数组
        for(int i = 0;i < arr.length / 2;i++){
            // 交换元素
            int temp = arr[arr.length -i - 1];
            arr[arr.length -i - 1] = arr[i];
            arr[i] = temp;
        }
        // 返回反转后的结果
        return arr;
    }
}
```