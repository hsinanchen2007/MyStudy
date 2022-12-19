#### 概述

题目要求 $O(N)$ 时间复杂度，下面会讨论两种典型的 $O(N)$ 复杂度解法。

1. 利用哈希集合存储按位前缀。
2. 利用字典树存储按位前缀。

这两种解法背后的思想是一样的，都是先将整数转化成二进制形式，再从最左侧的比特位开始逐一处理来构建最大异或值。两个方法的不同点在于采用了不同的数据结构来存储按位前缀。第一个方法在给定的测试集下执行速度更快，但第二种方法更加普适，更加简单。

**基础知识**

0 和任意比特 x 异或结果还是 x 本身。

$$
0 \oplus x = x  
$$

如果a，b两个值相同，异或结果为0

$$
x \oplus x = 0  
$$

#### 方法一：利用哈希集合存储按位前缀

假定数组为 `[3, 10, 5, 25, 2, 8]`，首先将其中的整数转化成二进制形式：

$3 = (00011)_2$

$10 = (01010)_2$

$5 = (00101)_2$

$25 = (11001)_2$

$2 = (00010)_2$

$8 = (01000)_2$

为了简化按位前缀的计算，将所有数转化成二进制形式之后，需要在左边补 0 使得所有数对齐。最终所有数的长度都为 $L$，其中 $L$ 为最大数的二进制长度。

之后我们就可以从最左侧的比特位开始构建最大异或值了，在 $L = 5$ 的情况下，可能的最大异或值为 $(11111)_2$。

- 首先检查最左侧的比特位有可能使其为 1 嘛？（即 $(1****)_2$ 这种形式）。

显然是可以的，只要将 $25 = (11001)_2$ 和另一个最左侧比特位为 0 的数（2，3，5，8，10）异或就可以了，这时候就得到了 $(1****)_2$。

- 继续下一步，有可能使得最左侧两个比特位都为 1 嘛？（即 $(11***)_2$ 这种形式）

这时候考虑所有长度为 2 的按位前缀，检查是否有 $p_1$，$p_2$ 这样的组合，使得 $p_1 \oplus p_2 == 11$。

$3 = (00***)_2$

$10 = (01***)_2$

$5 = (00***)_2$

$25 = (11***)_2$

$2 = (00***)_2$

$8 = (01***)_2$

显然在这个数组里面是有的，如 $5 = (00***)_2$ 和 $25 = (11***)_2$ 异或，或者 $2 = (00***)_2$ 和 $25 = (11***)_2$ 异或，又或者 $3 = (00***)_2$ 和 $25 = (11***)_2$ 异或。 

按这种方式一比特一比特处理下去就可以得到最大异或值。在这过程中需要检查各种前缀的异或结果，但由于长度为 $L - i$ 的前缀数量不会超过 $2^{L - i}$，因此判断第 $i$ 个比特位是否有可能为 1 最多需要执行 $2^{L - i} \times 2^{L - i}$ 次操作。

**算法**

- 首先计算数组中最大数的二进制长度 $L$。

- 初始化 `max_xor = 0`。

- 从 $i = L - 1$ 遍历到 $i = 0$（代表着从最左侧的比特位 $L - 1$ 遍历到最右侧的比特位 $0$）：

    - 将 `max_xor` 左移，释放出下一比特位的位置。
    
    - 初始化 `curr_xor = max_xor | 1`（即将 `max_xor` 最右侧的比特置为 1）。
    
    - 遍历 `nums`，计算出长度为 $L - i$ 的所有可能的按位前缀。
        
        - 将长度为 $L - i$ 的按位前缀加入哈希集合 `prefixes`，按位前缀的计算公式如下：`num >> i`。
        
    - 遍历所有可能的按位前缀，检查是否存在 `p1`，`p2` 使得 `p1^p2 == curr_xor`。比较简单的做法是检查每个 `p`，看 `curr_xor^p` 是否存在。如果存在，就将 `max_xor` 改为 `curr_xor`（即将 `max_xor` 最右侧的比特位改为 1）。如果不存在，`max_xor` 最右侧的比特位继续保持为 0。
    
- 返回 `max_xor`。 

```java [solution1-Java]
class Solution {
  public int findMaximumXOR(int[] nums) {
    int maxNum = nums[0];
    for(int num : nums) maxNum = Math.max(maxNum, num);
    // length of max number in a binary representation
    int L = (Integer.toBinaryString(maxNum)).length();

    int maxXor = 0, currXor;
    Set<Integer> prefixes = new HashSet<>();
    for(int i = L - 1; i > -1; --i) {
      // go to the next bit by the left shift
      maxXor <<= 1;
      // set 1 in the smallest bit
      currXor = maxXor | 1;
      prefixes.clear();
      // compute all possible prefixes 
      // of length (L - i) in binary representation
      for(int num: nums) prefixes.add(num >> i);
      // Update maxXor, if two of these prefixes could result in currXor.
      // Check if p1^p2 == currXor, i.e. p1 == currXor^p2.
      for(int p: prefixes) {
        if (prefixes.contains(currXor^p)) {
          maxXor = currXor;
          break;
        }
      }
    }
    return maxXor;
  }
}
```

