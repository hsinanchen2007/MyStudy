### 解题思路
1、用以数组来存最后一跳是当前节点时，走过的节点数；初始值都是1，记为Max(i)；
2、遍历每个节点： 
    节点可往左或者往右跳，遇到比当前节点高或者相等的节点就不跳了。（当前节点可以到达的节点）
    遍历这些可到达的节点，如果Max[j] < Max[i] + 1;说明从当前节点i跳到节点j时，Max[j]可以更大
    如果节点j可以更大，则j可能到达的节点也可能更大，将其加入队列，后续再操作一次。
3、直至所有节点的max都不能更大了。
4、找出最大的max数组最大的值


### 代码

```java
class Solution {
static int ans = 0;
    public int maxJumps(int[] arr, int d) {
        int[] max = new int[arr.length];
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < arr.length; i++) {
            max[i] = 1;
            queue.add(i);
        }
        while (!queue.isEmpty()) {
            int index = queue.poll();
            for (int i = index - 1; i >= 0 && i >= index - d; i--) {
                if (arr[i] >= arr[index]) {
                    break;
                }
                if (max[i] < (max[index] + 1)) {
                    max[i] = max[index] + 1;
                    queue.add(i);
                }
            }
            for (int i = index + 1; i < arr.length && i <= index + d ; i++) {
                if (arr[i] >= arr[index]) {
                    break;
                }
                if (max[i] < (max[index] + 1)) {
                    max[i] = max[index] + 1;
                    queue.add(i);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < max.length; i++) {
            // System.out.print(" " + max[i]);
            res = Math.max(res, max[i]);
        }
        return res;
    }
}
```