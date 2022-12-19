思路：官方给的时间复杂度比较高，达到了`O(m * n ^ 2)`, m 为字符串的个数。满足理论时间复杂度要求的做法是字典树，建树需要`O(m * n)`, 匹配需要`(n ^ 2)`,总的时间复杂度为`O(n * (m + n))`,典型的空间换时间思想 
```
class Solution {

    private class Node{
        Node[] childs = new Node[256];
        boolean isLeaf;
    }

    private Node root;

    public String addBoldTag(String s, String[] dicts) {
        root = new Node();
        for(String dict: dicts){
            Node node = root;
            for(char c: dict.toCharArray()){
                if(node.childs[c] == null){
                    node.childs[c] = new Node();
                }
                node = node.childs[c];
            }
            node.isLeaf = true;
        }
        int n = s.length();
        boolean[] label = new boolean[n];
        for(int i = 0 ; i < n ; i++){
            Node node = root;
            int cnt = 0, maxValidCnt = 0;
            for(int j = i; j < n; j++){
                if(node.childs[s.charAt(j)] == null){
                    break;
                }
                cnt++;
                node = node.childs[s.charAt(j)];
                if(node.isLeaf){
                    maxValidCnt = cnt;
                }
            }
            for(int j = i; j < i + maxValidCnt; j++){
                label[j] = true;
            }
        }
        StringBuilder res = new StringBuilder();
        int id = 0;
        while(id < n){
            if(!label[id]){
                res.append(s.charAt(id++));
            } else {
                res.append("<b>");
                while(id < n && label[id]){
                    res.append(s.charAt(id++));
                }
                res.append("</b>");
            }
        }
        return res.toString();
    }
}
```