```python [solution1-Python]
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # length of max number in a binary representation
        L = len(bin(max(nums))) - 2
        max_xor = 0
        for i in range(L)[::-1]:
            # go to the next bit by the left shift
            max_xor <<= 1
            # set 1 in the smallest bit
            curr_xor = max_xor | 1
            # compute all existing prefixes 
            # of length (L - i) in binary representation
            prefixes = {num >> i for num in nums}
            # Update max_xor, if two of these prefixes could result in curr_xor.
            # Check if p1^p2 == curr_xor, i.e. p1 == curr_xor^p2
            max_xor |= any(curr_xor^p in prefixes for p in prefixes)
                    
        return max_xor
```

**复杂度分析**

* 时间复杂度：$O(N)$。计算按位前缀需要遍历 nums 数组，复杂度为 $N$，计算所有可能按位前缀的异或结果复杂度为 $2^{L - i} \times 2^{L - i}$。最终复杂度为 $\sum_{i = 0}^{L - 1}{(N + 4^{L - i})} = NL + \frac{4}{3}(4^L - 1)$，即 $O(N)$ 复杂度。

* 空间复杂度：$O(1)$。最长的按位前缀长度为 $L$，同时 $L = 1 + [\log_2 M]$，其中 M 为 nums 中的最大数值。

#### 方法二：逐位字典树

**为什么哈希集合不适合用来存储按位前缀？**

对于那些一定不能得到最终解的路径可以通过剪枝来舍弃，但是用哈希集合来存储按位前缀是没法做剪枝优化的。举个例子，两次异或操作之后为了得到 $(11***)_2$，显然只能让 25 和 最左侧为 $00$ 前缀的数字（2，3， 5）组合。

$3 = (00011)_2$

$10 = (01010)_2$

$5 = (00101)_2$

$25 = (11001)_2$

$2 = (00010)_2$

$8 = (01000)_2$

因此，在计算第三位比特的时候，我们就没有必要计算所有可能的按位前缀组合了。光看前两位就知道一些组合已经不能得到最大异或值了。

$3 = (000**)_2$

$10 = (010**)_2$

$5 = (001**)_2$

$25 = (110**)_2$

$2 = (000**)_2$

$8 = (010**)_2$

为了方便剪枝，我们要采用一种类树的存储结构。

**按位字典树：这是什么？怎么构建？**

假设数组为 `[3, 10, 5, 25, 2]`，据此来构建按位字典树。

$3 = (00011)_2$

$10 = (01010)_2$

$5 = (00101)_2$

$25 = (11001)_2$

$2 = (00010)_2$

