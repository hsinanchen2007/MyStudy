1.gap表距离,index表示下标,temp表示上一次1位置的坐标,cou表计数器;
2.第一次遍历遇到1时,没有1的坐标值,所以进不到if循环;
3.所以定义一个计数机cou,表示第二次才能进入if循环,temp记录上一次1位置的坐标;
4.记录下第一个1位置temp后,之后每次遍历到1的位置和上一次1的位置距离通过if里面的语句保留;
5.完结。

        public int binaryGap(int N) {
		int gap = 0;//两个1之间的距离
		int index = 0, temp = 0, cou = 0;//1的下标,上一次1的位置,计数器
		while (N != 0) {
			if ((N & 1) == 1) {
				cou++;
				if (cou > 1) {
					gap = Math.max(gap, index - temp);
				}
				temp = index;
			}
			index++;
			N >>= 1;
		}
		return gap;
	    }