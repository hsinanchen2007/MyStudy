```javascript []
/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
	var res = [];
	//定义一个二维数组，初始化全是0，皇后落格后，受影响的格子全部+1
	var nums = new Array();
	for (var i = 0; i < n; i++) {
		var nums2 = new Array();
		for (var j = 0; j < n; j++) {
			nums2.push(0);
		}
		nums.push(nums2);
	}
	//用一个栈记录皇后坐标位置，取第4象限
	var stack = [];
	for (var i = 0, j = 0; i < n; i++) {
		for (; j < n; j++) {
			//当前格子可以放皇后
			if (nums[i][j] == 0) {
				//记录皇后位置
				stack.push([i, j]);
				//处理星形线数字
				T51_doStar(nums, i, j, 1);
				break;
			}
		}
		j = 0;
		if (i == n - 1) {
			//如果已经放下n个皇后
			if (stack.length == n) {
				var rows = [];
				for (var x = 0; x < n; x++) {
					var row = '', t = stack[x][1];
					for (var y = 0; y < n; y++) {
						if (y == t) row += 'Q'; else row += '.'; 
					}
					rows.push(row);
				}
				res.push(rows);
			}
			var xy = stack.pop();
			i = xy[0];
			j = xy[1];
			//处理星形线数字
			T51_doStar(nums, i, j, -1);
			//上一行皇后落在最后一格，需要多回溯一行，因为不会列重合，所以只需判断一次即可
			if (xy[1] == n - 1 && stack.length > 0) {
				xy = stack.pop();
				i = xy[0];
				j = xy[1];
				//处理星形线数字
				T51_doStar(nums, i, j, -1);
			}
			//如果栈中没有皇后，回溯已经到了第一行的最后一个，则终止循环
			if (stack.length == 0 && j == n - 1) break;
			i--;
			j++;
		}
	}
	return res;
}

/**处理当前格子所在星形行、列、对角线上的数字*/
function T51_doStar(nums, i, j, num) {
	var n = nums.length;
	for (var t = 0; t < n; t++) {nums[i][t]+=num;}//行
	for (var t = 0; t < n; t++) {nums[t][j]+=num;}//列
	var x = i, y = j;
	//对角线左上角的数
	while (x > 0 && y > 0) {x--;y--;}
	//左上角到右下角的对角线数字+1
	while (x < n && y < n) {nums[x][y]+=num;x++;y++;}
	x = i;y = j;
	//对角线右上角的数
	while (x > 0 && y < n - 1) {x--;y++;}
	//右上角到左下角的对角线数字+1
	while (x < n && y >= 0) {nums[x][y]+=num;x++;y--;}
}
```
```java []
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        //定义一个二维数组，初始化全是0，皇后落格后，受影响的格子全部+1
        int[][] nums = new int[n][n];
        //用一个栈记录皇后坐标位置，取第4象限
        Stack<int[]> stack = new Stack<>();
        for (int i = 0, j = 0; i < n; i++) {
            for (; j < n; j++) {
                //当前格子可以放皇后
                if (nums[i][j] == 0) {
                    //记录皇后位置
                    stack.push(new int[] {i, j});
                    //处理星形线数字
                    T51_doStar(nums, i, j, 1);
                    break;
                }
            }
            j = 0;
            if (i == n - 1) {
                //如果已经放下n个皇后
                if (stack.size() == n) {
                    List<String> rows = new ArrayList<>();
                    for (int x = 0; x < n; x++) {
                        StringBuilder row = new StringBuilder();
                        int t = stack.get(x)[1];
                        for (int y = 0; y < n; y++) {
                            if (y == t) row.append("Q"); else row.append("."); 
                        }
                        rows.add(row.toString());
                    }
                    res.add(rows);
                }
                int[] xy = stack.pop();
                i = xy[0];
                j = xy[1];
                //处理星形线数字
                T51_doStar(nums, i, j, -1);
                //上一行皇后落在最后一格，需要多回溯一行，因为不会列重合，所以只需判断一次即可
                if (xy[1] == n - 1 && stack.size() > 0) {
                    xy = stack.pop();
                    i = xy[0];
                    j = xy[1];
                    //处理星形线数字
                    T51_doStar(nums, i, j, -1);
                }
                //如果栈中没有皇后，回溯已经到了第一行的最后一个，则终止循环
                if (stack.size() == 0 && j == n - 1) break;
                i--;
                j++;
            }
        }
        return res;
    }
    
    /**处理当前格子所在星形行、列、对角线上的数字*/
	private void T51_doStar(int[][] nums, int i, int j, int num) {
		int n = nums.length;
		for (int t = 0; t < n; t++) {nums[i][t]+=num;}//行
		for (int t = 0; t < n; t++) {nums[t][j]+=num;}//列
		int x = i, y = j;
		//对角线左上角的数
		while (x > 0 && y > 0) {x--;y--;}
		//左上角到右下角的对角线数字+1
		while (x < n && y < n) {nums[x][y]+=num;x++;y++;}
		x = i;y = j;
		//对角线右上角的数
		while (x > 0 && y < n - 1) {x--;y++;}
		//右上角到左下角的对角线数字+1
		while (x < n && y >= 0) {nums[x][y]+=num;x++;y--;}
	}

}
```