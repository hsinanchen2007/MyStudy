### 解题思路
代码中只有一处与[「探索——前缀树」](https://leetcode-cn.com/explore/learn/card/trie/168/practical-application-ii/651/)的通用模版中不同的地方，已经给出相应注释，相信如果知道前缀树的通用模版，其他地方都能看懂了。（PS：原本 `node` 中的 `children` 是使用 map 来实现的，竟然超时了...）

### 代码

```java
class Solution {

    class Node {
        Node[] children = new Node[2];
    }

    static final int MAX_BIT = 31;
    static final int MIN_BIT = 0;

    Node root = new Node();

    public int findMaximumXOR(int[] nums) {
        if (nums == null) {
            return 0;
        }
        initTrie(nums);
        return helper(nums);
    }

    private void initTrie(int[] nums) {
        for (int num : nums) {
            Node cur = root;
            for (int i = MAX_BIT; i >= MIN_BIT; i--) {
                int bit = getBit(num, i);
                Node next = cur.children[bit];
                if (next == null) {
                    next = new Node();
                    cur.children[bit] = next;
                }
                cur = next;
            }
        }
    }

    private int helper(int[] nums) {
        int max = Integer.MIN_VALUE;

        for (int num : nums) {
            Node cur = root;
            int sum = 0; 
            for (int i = MAX_BIT; i >= MIN_BIT; i--) {
                int bit = getBit(num, i);
                int xorBit = bit ^ 1;

                /* 
                 * 1. 异或位为空，则该位没有可以异或的值，则从原位置继续下一次循环；
                 * 2. 异或位不为空，说明该位置可以进行异或操作，则从异或后的位置继续循环，
                 * 并将 num 对应的异或值之和 sum 相应位置加上 1；
                 */
                Node next = cur.children[xorBit];
                if (next == null) {
                    cur = cur.children[bit];
                } else {
                    sum += (1 << i); 
                    cur = next;
                }
            }
            max = Math.max(max, sum);
        }
        return max;
    }

    private int getBit(int num, int bit) {
        return (num >>> bit) & 1; 
    }
}
```