最简单的方法 就是直接用linkedList 去构造.


class MyHashSet {

 private List<LinkedList<Integer>> bucket;

	private static final int initSize = 15;

	private int size = 0;

	private int addSize = 10;
    
   

   

	/**
	 * Initialize your data structure here.
	 */

	public MyHashSet() {
		bucket = new ArrayList<LinkedList<Integer>>();
		for (int i = 0; i < initSize; i++) {
			bucket.add(new LinkedList<Integer>());
		}
		size = initSize;
	}

	public void add(int key) {
		if (!contains(key)) {
			if (bucket.size()<size&&bucket.size() >=size*0.8) {
				for (int i = 0; i < addSize; i++) {
					bucket.add(new LinkedList<Integer>());
				}
				size  += addSize;
			}
			bucket.get(key % size).add(key);
		}
	}

	public void remove(int key) {
		if (contains(key)) {
			bucket.get(key % size).removeFirstOccurrence(key);
		}
	}

	/**
	 * Returns true if this set contains the specified element
	 */
	public boolean contains(int key) {
		LinkedList<Integer> linkedList = bucket.get(key % size);
		for (Integer i : linkedList) {
			if (i == key) {
				return true;
			}
		}

		return false;
	}
}
