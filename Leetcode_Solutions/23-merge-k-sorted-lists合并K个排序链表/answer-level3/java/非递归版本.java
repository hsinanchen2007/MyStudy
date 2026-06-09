能不用递归就不用递归，毕竟栈帧就2M大很容易爆栈。本题其实是分治，分治到最细粒度都是两两合并再回溯，所以可以直接两两合并。

Java
```
	public IntNode T23(IntNode[] intNodes) {
        if (intNodes == null || intNodes.length == 0) return null;
        //分治到最细粒度也就是两个链表合并，所以直接两两合并即可
        List<IntNode> res = new ArrayList<>(intNodes.length);
        for (IntNode intNode : intNodes) {
        	res.add(intNode);
        }
        //一直两两合并，奇数时最后的1个不合并，扔到下一轮继续合并
        while (res.size() != 1) {
        	List<IntNode> temp = new ArrayList<>();
        	for (int i = 0, size = res.size() - 1; i < size; i += 2) {
        		//这里可以调用21题的方法了，注释我不写了，回去看21题
        		IntNode first = new IntNode(-1), second = first;
        		IntNode node1 = res.get(i), node2 = res.get(i + 1);
        		while (node1 != null && node2 != null) {
        			if (node1.value <= node2.value) {
        				second.next = node1;
        				node1 = node1.next;
        			} else {
        				second.next = node2;
        				node2 = node2.next;
        			}
        			second = second.next;
        		}
        		second.next = node1 == null ? node2 : node1;
        		temp.add(first.next);
        	}
        	//如果是奇数，最后会多一个，丢进去继续处理
        	if (res.size() > temp.size() * 2) {
        		temp.add(res.get(res.size() - 1));
    		}
        	res = temp;
        }
        return res.get(0);
    }
```
JavaScript
```
function(nodes) {
    if (nodes == null || nodes.length == 0) return null;
    //分治到最细粒度也就是两个链表合并，所以直接两两合并即可
    //一直两两合并，奇数时最后的1个不合并，扔到下一轮继续合并
    while (nodes.length != 1) {
    	var temp = [];
    	for (var i = 0, length = nodes.length - 1; i < length; i += 2) {
    		//这里可以调用21题的方法了，注释我不写了，回去看21题
    		var first = {'val': -1}, second = first;
    		var node1 = nodes[i], node2 = nodes[i + 1];
    		while (node1 != null && node2 != null) {
    			if (node1.val <= node2.val) {
    				second.next = node1;
    				node1 = node1.next;
    			} else {
    				second.next = node2;
    				node2 = node2.next;
    			}
    			second = second.next;
    		}
    		second.next = node1 == null ? node2 : node1;
    		temp.push(first.next);
    	}
    	//如果是奇数，最后会多一个，丢进去继续处理
    	if (nodes.length > temp.length * 2) {
    		temp.push(nodes[nodes.length - 1]);
		}
    	nodes = temp;
    }
    return nodes[0];
}
```


![1.png](https://pic.leetcode-cn.com/c7d98e8bf384a503a21ac560458516e72811702fa164879fff1dd0d3ad29cfc0-1.png)
![2.png](https://pic.leetcode-cn.com/17fbf68692d2c092a1173c2c037a72004129f0da4a5937251384ead5c189ff4f-2.png)
