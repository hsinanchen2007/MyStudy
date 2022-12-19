### 解题思路
代码很简单，见注释

### 代码

```java
class Solution {
    private static class Node{
        char val; // 字符
        int height; // 头节点到当前节点的长度
        boolean end; // 当前节点是否为某个word的结尾
        String word; // 以当前节点结尾表示的字符串
        TreeMap<Character, Node> next;
        public Node(char val, int height, boolean end, String word){
            this.val = val;
            this.height = height;
            this.end = end;
            this.word = word;
            next = new TreeMap<>();
        }
    }

    // 建立前缀树，返回头节点
    private Node build(String[] words){
        Node head = new Node('0', 0, false, "");
        for(String word: words){
            // 为每个单词建分支
            char[] arr = word.toCharArray();
            Node n = head;
            for(int i = 0; i < arr.length; i++){
                // 如果当前节点不能往下走到arr[i]字符，则为arr[i]新建节点
                if(!n.next.containsKey(arr[i])){
                    Node node = new Node(arr[i], i + 1, false, word.substring(0, i + 1));
                    n.next.put(arr[i], node);
                }
                // 往下走
                n = n.next.get(arr[i]);
                // 如果走到word的最后一个字符，标记该节点的end为true
                if(i == arr.length - 1)
                    n.end = true;
            }
        }
        return head;
    }

    // 宽度优先遍历
    public String longestWord(String[] words) {
        Node head = build(words);
        Node ans = head;
        Queue<Node> q = new LinkedList<>();
        q.add(head);
        while(!q.isEmpty()){
            Node n = q.poll();
            Iterator<Map.Entry<Character, Node>> it = n.next.entrySet().iterator();
            while(it.hasNext()){
                Map.Entry<Character, Node> next = it.next();
                // 只有下层节点的end为true，才可能往下走
                if(next.getValue().end){
                    q.add(next.getValue());
                }
            }
            // next是有序表组织的，每层的第一个节点字典序最小，答案必来源于它
            if(n.height > ans.height){
                ans = n;
            }
        }
        return ans.word;
    }
}
```