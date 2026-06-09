```java
class Solution {

    private class Node {
        Node[] childs = new Node[26];
        boolean isLeaf = false;
    }

    private Node root;

    public int respace(String[] dictionary, String sentence) {
        root = new Node();
        for(String word: dictionary){
            addWord(word);
        }
        int n = sentence.length();
        int[] dp = new int[n + 1];
        for(int i = n - 1; i >= 0 ; i--){
            Node node = root;
            dp[i] = n - i;
            for(int j = i; j < n; j++){
                char c = sentence.charAt(j);
                if(node.childs[c - 'a'] == null){
                    dp[i] = Math.min(dp[i], j - i + 1 + dp[j + 1]);
                    break;
                }
                node = node.childs[c - 'a'];
                dp[i] = Math.min(dp[i], node.isLeaf ? dp[j + 1] : j - i + 1 + dp[j + 1]);
            }
        }
        return dp[0];
    }

    private void addWord(String word){
        Node node = root;
        for(char c: word.toCharArray()){
            if(node.childs[c - 'a'] == null){
                node.childs[c - 'a'] = new Node();
            }
            node = node.childs[c - 'a'];
        }
        node.isLeaf = true;
    }
}
```