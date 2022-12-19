Java
```
class MapSum {

    class Node {
        int val;
        int sum;
        boolean end;
        Node[] nexts = new Node[26];
    }
    Node root;
    public MapSum() {
        root = new Node();
    }
    
    public void insert(String key, int val) {
        Node preNode = find(key);
        int preval = preNode == null ? 0 : preNode.val;
        val -= preval;
        Node node = root;      
        node.sum +=  val;
        
        for(int i = 0; i < key.length(); i++) {
            int index = key.charAt(i) - 'a';
            if(node.nexts[index] == null) {
                node.nexts[index] = new Node();
            }
            
            node = node.nexts[index];
            node.sum += val;
        }
        node.val = val;
        node.end = true;
    }
    
    public int sum(String prefix) {
        Node node = find(prefix);
        return node == null ? 0 : node.sum;
    }
    
    public Node find(String prefix) {
        Node node = root;
        for(int i = 0; i < prefix.length(); i++) {
            int index = prefix.charAt(i) - 'a';
            if(node.nexts[index] == null) {
                return null;
            }
            node = node.nexts[index];
        }
        return node;
    }
}
```
golang
```
// 在插入word时, 把路径上的点的sum累加上当前val
type Node struct {
	val int
	sum int
	nexts [26]*Node
}
type MapSum struct {
	root *Node
}


/** Initialize your data structure here. */
func Constructor() MapSum {
	return MapSum{
		root : &Node {
			nexts : [26]*Node{},
		},
	}
}


func (this *MapSum) getNode(key string) *Node {
	var index int
	cur := this.root
	for _, v := range key {
		index = int(v - 'a')
		if cur.nexts[index] == nil {
			return nil
		}
		cur = cur.nexts[index]
	}
	return cur
}


func (this *MapSum) Insert(key string, val int)  {
	preVal := 0
	if preNode := this.getNode(key); preNode != nil {
		preVal = preNode.val
	}

	val = val - preVal
	var index int
	cur := this.root
	for _, v := range key {
		index = int(v - 'a')
		if cur.nexts[index] == nil {
			cur.nexts[index] = &Node{nexts : [26]*Node{},}
		}
		cur = cur.nexts[index]
		cur.sum += val
	}
	cur.val = val
}


func (this *MapSum) Sum(prefix string) int {
	node := this.getNode(prefix)
	if node != nil {
		return node.sum
	}
	return 0
}
```

