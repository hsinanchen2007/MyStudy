```
public int[] findDiagonalOrder(int[][] matrix) {
	List<Integer> list = new ArrayList<Integer>();
	int m = matrix.length;
	int[] array = {};
	if(m==0) return array;
	int n = matrix[0].length;
	
	boolean bXFlag = true;
	for(int i = 0; i<m+n;i++) {
		int pm = bXFlag? m : n;
		int pn = bXFlag? n : m;
		
		int x = (i<pm) ? i : pm-1;
		int y = i -x;
		
		while(x>=0 && y<pn) {
			list.add(bXFlag ? matrix[x][y] : matrix[y][x]);
			x--;
			y++;
		}
		
		bXFlag = !bXFlag;
	}
	
	int[] nums = new int[m*n];
	int j =0;
	for(int num : list) {
		nums[j++] = num;
	}
	
	return nums;
}
```

这个是  【对角线遍历】 分析题目-找准规律-代码清晰易读-不要让自己迷失在随意的ifelse中  题解的思路，将其转换成Java代码。
实现思路查看上面题解，感觉按他的思路来写比较清晰，但耗时比较长，我提交执行用了7ms。
