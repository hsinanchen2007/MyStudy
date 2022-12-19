### 解题思路
我们考虑使用ELFhash算法对节点进行哈希，同时增加了magic number消除同值节点的影响，避免了序列化和计算序列化字符串的开销，时间复杂度O(N)，对于每一个节点仅访问了一次，空间复杂度O(N)，一个是维护哈希表的开销，另一个是递归栈的开销。
![2020-02-29 (2).png](https://pic.leetcode-cn.com/a70f886ddfebf4d2066a74ca4ca99865fa186a4c98147ab70bb3e25becc000df-2020-02-29%20\(2\).png)
具体有关ELFhash的原理和证明本篇不加多介绍，关注代码和注释即可。


### 代码

```cpp
class Solution {
private:
    // 哈希表查询
    unordered_map<size_t, pair<int, TreeNode*>> hashtable;
    // 获取节点哈希（非字符串算法）
    size_t getHash(TreeNode* node) {
        // 空节点，返回一个*不常见*的常数值（理论上除0外的任意值，但是二进制数越乱越好，这个值将会是后面进行哈希运算的一个初值）
        if (node == nullptr) return -23333333;
        // 获取左右节点的哈希值
        size_t left = getHash(node->left);
        size_t right = getHash(node->right);
        // 获取当前节点的值，转为unsigned
        // 因为我们的hash算法只关心储存的二进制值，所以符号已经不重要了，另外接下来会有左移位和右移位操作，符号会带来很大的影响（例如负数移位补1而不是补0）
        unsigned int tmp = (unsigned int)node->val;

        // 最核心的magic number，随便选了一堆数字，居然work了！
        // tmp （也就是所有的节点值）如果一直为一个数的话，会导致后面节点哈希值撞车，而且非常严重（以至于把最后一个边缘的case给撞出来了TAT 错了三次啊三次ORZ）
        tmp += (left + right) * 23333 % 1135306736;

        // 接下来每一个while都是一次ELFhash，致敬大神！
        // 相当于把left, right, tmp都当作一个8/4字节的字符串进行hash操作
        // 即实际上我们在对一个20字节长度的字符串做hash
        // 换句话说，本篇代码依旧是序列化，只不过采用了自己的hash算法而已
        size_t cur = 0, x = 0;
        while (left) {
            cur = (cur << 4) + (left & 0xff);
            if ((x = cur & 0xf000000000000000) != 0) {
                cur ^= (x >> 56);
                cur &= ~x;
            }
            left >>= 8;
        }
        while (right) {
            cur = (cur << 4) + (right & 0xff);
            if ((x = cur & 0xf000000000000000) != 0) {
                cur ^= (x >> 56);
                cur &= ~x;
            }
            right >>= 8;
        }
        while (tmp) {
            cur = (cur << 4) + (tmp & 0xff);
            if ((x = cur & 0xf000000000000000) != 0) {
                cur ^= (x >> 56);
                cur &= ~x;
            }
            tmp >>= 8;
        }
        
        // 最后将hash记入table
        if (hashtable.count(cur) > 0) {
            hashtable[cur].first++;
        } else {
            hashtable[cur] = make_pair(1, node);
        }
        return cur;
    }
public:
    // 常规操作
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getHash(root);
        vector<TreeNode*> ret;
		for(auto& each: hashtable) {
            // 将计数大于1的推入返回值
			if (each.second.first > 1) {
				ret.push_back(each.second.second);
			}
		}
        return ret;
    }
};
```