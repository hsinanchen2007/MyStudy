### 解题思路一 前缀树
    /*
     * 方法1 前缀树
     *
     * 构建一棵前缀树，将数组中的数存储在前缀树中。
     * 因为异或的特点，相同为假不同为真，而二进制数每一位为1时越大。
     *
     * 所以在对前缀树查找时，
     * 如果当前数的当前位为1，如果存在为0的分支，则转到前缀树为0的分支，并将返回结果的该位置1；
     * 如果当前数的当前位为0，如果存在为1的分支，则转到前缀树为1的分支，并将返回结果的该位置1。
     *
     * 对数组中的每个数进行上述操作，更新返回的结果为最大值的结果。
     * */
### 代码

```cpp
int findMaximumXOR(std::vector<int> &nums) {
    Trie *root = new Trie();
    // 为数组nums的每个数num构建前缀树
    for (int num : nums) {
        insert(root, num);
    }

    int ansMax = 0;
    // 遍历数组中的数
    for (int num : nums) {
        // 返回每个数当前最大的结果，
        // 并更新最大值
        ansMax = std::max(ansMax, (search(root, num)));
    }

    return ansMax;
}

void insert(Trie *root, int num) {
    Trie *node = root;

    // 对31位二进制构建前缀树
    for (int i = 30; i >= 0; i--) {
        // 当前数num的当前位为0或1两种情况
        if ((num >> i) & 1) {
            // 如果该节点为nullptr，则创建新节点
            if (node->next[1] == nullptr) {
                node->next[1] = new Trie();
            }
            // 该位为前缀树节点值为1的节点
            node = node->next[1];
        } else {
            // 如果该节点为nullptr，则创建新节点
            if (node->next[0] == nullptr) {
                node->next[0] = new Trie();
            }
            // 该位为前缀树节点值为0的节点
            node = node->next[0];
        }
    }
}

int search(Trie *root, int num) {
    Trie *node = root;
    int res = 0;

    // 对31位二进制数在前缀树上查找
    for (int i = 30; i >= 0; i--) {
        // 当前数的当前位为0或1两种情况
        // 如果当前位是1
        if ((num >> i) & 1) {
            // 则转到前缀树为0的节点
            // 因为异或时不同为真，而二进制位为1越大
            if (node->next[0]) {
                node = node->next[0];
                // 将结果的该位置1
                res += (1 << i);
            } else {
                node = node->next[1];
            }
        } else {
            // 如果当前位是0
            // 则转到前缀树为1的节点
            // 因为异或时不同为真，而二进制位为1越大
            if (node->next[1]) {
                node = node->next[1];
                res += (1 << i);
            } else {
                node = node->next[0];
            }
        }
    }

    // 返回每一位尽可能为1的结果
    return res;
}
```

### 解题思路二 异或运算+假设修正
    /*
     * 方法2 异或运算+假设修正
     *
     * 异或运算：
     * 如果 a ^ b = c 成立，那么a ^ c = b 与 b ^ c = a 均成立。
     * 即如果有三个数，满足其中两个数的异或值等于另一个值，那么这三个数的顺序可以任意调换。
     *
     * 假设修正：
     * 因为二进制数每一位上出现的1越多，该数越大。从最高位到最低位，假设结果的高位是1，
     * 则将数组中的数都遍历一遍，判断是否为1，否则为0。
     *
     * 根据异或运算和假设修正，如果 a ^ b = max成立，max是当前得到的最大值，则也有max ^ a = b成立。
     * 先假设返回结果的当前位的值为1，在把当前位得到的数与数num的当前前缀进行异或运算，
     * 存储在哈希表中，再依次把所有前缀与该假设的最大值进行异或，得到的结果如果在哈希表中，
     * 则说明返回结果当前位可以为1，否则返回结果的当前位为0.
     * */
### 代码

```cpp
int findMaximumXOR2(std::vector<int> &nums) {
    int mask = 0;
    int ans = 0;

    for (int i = 30; i >= 0; i--) {
        // 定义当前位的掩码
        mask = mask | (1 << i);
        // 存储每一个num的前缀
        std::unordered_set<int> unorderedSet;

        // 遍历数组中的每个数
        for (int num : nums) {
            // 将每个数的前缀插入哈希集合中
            unorderedSet.insert(num & mask);
        }

        // 期望的值
        int temp = ans | (1 << i);

        for (auto it : unorderedSet) {
            // 因为 a ^ b = c，要使c越大，c各位假设为1，并与每个数的前缀异或
            // 如果能够找到异或的值，即 c ^ a = b，在前缀哈希集合中存在b的值，
            // 则将当前期望的值设定为最终结果，每次更新
            if (unorderedSet.find(it ^ temp) != unorderedSet.end()) {
                ans = temp;
                break;
            }
        }
    }

    return ans;
}
```