![fig](https://pic.leetcode-cn.com/Figures/421/trie.png)

字典树中每条根节点到叶节点的路径都代表了 nums 中的一个整数（二进制形式），举个例子，0 -> 0 -> 0 -> 1 -> 1 表示 3。与之前的方法一样，所有二进制的长度都为 $L$，其中 $$L = 1 + [\log_2 M]$$，这里 M 为 nums 中的最大数值。显然字典树的深度也为 $L$，同时叶子节点也都在同一层。

字典树非常适合用来存储整数的二进制形式，例如存储 2（00010） 和 3（00011），其中 5 个比特位中有 4 个比特位都是相同的。字典树的构建方式也很简单，就是嵌套哈希表。在每一步，判断要增加的孩子节点（0，1）是否已经存在，如果存在就直接访问该孩子节点。如果不存在，需要先新增孩子节点再访问。

```java [snippet1-Java]
TrieNode trie = new TrieNode();
for (String num : strNums) {
  TrieNode node = trie;
  for (Character bit : num.toCharArray()) { 
    if (node.children.containsKey(bit)) {
      node = node.children.get(bit);
    } else {
      TrieNode newNode = new TrieNode();
      node.children.put(bit, newNode);
      node = newNode;
    }
  }  
}
```

```python [snippet1-Python]
trie = {}
for num in nums:
    node = trie
    for bit in num:
        if not bit in node:
            node[bit] = {}
        node = node[bit]
```

**字典树中给定数的最大异或值** 

为了最大化异或值，需要在每一步找到当前比特值的互补比特值。下图展示了 25 在每一步要怎么走才能得到最大异或值：

![fig](https://pic.leetcode-cn.com/Figures/421/max_xor.png)

实现方式也很简单：

- 如果当前比特值存在互补比特值，访问具有互补比特值的孩子节点，并在异或值最右侧附加一个 1。

- 如果不存在，直接访问具有当前比特值的孩子节点，并在异或值最右侧附加一个 0。

```java [snippet2-Java]
TrieNode trie = new TrieNode();
for (String num : strNums) {
  TrieNode xorNode = trie;
  int currXor = 0;
  for (Character bit : num.toCharArray()) {
    Character toggledBit = bit == '1' ? '0' : '1';
    if (xorNode.children.containsKey(toggledBit)) {
      currXor = (currXor << 1) | 1;
      xorNode = xorNode.children.get(toggledBit);
    } else {
      currXor = currXor << 1;
      xorNode = xorNode.children.get(bit);
    }
  }
}
```

```python [snippet2-Python]
trie = {}
for num in nums:
    xor_node = trie
    curr_xor = 0
    for bit in num:
        opp_bit = 1 - bit
        if opp_bit in xor_node:
            curr_xor = (curr_xor << 1) | 1
            xor_node = xor_node[opp_bit]
        else:
            curr_xor <<= 1
            xor_node = xor_node[bit]
```


**算法** 

算法结构如下所示：

- 在按位字典树中插入数字。

- 找到插入数字在字典树中所能得到的最大异或值。

算法的具体实现如下所示：

- 将所有数字转化成二进制形式。

- 将数字的二进制形式加入字典树，同时计算该数字在字典树中所能得到的最大异或值。再用该数字的最大异或值尝试性更新 `max_xor`。

- 返回 `max_xor`。

**实现** 

```java [solution2-Java]
class TrieNode {
  HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
  public TrieNode() {}
}

class Solution {
  public int findMaximumXOR(int[] nums) {
    // Compute length L of max number in a binary representation
    int maxNum = nums[0];
    for(int num : nums) maxNum = Math.max(maxNum, num);
    int L = (Integer.toBinaryString(maxNum)).length();

    // zero left-padding to ensure L bits for each number
    int n = nums.length, bitmask = 1 << L;
    String [] strNums = new String[n];
    for(int i = 0; i < n; ++i) {
      strNums[i] = Integer.toBinaryString(bitmask | nums[i]).substring(1);
    }

    TrieNode trie = new TrieNode();
    int maxXor = 0;
    for (String num : strNums) {
      TrieNode node = trie, xorNode = trie;
      int currXor = 0;
      for (Character bit : num.toCharArray()) {
        // insert new number in trie  
        if (node.children.containsKey(bit)) {
          node = node.children.get(bit);
        } else {
          TrieNode newNode = new TrieNode();
          node.children.put(bit, newNode);
          node = newNode;
        }

        // compute max xor of that new number 
        // with all previously inserted
        Character toggledBit = bit == '1' ? '0' : '1';
        if (xorNode.children.containsKey(toggledBit)) {
          currXor = (currXor << 1) | 1;
          xorNode = xorNode.children.get(toggledBit);
        } else {
          currXor = currXor << 1;
          xorNode = xorNode.children.get(bit);
        }
      }
      maxXor = Math.max(maxXor, currXor);
    }

    return maxXor;
  }
}
```

```python [solution2-Python]
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # Compute length L of max number in a binary representation
        L = len(bin(max(nums))) - 2
        # zero left-padding to ensure L bits for each number
        nums = [[(x >> i) & 1 for i in range(L)][::-1] for x in nums]
        
        max_xor = 0
        trie = {}
        for num in nums:
            node = trie
            xor_node = trie
            curr_xor = 0
            for bit in num:
                # insert new number in trie
                if not bit in node:
                    node[bit] = {}
                node = node[bit]
                
                # to compute max xor of that new number 
                # with all previously inserted
                toggled_bit = 1 - bit
                if toggled_bit in xor_node:
                    curr_xor = (curr_xor << 1) | 1
                    xor_node = xor_node[toggled_bit]
                else:
                    curr_xor = curr_xor << 1
                    xor_node = xor_node[bit]
                    
            max_xor = max(max_xor, curr_xor)

        return max_xor
```

**复杂度分析**

* 时间复杂度：$O(N)$。在字典树插入一个数的时间复杂度为 $O(L)$，找到一个数的最大异或值时间复杂度也为 $O(L)$。其中 $L = 1 + [\log_2 M]$，M 为数组中的最大数值，这里可以当做一个常量。因此最终时间复杂度为 $O(N)$。

* 空间复杂度：$O(1)$。维护字典树最多需要 $O(2^L) = O(M)$ 的空间，但由于输入的限制，这里的 L 和 M 可以当做常数。