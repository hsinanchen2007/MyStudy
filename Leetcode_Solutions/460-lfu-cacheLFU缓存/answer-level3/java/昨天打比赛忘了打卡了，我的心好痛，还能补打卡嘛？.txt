### 解题思路
此处撰写解题思路

### 代码

```java
class LFUCache {
ArrayList<Pair<Integer, Pair<Integer, Integer>>> list;
	int size;
	int capacity;

	public LFUCache(int capacity) {
		size = 0;
		this.capacity = capacity;
		list = new ArrayList<Pair<Integer, Pair<Integer, Integer>>>();
	}

	public int get(int key) {
		Pair<Integer, Integer> tempPair = null;
		for (Pair<Integer, Pair<Integer, Integer>> p : list) {
			if ((int) p.getKey() == key) {
				tempPair = p.getValue();
				list.remove(p);
				list.add(new Pair<Integer, Pair<Integer, Integer>>(key,
						new Pair<Integer, Integer>(tempPair.getKey(), tempPair
								.getValue() + 1)));
				break;
			}
		}
		if (tempPair == null) {
			return -1;
		}

		return tempPair.getKey();

	}

	public void put(int key, int value) {
		Pair<Integer, Integer> keyTemp = ContainOrNot(key);
		if (keyTemp != null) {
			list.add(new Pair<Integer, Pair<Integer, Integer>>(key,
					new Pair<Integer, Integer>(value, keyTemp.getValue() + 1)));
		}

		else {
			if (size < capacity) {
				list.add(new Pair<Integer, Pair<Integer, Integer>>(key,
						new Pair<Integer, Integer>(value, 0)));
				size++;
			} else if (capacity>0&&size == capacity) {
				removeOneFromList();
				list.add(new Pair<Integer, Pair<Integer, Integer>>(key,
						new Pair<Integer, Integer>(value, 0)));

			}

		}

	}

	private void removeOneFromList() {
		int min=Integer.MAX_VALUE;
		for(Pair<Integer, Pair<Integer, Integer>> p:list){
			min=Math.min(p.getValue().getValue(), min);
		}
		for(Pair<Integer, Pair<Integer, Integer>> p:list){
			if(p.getValue().getValue()==min){
				list.remove(p);
				return ;
			}
		}
		
	}

	private Pair<Integer, Integer> ContainOrNot(int key) {
		Pair<Integer, Integer> temp = null;
		for (Pair<Integer, Pair<Integer, Integer>> p : list) {
			if ((int) p.getKey() == key) {
				temp = p.getValue();
				list.remove(p);
				break;
			}
		}
		return temp;
	}
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```