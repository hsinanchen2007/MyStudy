将二维数组遍历一遍，记录其他点到该点的距离，并将距离--频次键值对存储在Map查找表中，循环结束后，对Map集合中值大于2的进行统计
    public int numberOfBoomerangs(int[][] points) {		
		int res = 0;
		for(int i = 0; i < points.length; i ++) {
			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			for(int j = 0; j < points.length; j ++) {
				if(i != j) {
					int dis = dist(points[i],points[j]);
					if(map.containsKey(dis)) {
						map.put(dis, map.get(dis) + 1);
					}else {
						map.put(dis, 1);
					}
				}
			}
			for(Map.Entry<Integer, Integer> en : map.entrySet()) {	//增强for循环
				if(en.getValue() >= 2) {
					res += en.getValue() * (en.getValue() - 1);
				}
			}
		}
		return res;
    }
	private int dist(int[] p1, int[] p2) {
		return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
	}