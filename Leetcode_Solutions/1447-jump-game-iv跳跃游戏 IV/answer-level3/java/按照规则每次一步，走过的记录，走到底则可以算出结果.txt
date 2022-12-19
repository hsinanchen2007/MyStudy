### 解题思路
每次一步，走过的记录，走到底则可以算出结果

### 代码

```java
class Solution {
    //向前推演异步：1.找相同，2.找前后
	private Set<Integer> stepOne(int[] arr, int k, int[] store, Map<Integer, List<Integer>> m) {
		Set<Integer> l = new HashSet<>();
		for (int i : m.get(arr[k])) {
			if (i == k) {
				addBA(arr,k,l,store);
				continue;
			}
			if (store[i] >0)
				continue;
			if (arr[i] == arr[k]) {
				l.add(i);
				if (i == 0) {
					//可以提前结束了
					break;
				} 
			}
		}
		for(int i:l) {
			store[i]=store[k]+1;
		}
		return l;
	}

	private void addBA(int[] arr, int k, Set<Integer> l, int[] store) {
		if (k - 1 >= 0 && store[k - 1] ==0) {
			l.add(k - 1);
		}
		if (k + 1 < arr.length && store[k + 1] ==0) {
			l.add(k + 1);
		}
	}

	public int minJumps(int[] arr) {
		//只有一个元素，不用jump
		if(arr.length==1)
			return 0;
		
		Map<Integer,List<Integer>> m = new HashMap<>();
		for(int i=0;i<arr.length;i++) {
			if(!m.containsKey(arr[i])) {
				m.put(arr[i], new ArrayList());
			}
			m.get(arr[i]).add(i);
		}
		
		//最后一位需要jump一次才能到
		int[] store = new int[arr.length];
		store[arr.length-1] = 1;
		
		Set<Integer> s = new HashSet<Integer>();
		s.add(arr.length - 1);
		while (true) {
			Set<Integer> f = new HashSet<Integer>();
			for (int i : s) {
				f.addAll(stepOne(arr, i,store,m));
				if (f.contains(0)) {
					return store[0]-1;
				}
			}
			if (f.size() == 0)
				return 0;
			s.clear();
			s.addAll(f);
		}
		
	}
}
```