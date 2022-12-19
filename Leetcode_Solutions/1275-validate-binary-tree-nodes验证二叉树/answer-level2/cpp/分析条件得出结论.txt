### 解题思路
这道题需要满足的条件：
1. 任一节点不能有多个父节点；
2. 有一个节点没有父节点。
只要满足这两个条件，就能满足题设，因此我们使用一个哈希表来追踪已经有父节点的元素，并在最终结束后统计哈希表内的元素个数，就可以做出判断了。

### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, bool> mp;
        for (int i=0; i<n; i++) {
            if (leftChild[i] != -1 && mp.find(leftChild[i]) != mp.end() || rightChild[i] != -1 && mp.find(rightChild[i]) != mp.end()) return false;
            if (leftChild[i] != -1) mp[leftChild[i]] = true;
            if (rightChild[i] != -1) mp[rightChild[i]] = true;
        }
        if (mp.size() != n-1) return false;
        return true;
    }
};
```