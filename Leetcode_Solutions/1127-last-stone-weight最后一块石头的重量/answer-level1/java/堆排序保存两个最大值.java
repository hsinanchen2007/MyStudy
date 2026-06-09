### 解题思路
1. 不断循环排序，找到最大两个值
2. 直到第一个值是0，或者第一个不是0，第二个是0
3. 需要用到大堆排序方法，找到最值

### 代码

```java
class Solution {
    // 求解方法仍然是使用堆排序
    // 每次排出两个最大的数，减去之后一个为0，另外一个为剩下的数
    // 然后重新排序
    public int lastStoneWeight(int[] stones) {
        int size = stones.length;
        // 如果数组只有1个，就直接返回
        if(size <= 1){
            return stones[0];
        }
        do {
            // 找到第一个最大值
            int a = findMaxElementByHeap(stones);
            // 为0 就返回
            if(a == 0){
                return 0;
            }
            // 去掉第一个元素，剩余的元素按照大堆排序找到第二个最大的
            int[] stones2 = Arrays.copyOfRange(stones, 1, stones.length);
            int b = findMaxElementByHeap(stones2);
            // 如果第二个元素最大为0，则证明已经有结果了，返回前一个即可
            if(b == 0){
                return a;
            }
            // 把数组2从0开始复制到数组1中去
            // 复制参数是
            // 1-源
            // 2-从源到哪个位置开始复制
            // 3-目的地
            // 4-从目的地哪个位置开始放置
            // 5-复制到长度是多少
            System.arraycopy(stones2, 0, stones, 1, stones2.length);

            stones[0] = a-b;
            stones[1] = 0;

        } while (true);
    }

    // 大堆排序私有方法
    private int findMaxElementByHeap ( int[] arr){
            for (int i = 0; i < arr.length; i++) {
                int j = i + 1;
                if (j >= arr.length) {
                    return arr[0];
                }
                while (j > 0) {
                    boolean even = arr[j] % 2 == 0;
                    int parent;
                    int parentIndex;
                    if (even) {
                        parentIndex = (j - 2) / 2;
                    } else {
                        parentIndex = (j - 1) / 2;
                    }
                    parent = arr[parentIndex];
                    if (arr[j] > parent) {
                        arr[parentIndex] = arr[j];
                        arr[j] = parent;
                        j = parentIndex;
                        continue;
                    } else {
                        break;
                    }
                }
            }
            return arr[0];
        }
}
```