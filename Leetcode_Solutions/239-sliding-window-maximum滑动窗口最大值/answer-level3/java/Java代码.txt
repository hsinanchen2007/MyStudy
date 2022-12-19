```
        Queue<Integer> queue = new LinkedList<Integer>();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0 ; i < k ; i++) queue.add(nums[i]);
		list.add(Collections.max(queue));
		for (int i = k ; i < nums.length; i++) {
			queue.poll();
			queue.add(nums[i]);
			list.add(Collections.max(queue));	
		}
		int res [] = new int [list.size()];
		for (int i = 0; i < res.length; i++) res[i] = list.get(i);
		return res;
```
