### 解题思路
此处撰写解题思路

### 代码

```java
class MyHashSet {

 class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
			next = null;
		}
	}

	ListNode[] table;
	int length;
	int size;

	/**
	 * 定义大于0.75，扩容2倍，小于0.1缩容2倍
	 */

	/** Initialize your data structure here. */
	public MyHashSet() {
		table = new ListNode[8];
		length = 8;
		size = 0;
	}

	public void add(int key) {
		int hash = key % length;
		if (table[hash] == null) {
			table[hash] = new ListNode(key);
			size++;
		} else {
			ListNode node = table[hash];

			boolean isSame = false;
			if (node.val == key) {
				isSame = true;
			} else {
				while (node.next != null) {
					if (node.next.val == key) {
						isSame = true;
						break;
					}
					node = node.next;
				}
			}
			if (!isSame) {
				node.next = new ListNode(key);
				size++;
			}
		}
		resize();
	}

	public void resize() {
		double rate = Double.valueOf(size) / Double.valueOf(length);
		ListNode[] newTable = null;
		if (rate > 0.75) {
			newTable = new ListNode[length * 2];
			length = length * 2;
		}
		if (rate < 0.1) {
			newTable = new ListNode[length / 2];
			length = length / 2;
		}

		if (rate > 0.75 || rate < 0.1) {
			for (int i = 0; i < table.length; i++) {
				ListNode node = table[i];
				while (node != null) {
					int hash = node.val % length;
					if (newTable[hash] == null) {
						newTable[hash] = new ListNode(node.val);
					} else {
						ListNode temp = newTable[hash];
						while (temp.next != null) {
							temp = temp.next;
						}
						temp.next = new ListNode(node.val);

					}
					node = node.next;
				}
			}
			table = newTable;
		}

	}

	public void remove(int key) {
		int hash = key % length;
		if (table[hash] == null) {
			return;
		} else {
			ListNode node = table[hash];

			if (node.val == key) {
				table[hash] = table[hash].next;
				size--;
			} else {
				while (node.next != null) {
					if (node.next.val == key) {
						node.next = node.next.next;
						size--;
						return;
					}
					node = node.next;
				}
			}

		}
		resize();

	}

	/** Returns true if this set contains the specified element */
	public boolean contains(int key) {
		int hash = key % length;
		if (table[hash] == null) {
			return false;
		} else {
			ListNode node = table[hash];

			while (node != null) {
				if (node.val == key) {
					return true;
				}
				node = node.next;
			}

		}

		return false;

	}

}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```