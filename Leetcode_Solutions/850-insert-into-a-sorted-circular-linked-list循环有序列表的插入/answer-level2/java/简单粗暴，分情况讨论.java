### 解题思路
此处撰写解题思路

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
   public Node insert(Node head, int insertVal) {
		Node targetNode = new Node(insertVal);
		if (head == null) {
			targetNode.next = targetNode;
			return targetNode;
		}
		Node tmp = head;
		Map<Node, Integer> cycleMap = new HashMap<>();
		while (true) {
			if (cycleMap.containsKey(tmp)) {
				break;
			}
			cycleMap.put(tmp, tmp.val);
			tmp = tmp.next;
		}
		List<Integer> nodeValList = new ArrayList<>(cycleMap.values());
		if (new HashSet<>(nodeValList).size() == 1) {
			targetNode.next = head.next;
			head.next = targetNode;
			return head;
		}
		Collections.sort(nodeValList);
		int minVal = nodeValList.get(0);
		int maxVal = nodeValList.get(nodeValList.size() - 1);
		tmp = head;
		if (insertVal < minVal) {
			while (true) {
				if (tmp.val > minVal && tmp.next.val == minVal) {
					break;
				}
				tmp = tmp.next;
			}
		} else if (insertVal > maxVal) {
			while (true) {
				if (tmp.val == maxVal && tmp.next.val < maxVal) {
					break;
				}
				tmp = tmp.next;
			}
		} else {
			while (true) {
				if (tmp.val <= insertVal && tmp.next.val >= insertVal) {
					break;
				}
				tmp = tmp.next;
			}
		}
		targetNode.next = tmp.next;
		tmp.next = targetNode;
		return head;
	}
}
```