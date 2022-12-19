
public  void rotate(int[][] array) {
		int len = array.length;
		if (len == 0 || len == 1) {
			return;
		}
		for (int i = 0; i < len / 2; i++) {//总共有多少矩形,从最外围开始旋转
			int currLen = len -1- i * 2;//注意这里一定要减去1,假设每行有四个数则只需旋转3个
			for (int j = 0; j < currLen; j++) {//每个矩形需要旋转多少个数
				int k = i+j;
				int temp = array[k][len - i - 1];
				array[k][len - i - 1] = array[i][k];
				array[i][k] = array[len - k - 1][i];
				array[len - k - 1][i] = array[len - i - 1][len - k - 1];
				array[len - i - 1][len - k - 1] = temp;
			}
		}
	}