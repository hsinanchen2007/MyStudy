## 说明
官方的题解只给了c++的哈希表+平衡二叉树的实现，我照着c++的实现方法写了一个java版本的，萌新第一次尝试写题解(T T)有错误的地方，还请大佬指出(Orz)

## 主要思路
首先建立一个节点类Node, 定义如下
```
class Node implements Comparable<Node>{
	int key;
	int value;
	//表示出现的频率
	int cnt;
	//表示出现的时间
	int time;
	
	@Override
    //当频率一样的时候,比较时间,否则比较频率
	public int compareTo(Node n) {
		if(this.cnt == n.cnt) {
			return time - n.time;
		}else {
			return cnt - n.cnt;
		}
	}
	public Node(int key, int value, int cnt, int time) {
		this.key = key;
		this.value = value;
		this.cnt = cnt;
		this.time = time;
	}
	

}
```
利用`key, value`来记录添加的key和value，用`cnt`记录操作的次数,用`time`记录添加的时间

根据官方的题解，用HashMap来记录缓存，用`key`作为HashMap的key。用TreeSet来记录添加缓存的先后和频率,根据cnt和time来进行排序，所以要复写compareTo。

- `get(key)`这个比较直观，如果HashMap中有相应的key直接返回，并且要更新TreeSet中相应Node的cnt和time，否则返回-1
```
	public int get(int key) {
		if(capacity == 0) {
			return -1;
		}
		Node node = map.get(key);
		//没有该节点
		if(node == null) {
			return -1;
		}
		//存在该节点的话,先删除原来的旧的缓存
		ts.remove(node);
		node.time = ++time;
		node.cnt += 1;
		ts.add(node);
		map.put(key, node);
		
		return node.value;
	}
```
- `put(key, value)`的思路就是先查看HashMap是否已经存在当前的`key`如果存在key的话，相当与更新与`key`相关的节点即可。如果是新的节点的话，则需要先查看是否容量已经满了，如果满的话，则需要根据`TreeSet`中的最左边的节点来确定删除HashMap中那个节点。然后在HashMap和TreeSet中更新数据。
```
public void put(int key, int value) {
		if(capacity == 0) return;
		Node node = map.get(key);
		// 该节点是新节点
		if(node == null) {
			if(map.size() == capacity) {//缓存达到容量上限
				Node f = ts.first();
				map.remove(f.key);
				ts.remove(f);
				
			}
			Node cache = new Node(key, value, 1, ++time);
			map.put(key, cache);
			ts.add(cache);
			
			
		}else {//该节点已经存在
			ts.remove(node);
			node.time = ++time;
			node.cnt += 1;
			node.value = value;
			ts.add(node);
			map.put(key, node);
		}
```

## java全部代码
```
class Node implements Comparable<Node>{
	int key;
	int value;
	//表示出现的频率
	int cnt;
	//表示出现的时间
	int time;
	
	@Override
	public int compareTo(Node n) {
		if(this.cnt == n.cnt) {
			return time - n.time;
		}else {
			return cnt - n.cnt;
		}
	}
	public Node(int key, int value, int cnt, int time) {
		this.key = key;
		this.value = value;
		this.cnt = cnt;
		this.time = time;
	}
	

}
class LFUCache {
	int capacity;
	Map<Integer, Node> map;
	TreeSet<Node> ts;
	int time;
	
	public LFUCache(int capacity) {
		this.capacity = capacity;
		map = new HashMap<>();
		ts = new TreeSet<>();
		time = 0;
	}
	
	public int get(int key) {
		if(capacity == 0) {
			return -1;
		}
		Node node = map.get(key);
		//没有该节点
		if(node == null) {
			return -1;
		}
		//存在该节点的话,先删除原来的旧的缓存
		ts.remove(node);
		node.time = ++time;
		node.cnt += 1;
		ts.add(node);
		map.put(key, node);
		
		return node.value;
	}
	
	public void put(int key, int value) {
		if(capacity == 0) return;
		Node node = map.get(key);
		// 该节点是新节点
		if(node == null) {
			if(map.size() == capacity) {//缓存达到容量上限
				Node f = ts.first();
				map.remove(f.key);
				ts.remove(f);
				
			}
			Node cache = new Node(key, value, 1, ++time);
			map.put(key, cache);
			ts.add(cache);
			
			
		}else {//该节点已经存在
			ts.remove(node);
			node.time = ++time;
			node.cnt += 1;
            node.value = value;
			ts.add(node);
			map.put(key, node);
		}
		
	}
}
```


## 复杂度
- 时间复杂度：`get`和`put`的时间复杂度都是*O*(logn)，是由于平衡二叉树引起的
- 空间复杂度：*O*(capacity)


