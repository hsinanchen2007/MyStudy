talk is cheap，show your code.
```
import java.util.Map.Entry;
class Solution {
	public int maxPoints(int[][] points) {
        if(points.length < 3) return points.length;
		int x= 0, y = 1;
		Map<String,Integer> unique = new HashMap<String,Integer>();
		for(int i = 0; i < points.length; i++) {
			if(unique.containsKey(points[i][x]+","+points[i][y])) {
				unique.put(points[i][x]+","+points[i][y],unique.get(points[i][x]+","+points[i][y])+1);
			}else unique.put(points[i][x]+","+points[i][y],1);
		}
		
		int[][] p = new int[unique.size()][2];
		int index = 0;
		for(Entry<String,Integer> e: unique.entrySet()) {
			String[] xy = e.getKey().split(",");
			p[index][y] = Integer.valueOf(xy[y]);
			p[index][x] = Integer.valueOf(xy[x]);
			++index;
		}

        if(p.length == 0) return 0;
        if(p.length == 1) return unique.get(p[0][x]+","+p[0][y]);
		
		int[][] k = new int[((p.length - 1)*p.length)/2][4];
		int x1 = 0, y1 = 1,x2 = 2, y2 = 3;
		index = 0;
		for(int i = 0; i < p.length - 1; i++) {
			for(int j = i+1; j < p.length; j++) {
				k[index][x1] = p[i][x];
				k[index][y1] = p[i][y];
				k[index][x2] = p[j][x];
				k[index][y2] = p[j][y];
				++index;
			}
		}
		int[] count = new int[k.length];
		for(int n = 0; n < k.length; n++) {
			for(int i = 0; i < p.length; i++) {
				long leftVal = (long)(k[n][x1]-k[n][x2])*(long)p[i][y];
				long rightVal = (long)(k[n][y1]-k[n][y2])*(long)p[i][x]+(long)k[n][x1]*(long)k[n][y2]-(long)k[n][x2]*(long)k[n][y1];
				if(leftVal == rightVal)
					count[n] += unique.get(p[i][x]+","+p[i][y]);
			}
		}
		int max = 0;
		for(int i = 0; i < count.length; i++) {
			max = count[i]>max?count[i]:max;
		}
		return max;
	}
	public void test() {
		Random r = new Random();
		int len = 10,range = 20;
		int[][] in = new int[len][2];
		for(int i = 0; i < len; i++) {
			in[i][0] = r.nextInt(2*range) - 20;
			in[i][1] = r.nextInt(2*range) - 20;
			System.out.print("("+in[i][0]+","+in[i][1]+") ");
		}
		System.out.println("");
		System.out.println(maxPoints(in));
	}
}
```
