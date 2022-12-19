![Screen Shot 2020-01-03 at 8.15.04 PM.png](https://pic.leetcode-cn.com/1751fc6eac97c04aa1291ee6de94bbf3379c9b3ca3fd1617b0beb2a96ab3c38a-Screen%20Shot%202020-01-03%20at%208.15.04%20PM.png)

## 解题思路
该方法有如下三个关键点：
- 什么情况下我们处理的是左节点
- 什么情况下处理的是右节点
- 如何进行子节点和父节点的连接

#### 情况(a)
如果我们处理的是"..)(.."，如下图所示，我们需要将当前节点作为left node处理。
![536-1.jpg](https://pic.leetcode-cn.com/ceaca64cb90cf1683810eb8904e245a4ffb8176919687702aff01a12ab841d03-536-1.jpg)


#### 情况(b)
如果处理的是..))"，那么我们需要check parent的`left`数据成员和`right`数据成员，来决定当前是left node还是right node。优先将当前节点视为左节点。另外由于"..))"是一个节点的结束，我们需要“再往上一层进行连接”，也就是把`parent`和`grand`连接起来。
![536-b.jpg](https://pic.leetcode-cn.com/d15ff7ce1c1ecf11c982edc1c753a8c6f3e7df2cbadbf547de1c09db827b4cad-536-b.jpg)


#### 情况(c)
如果处理的是"..)"，而且我们已经到了字符串结尾，同情况(b)。

#### 情况(d)
如果我们处理的是"num).."或者"num(.."，创建一个新的节点并将其压栈。

## 代码

```cpp
class Solution {
public:
  TreeNode *str2tree(string s) {
    if (s.empty())
      return nullptr;
    vector<TreeNode *> stack;
    size_t i = s.find("(");

    // Fill the root node.
    TreeNode *root = nullptr;
    if (i != string::npos) {
      root = new TreeNode(stoi(s.substr(0, i)));
      stack.push_back(root);
    } else {
      root = new TreeNode(stoi(s));
      return root;
    }

    // Handle the remain string.
    for (; i < s.size(); ++i) {
      if (s[i] == '(') {
        // (d) consume the characters and convert it to numbers.
        int j = ++i;
        while (s[j] != '(' && s[j] != ')')
          j++;
        TreeNode *node = new TreeNode(stoi(s.substr(i, j - i)));
        stack.push_back(node);
        i = j - 1;
      } else if (s[i] == ')') {
        if (i < s.size() - 1) {
          if (s[i + 1] == '(') {
            // (a) For "...)(..", this is definitely left node.
            // Pop back and assign it to parent->left.
            auto left = stack.back();
            stack.pop_back();
            stack.back()->left = left;
          } else if (s[i + 1] == ')') {
            // (b) "..))" means the end of some node.
            auto node = stack.back();
            stack.pop_back();
            // However, we have to check parent's `left` and `right` to decide
            // which subtree we are located in.
            if (stack.back()->left == nullptr) {
              stack.back()->left = node;
            } else if (stack.back()->right == nullptr) {
              stack.back()->right = node;
            }

            // Since "..))" is the end of some node, we should connect the node
            // to the parent.
            auto father = stack.back();
            stack.pop_back();
            if (!stack.empty()) {
              if (stack.back()->left == nullptr) {
                stack.back()->left = father;
              } else if (stack.back()->right == nullptr) {
                stack.back()->right = father;
              }
            }
            // Since we look ahead one character, ++i.
            i++;
          }
        } else {
          // (c) Arrive at the end of the string, "..num)".
          auto node = stack.back();
          stack.pop_back();
          // Check parent's `left` and `right` to decide which subtree we are
          // locate in.
          if (stack.back()->left == nullptr) {
            stack.back()->left = node;
          } else if (stack.back()->right == nullptr) {
            stack.back()->right = node;
          }
        }
      }
    }
    return root;
  }
};
```