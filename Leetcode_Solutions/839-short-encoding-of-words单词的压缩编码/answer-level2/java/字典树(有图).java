### 解题思路
一直没想好思路，直到看到答案。。。我是真的菜。还是画图比较好懂：
![leetcode820.jpg](https://pic.leetcode-cn.com/53e363baa4f8dc0b39f91f6eb593ac4f80fb9136d3b70e778afdc03850dfd94b-leetcode820.jpg)

里面的每个长条都是capacity为26，可能画得有点不等长，不要介意哈。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Node root = new Node();
        Map<Node,Integer> nodes = new HashMap();
        for(int i=0;i<words.length;i++){
            String word = words[i];
            Node curNode = root;
            for(int j=word.length()-1;j>=0;j--){
                curNode = curNode.get(word.charAt(j));
            }
            nodes.put(curNode,i);
        }
        int ans=0;
        for(Node node:nodes.keySet()){
            if(node.count==0)
                ans += words[nodes.get(node)].length()+1;
        }
        return ans;
    }


}
class Node{
    Node[] nextNode;
    int count;
    Node(){
        nextNode = new Node[26];
        count = 0;
    }
    public Node get(char c){
        if(nextNode[c-'a']==null){
            nextNode[c-'a'] = new Node();
            count++;
        }
        return nextNode[c-'a'];
    }
}
```