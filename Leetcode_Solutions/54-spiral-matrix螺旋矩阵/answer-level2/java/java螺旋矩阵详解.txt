旋转方向是固定的，都是往右，往下，往左，往上这样不断的循环。


我们可以定义x1,x2来定义X方向的边界，y1和y2来定义Y方向的边界

int y1 = 0;

int y2 = matrix.length - 1;

int x1 = 0;

int x2 = matrix[0].length - 1;

数组的个数是固定的，m*n个，所以我们可以使用while循环

int count = (x2 + 1) * (y2 + 1);

我们定义四个变量来控制当前行走的方向，因为刚刚开始是往右走的，所以

boolean rigth = true;

boolean left = false;

boolean down = false;

boolean up = false;

定义一个变量K来代表当前添加到list的个数

int k = 0;

定义i,j来表示当前数组的下标

int i = 0;

int j = 0;


执行while循环

		while (k < count) {
			// 从左往右走
			if (rigth) {
				if (j >= x1 && j <= x2) {
					list.add(matrix[i][j]);
					k++;
					// 从左往右走，如果走到了边界
					if (j == x2) {
						y1++;// 下边界加1
						i++;
						down = true;// 下一次执行从上往下
						rigth = false;
						left = false;
						up = false;
						continue;
					}
					j++;
					continue;
				}
			}
			// 从右往左走
			if (left) {
				if (j >= x1 && j <= x2) {
					list.add(matrix[i][j]);
					k++;
					// 从右往左走，走到了边界
					if (j == x1) {
						y2--;// 上边界减1
						i--;
						down = false;
						rigth = false;
						left = false;
						up = true;// 下一次执行从下往上走
						continue;
					}
					j--;
					continue;
				}

			}
			// 从上往下走
			if (down) {
				if (i >= y1 && i <= y2) {
					list.add(matrix[i][j]);
					k++;
					// 从上往下走，走到了边界
					if (i == y2) {
						x2--;// 右边界减1
						j--;
						down = false;
						rigth = false;
						left = true;// 下一次执行从右往左走
						up = false;
						continue;
					}
					i++;
					continue;
				}
			}

			// 从下往上走
			if (up) {
				if (i >= y1 && i <= y2) {
					list.add(matrix[i][j]);
					k++;
					// 从下往上走，走到了边界
					if (i == y1) {
						x1++;// 左边界加1
						j++;
						down = false;
						rigth = true;// 下一次执行从左往右走
						left = false;
						up = false;
						continue;
					}
					i--;
					continue;
				}

			}

		}

完整代码






	public static List<Integer> spiralOrder(int[][] matrix) {
		if (matrix == null || matrix.length == 0) {
			return new ArrayList<Integer>();
		}
		List<Integer> list = new ArrayList<Integer>();
		int y1 = 0;
		int y2 = matrix.length - 1;

		int x1 = 0;

		int x2 = matrix[0].length - 1;

		int count = (y2 + 1) * (x2 + 1);

		int k = 0;
		int i = 0;
		int j = 0;
		boolean rigth = true;
		boolean left = false;
		boolean down = false;
		boolean up = false;
		while (k < count) {
			// 从左往右走
			if (rigth) {
				if (j >= x1 && j <= x2) {
					list.add(matrix[i][j]);
					k++;
					// 从左往右走，如果走到了边界
					if (j == x2) {
						y1++;// 下边界加1
						i++;
						down = true;// 下一次执行从上往下
						rigth = false;
						left = false;
						up = false;
						continue;
					}
					j++;
					continue;
				}
			}
			// 从右往左走
			if (left) {
				if (j >= x1 && j <= x2) {
					list.add(matrix[i][j]);
					k++;
					// 从右往左走，走到了边界
					if (j == x1) {
						y2--;// 上边界减1
						i--;
						down = false;
						rigth = false;
						left = false;
						up = true;// 下一次执行从下往上走
						continue;
					}
					j--;
					continue;
				}

			}
			// 从上往下走
			if (down) {
				if (i >= y1 && i <= y2) {
					list.add(matrix[i][j]);
					k++;
					// 从上往下走，走到了边界
					if (i == y2) {
						x2--;// 右边界减1
						j--;
						down = false;
						rigth = false;
						left = true;// 下一次执行从右往左走
						up = false;
						continue;
					}
					i++;
					continue;
				}
			}

			// 从下往上走
			if (up) {
				if (i >= y1 && i <= y2) {
					list.add(matrix[i][j]);
					k++;
					// 从下往上走，走到了边界
					if (i == y1) {
						x1++;// 左边界加1
						j++;
						down = false;
						rigth = true;// 下一次执行从左往右走
						left = false;
						up = false;
						continue;
					}
					i--;
					continue;
				}

			}

		}

		return list;
	}










