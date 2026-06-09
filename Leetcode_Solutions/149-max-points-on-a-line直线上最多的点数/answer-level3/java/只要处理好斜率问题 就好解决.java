将斜率化简后转换成字符串，形成字符串--频次  键值对的形式存储统计


  public int maxPoints(int[][] points) {
		if(points.length <= 1) {
			return points.length;
		}
		int res = 1;
		for(int i = 0; i < points.length; i ++) {
			//将斜率-频次  键值对存储在map中   不过斜率是以字符串形式存在而不是double形式的数
			Map<String, Integer> map = new HashMap<>();
			int samepoints = 0;	//相同的点
			for(int j = 0; j < points.length; j ++) {
				if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
					//说明两个点相同  即同一个点
					samepoints ++;
				}else {	//两个点不重合
					String k = slope(points[i], points[j]);
					if(!map.containsKey(k)) {
						map.put(k, 1);
					}else {
						map.put(k, map.get(k) + 1);
					}
				}		
			}
			res = Math.max(res, samepoints);	//针对的是所有点都是相同的点的情况
			if(map.size() > 0) {
				int[] arr = new int[map.size()];
				int index = 0;
				for(Map.Entry<String, Integer> en : map.entrySet()) {
					arr[index ++] = en.getValue();
				}
				Arrays.sort(arr);
				res = Math.max(res, arr[map.size() - 1] + samepoints);
			}
		}
		return res;
	}
	private String slope(int[] p1, int[] p2) {
		int dx = p1[0] - p2[0];
		int dy = p1[1] - p2[1];
		if(dx == 0) {
			return 1 + "/" + 0;
		} 
		if(dy == 0) {
			return 0 + "/" + 1;
		}
		int g = gcd(Math.abs(dy), Math.abs(dx));
		dx /= g;
		dy /= g;
		if(dx < 0) {
			dy = -dy;
			dx = -dx;
		}
		return dy + "/" + dx;
	}
	//寻找dx和dy的最大公约数
	private int gcd(int a, int b) {
		if(a < b) {
			swap(a, b);
		}
		if(a % b == 0) {
			return b;
		}
		return gcd(b, a % b);
	}
	private void swap(int a, int b) {
		int c = a;
		a = b;
		b = c;
	}