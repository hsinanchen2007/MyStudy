### 解题思路
![image.png](https://pic.leetcode-cn.com/1b2b5e778d0a40d68ea6b1084b8a0189cf01933bafb755bdd54f8b7e5e04a933-image.png)

序列化相对容易理解，就是拼一个唯一字符串；
解序列就是从序列化的字符串中递归拆出三个部分：根节点字符串，左树序列化字符串，右树序列化字符串。。

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function (root) {
    if (!root) {
        return ".";
    }
    return `${root.val}<${serialize(root.left)}>${serialize(root.right)}`;

};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function (data) {
    if (data.length === 0 || data === ".") return null;

    let numStr = "",
        root = new TreeNode(),
        bal = 0,
        leftIdx = 0,
        rightIdx = 0,
        leftTreeSer = "",
        rightTreeSer = "";

    for (let i = 0; i < data.length; i++) {
        if (data[i] === "<" || data[i] === ">") {
            if (numStr != "END") {
                if (numStr != ".") {
                    root.val = parseInt(numStr);
                } else {
                    return root;
                }
                numStr = "END";
            }

            if (data[i] === "<") {
                bal++;
                if (leftIdx === 0) leftIdx = i + 1;
            } else if (data[i] === ">") {
                bal--;
            }

            if (bal === 0 && rightIdx === 0) rightIdx = i + 1;

        } else if (numStr != "END") {
            numStr += data[i];
        }
    }
    leftTreeSer = data.substring(leftIdx, rightIdx - 1);
    rightTreeSer = data.substring(rightIdx, data.length);

    root.left = deserialize(leftTreeSer);
    root.right = deserialize(rightTreeSer);

    return root;
};


/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */
```