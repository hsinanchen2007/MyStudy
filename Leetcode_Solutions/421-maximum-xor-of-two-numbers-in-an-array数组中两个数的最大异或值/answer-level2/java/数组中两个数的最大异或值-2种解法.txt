>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 2)，其中n为nums的长度。空间复杂度是O(1)。

执行用时：149ms，击败9.64%。消耗内存：49.5MB，击败16.08%。

```java
public class Solution {
    public int findMaximumXOR(int[] nums) {
        int n;
        if (null == nums || (n = nums.length) < 2) {
            return 0;
        }
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                result = Math.max(result, nums[i] ^ nums[j]);
            }
        }
        return result;
    }
}
```

# 解法二：Trie

时间复杂度是O(n)。空间复杂度是O(1)。

执行用时：12ms，击败98.80%。消耗内存：57.1MB，击败5.59%。

```java
public class Solution {
    private class TrieNode {
        private int val;

        private TrieNode zero, one;

        private boolean isNum;
    }

    private class Trie {
        private TrieNode root = new TrieNode();

        public void insert(int num) {
            TrieNode cur = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;   //bit代表num中的第i位值，最低位为第0位，最高位为第31位
                if (bit == 0 && cur.zero == null) {
                    cur.zero = new TrieNode();
                }
                if (bit == 1 && cur.one == null) {
                    cur.one = new TrieNode();
                }
                cur = bit == 0 ? cur.zero : cur.one;
            }
            cur.val = num;
            cur.isNum = true;
        }
    }

    public int findMaximumXOR(int[] nums) {
        if (null == nums || nums.length < 2) {
            return 0;
        }
        Trie root = new Trie();
        for (int num : nums) {
            root.insert(num);
        }
        //获取真正需要开始判断的root
        //以题目所给示例[3, 10, 5, 25, 2, 8]说明，各个数字的二进制表示如下：
        //3： 0000 0000 0000 0000 0000 0000 0000 0011
        //10：0000 0000 0000 0000 0000 0000 0000 1010
        //5： 0000 0000 0000 0000 0000 0000 0000 0101
        //25：0000 0000 0000 0000 0000 0000 0001 1001
        //2： 0000 0000 0000 0000 0000 0000 0000 0010
        //8： 0000 0000 0000 0000 0000 0000 0000 1000
        //显然对于[5, 31]位的元素，其值均为0，无需进行判断计算，因此真正的根节点就是第5位的元素，其值为0，其子节点值有两个，分别是0和1
        TrieNode cur = root.root;
        while (null == cur.one || null == cur.zero) {
            cur = cur.zero != null ? cur.zero : cur.one;
        }
        return findMaximumXOR(cur.one, cur.zero);
    }

    private int findMaximumXOR(TrieNode one, TrieNode zero) {
        if (one.isNum && zero.isNum) {  //如果均递归到底，两个节点代表的均是数字
            return one.val ^ zero.val;
        }
        if (one.zero == null) { //如果节点one的子节点只能取1，那么节点zero的子节点应尽可能取0
            return findMaximumXOR(one.one, zero.zero == null ? zero.one : zero.zero);
        } else if (one.one == null) {   //如果节点one的子节点只能取0，那么节点zero的子节点应尽可能取1
            return findMaximumXOR(one.zero, zero.one == null ? zero.zero : zero.one);
        } else if (zero.zero == null) { //如果节点zero的子节点只能取1，那么节点one的子节点取0
            return findMaximumXOR(one.zero, zero.one);
        } else if (zero.one == null) {  //如果节点zero的子节点只能取0，那么节点one的子节点取1
            return findMaximumXOR(one.one, zero.zero);
        }
        //进入此处说明节点one和节点zero均存在两个子节点分别是0和1
        return Math.max(findMaximumXOR(one.one, zero.zero), findMaximumXOR(one.zero, zero.one));
    }
}
```