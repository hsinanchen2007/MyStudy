```java
class Solution {
    public int findMaximumXOR(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }
        Trie trie = new Trie();
        for (int num : nums) {
            trie.insert(num);
        }
        Trie.TrieNode cur = trie.root;
        while (cur.one == null || cur.zero == null) {
            cur = cur.zero != null ? cur.zero : cur.one;
        }
        return trie.searchXor(cur.one, cur.zero);
    }

    static class Trie {
        static class TrieNode{
            int value;
            TrieNode one;
            TrieNode zero;

            TrieNode(int value) {
                this.value = value;
            }
        }

        TrieNode root;

        Trie() {
            this.root = new TrieNode(-1);
        }

        void insert(int num) {
            TrieNode cur = root;
            int j = 1 << 30;
            for (int i = 0; i < 31; i++) {
                int bit = (j & num);
                if (bit == 0) {
                    if (cur.zero == null) {
                        cur.zero = new TrieNode(-1);
                    }
                    cur = cur.zero;
                } else {
                    if (cur.one == null) {
                        cur.one = new TrieNode(-1);
                    }
                    cur = cur.one;
                }
                j >>= 1;
            }
            cur.value = num;
        }

        int searchXor(TrieNode one, TrieNode zero) {
            if (one.value != -1 && zero.value != -1) {
                return one.value ^ zero.value;
            }
            if (one.zero == null) {
                return searchXor(one.one, zero.zero != null ? zero.zero : zero.one);
            }
            if (one.one == null) {
                return searchXor(one.zero, zero.one != null ? zero.one : zero.zero);
            }
            if (zero.zero == null) {
                return searchXor(zero.one, one.zero);
            }
            if (zero.one == null) {
                return searchXor(zero.zero, one.one);
            }
            return Math.max(searchXor(one.one, zero.zero), searchXor(one.zero, zero.one));
        }
    }
}
```