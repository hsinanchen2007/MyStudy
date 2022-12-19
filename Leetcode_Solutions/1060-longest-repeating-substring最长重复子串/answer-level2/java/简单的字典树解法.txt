想法：构建从各个位置开始的子串的字典树，一旦发现某个位置已经被创建过，则说明重复，应该更新结果，以此类推，很简单。时间复杂度为O(n ^ 2)
```
class Solution {

    private class Node{
        Node[] childs = new Node[26];
    }

    private Node root;

    public int longestRepeatingSubstring(String s) {
        int max = 0;
        int n = s.length();
        root = new Node();
        for(int i = 0; i < n ; i++){
            Node node = root;
            for(int j = i ; j < n; j++){
                int index = s.charAt(j) - 'a';
                if(node.childs[index] != null){
                    max = Math.max(max, j - i + 1);
                } else {
                    node.childs[index] = new Node();
                }
                node = node.childs[index];
            }
        }
        return max;
    }
}
```