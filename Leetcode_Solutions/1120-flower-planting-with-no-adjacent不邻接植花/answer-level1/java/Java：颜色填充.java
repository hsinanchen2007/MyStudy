1. 给出每一个节点,和它连接的list，存入map;
2. 从小到大依次访问每一个节点，比你高标记此节点已经涂色过；
3. 为当前节点染色：如果其list中不存在已经涂色的区域，给颜色 1; 如果存在已经涂色的区域，取不和已涂色区域冲突的最小的颜色;

class Solution {
	public int[] gardenNoAdj(int N, int[][] paths) {
		Map<Integer, List<Integer>> graph = new HashMap<>();
		for (int i = 0; i < N; i++) {
			graph.put(i, new ArrayList<Integer>());
		}
		for (int[] path : paths) {
			graph.get(path[0] - 1).add(path[1] - 1);
			graph.get(path[1] - 1).add(path[0] - 1);
		}
		int[] res = new int[N];
		List<Integer> list;
		boolean[] used = new boolean[N + 1];
		boolean[] color;
		for (int i = 0; i < N; i++) {
			list = graph.get(i);
			used[i] = true;
			int max = 0;
			color = new boolean[5];
			for (int adj : list) {
				if (used[adj]) {
					max = Math.max(res[adj], max);
					color[res[adj]] = true;
				}
			}
//			为当前节点染色
			if(max == 0) {
				res[i] = 1;
			}else {
				for(int j = 1;j < 5;j++) {
					if(!color[j]) {
						res[i] = j;
						break;
					}
				}
			}
		}
		return res;
	}
}