```
//先排个子最低的，有一样高的排前面人最多的那个
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Comparator<int[]> com;
        int[][] answer;
        List<Integer> index;
        int i;
        
        answer = new int[people.length][2];
        index = new LinkedList<>();
        for(i = 0; i < people.length; i++)
        	index.add(i);
        com = new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				if(o1[0] != o2[0])
					return o1[0] - o2[0];
				return o2[1] - o1[1];
			}
		};

		Arrays.sort(people, com);
		for(i = 0; i < people.length; i++) {
			answer[index.get(people[i][1])] = people[i];
			index.remove(people[i][1]);
		}
    	return answer;
    }
}
```

