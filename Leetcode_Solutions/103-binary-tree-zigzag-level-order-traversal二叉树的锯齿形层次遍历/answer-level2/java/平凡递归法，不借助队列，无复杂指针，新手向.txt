### 解题思路

![image.png](https://pic.leetcode-cn.com/0b9afe4738f6fec2220903e902a2f049fb17fcfdff07e0c3c06f3c610a9be07e-image.png)
safetyGet：获取嵌套集合的元素，如果超过集合长度，在嵌套集合中插入新集合，并返回它，这个函数会在递归过程中补完最终输出的嵌套集合；

该解有以下注意点：
1、递归过程中只将根元素添加到相应集合中，先递归左子树，结合levelIndex的奇偶性达到判断顺序的目的；
2、终止条件两个，根节点为null返回，如果根节点非null，应当先添加到集合再判断左右子树是否为null;

### 代码

```java
// package com.leetcode.explore.learnCard.topInterviewQuestionsMedium.binaryTreeZigzagLevelOrderTraversal;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    List<List<Integer>> out;

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        out = new ArrayList<>();

        zigzagLevelOrderRecursively(root, 0);

        return out;
    }

    void zigzagLevelOrderRecursively(TreeNode root, int levelIndex) {
        if (root == null) {
            return;
        }

        if (levelIndex % 2 == 0) {
            safetyGet(levelIndex).add(root.val);
        } else {
            safetyGet(levelIndex).add(0, root.val);
        }

        if (root.left == null && root.right == null) {
            return;
        }

        zigzagLevelOrderRecursively(root.left, levelIndex + 1);
        zigzagLevelOrderRecursively(root.right, levelIndex + 1);

    }


    List<Integer> safetyGet(int levelIndex) {
        if (levelIndex > out.size() - 1 || levelIndex < 0) {
            List<Integer> levelList = new ArrayList<>();
            out.add(levelList);
            return levelList;
        }
        return out.get(levelIndex);
    }
}
```