### 解题思路
字典树

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (s1, s2)->(s2.length() - s1.length()));
        int result = 0;
        Tries root = new Tries();
        for (String word : words) {
            result += root.insert(word);
        }
        return result;
    }
}
class TreeNode {
    int val;
    TreeNode[] node = new TreeNode[26];

    public TreeNode() {}
}

class Tries {
    TreeNode root;

    public Tries() {
        root = new TreeNode();
    }

    public int insert(String s) {
        TreeNode cur = root;
        boolean isNew = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            int num = s.charAt(i) - 'a';
            if (cur.node[num] == null) {
                cur.node[num] = new TreeNode();
                isNew = true;
            }
            cur = cur.node[num];
        }
        return isNew == true ? s.length() + 1 : 0;
    }
}
```