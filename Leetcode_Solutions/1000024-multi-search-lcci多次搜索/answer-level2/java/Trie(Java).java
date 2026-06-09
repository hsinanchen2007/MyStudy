```java
// time complexity O(n ^ 2)
class Solution {

    private class Node {
        Node[] childs = new Node[26];
        boolean isLeaf = false;
        int id = 0;
    }

    private Node root;

    public int[][] multiSearch(String big, String[] smalls) {
        root = new Node();
        int n = smalls.length;
        List<Integer>[] res = new List[n];
        for(int i = 0 ; i < n ; i++){
            res[i] = new ArrayList<>();
        }
        for(int i = 0 ; i < smalls.length; i++){
            addWord(smalls[i], i);
        }
        outer:
        for(int i = 0 ; i < big.length(); i++){
            Node node = root;
            for(int j = i ; j < big.length(); j++){
                char c = big.charAt(j);
                if(node.childs[c - 'a'] == null){
                    continue outer;
                }
                node = node.childs[c - 'a'];
                if(node.isLeaf){
                    res[node.id].add(i);
                }
            }
        }
        int[][] resArray = new int[n][];
        for(int i = 0 ; i < n ; i++){
            resArray[i] = new int[res[i].size()];
            for(int j = 0 ; j < resArray[i].length; j++){
                resArray[i][j] = res[i].get(j);
            }
        }
        return resArray;
    }

    private void addWord(String word, int id){
        Node node = root;
        for(char c: word.toCharArray()){
            if(node.childs[c - 'a'] == null){
                node.childs[c - 'a'] = new Node();
            }
            node = node.childs[c - 'a'];
        }
        node.isLeaf = true;
        node.id = id;
    }
}
```