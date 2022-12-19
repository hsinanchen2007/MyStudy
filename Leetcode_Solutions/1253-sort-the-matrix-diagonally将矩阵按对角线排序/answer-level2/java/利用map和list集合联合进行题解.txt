由于对角线元素的相同点是j-i的值相等，即纵坐标和横坐标之差相等
主要分成三步：
1. 将j-i相等的元素都按j-i集中放到list中，可用Map<Integer, List<Integer>> map=new HashMap<>()存放。
2. 对list的元素进行排序，这里为了方便，我直接调用的Collections.sort()方法。
3. 再次遍历二维数组mat，对其重新赋值。
`这个时间复杂度较高
执行用时 :17 ms, 在所有 Java 提交中击败了5.85%的用户
内存消耗 :41.2 MB, 在所有 Java 提交中击败了100.00%的用户`
```
public int[][] diagonalSort(int[][] mat) {
     Map<Integer, List<Integer>> map=new HashMap<>();
	//同一对角线元素的j-i值相等，所以把这些按j-i值进行分类集中
	for (int i = 0; i < mat.length; i++) {
		for (int j = 0; j < mat[i].length; j++) {
			if (!map.containsKey(j-i)) map.put(j-i, new ArrayList<>());			
			map.get(j-i).add(mat[i][j]);						
		}
	}
	//对分类的值分别进行排序，从小到大
	for(int key:map.keySet()) {
		Collections.sort(map.get(key));
	}
	//对矩阵元素按对角线排序后重新赋值。
	for (int i = 0; i < mat.length; i++) {
		for (int j = 0; j < mat[i].length; j++) {
			mat[i][j]=map.get(j-i).get(0);
			map.get(j-i).remove(0);
		}
	}	
	return mat;      
    }
```
