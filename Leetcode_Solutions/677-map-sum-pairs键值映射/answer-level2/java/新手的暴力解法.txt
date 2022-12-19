### 解题思路
此处撰写解题思路

### 代码

```java
class MapSum {
    // 准备用前缀树的方法解决
    // 定义节点类
    private class Node{
        // 默认节点sum属性为0
        int sum = 0;
        Node[] childs = new Node[26];
    }

    // 定义根
    private Node root;
    // 需要一个哈希表, 用来记录已经加入过的字符串
    private HashMap<String, Integer> map;

    /** Initialize your data structure here. */
    public MapSum() {
        root = new Node();
        map = new HashMap<>();
    }
    
    public void insert(String key, int val) {
        // 分两种情况
        if(map.containsKey(key)){
            int oldVal = map.get(key);
            insert(key, val - oldVal, root);
            map.put(key, val);
        }
        else{
            insert(key, val, root);
            map.put(key, val);
        }    
    }
    private void insert(String key, int val, Node node){
        if(node == null){
            return;
        }
        if(key.length() == 0){
            node.sum += val;
            return;
        }
        node.sum += val;
        int index = indexForChar(key.charAt(0));
        if(node.childs[index] == null){
            node.childs[index] = new Node();
        }
        insert(key.substring(1), val, node.childs[index]);
    }
    
    public int sum(String prefix) {
        return sum(prefix, root);
    }
    private int sum(String prefix, Node node){
        if(node == null){
            return 0;
        }
        if(prefix.length() == 0){
            return node.sum;
        }

        int index = indexForChar(prefix.charAt(0));
        return sum(prefix.substring(1), node.childs[index]);
    }


    private int indexForChar(char c){
        return c - 'a';
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
```