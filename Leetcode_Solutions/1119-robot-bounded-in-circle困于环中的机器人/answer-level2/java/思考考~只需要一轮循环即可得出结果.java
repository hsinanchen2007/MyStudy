执行用时 :1 ms, 在所有Java提交中击败了99.62%的用户
内存消耗 :33.6 MB, 在所有Java提交中击败了100.00%的用户
看了很多人写的似乎都用死循环来判断最后是否会回到终点，其实有点多此一举了，因为只要走完一轮后，方向改变，即不是直走的话，最后无论再走多少轮总有一轮会走回终点。
下面看代码吧，最后困于环也就两种情况。

    public boolean isRobotBounded(String instructions) {
        
		int dir = 0; // 方向: 0上   1右   2下   3左
		int x = 0;   // x轴坐标
		int y = 0;   // y轴坐标
		char ch;
		for(int i = 0; i < instructions.length(); i ++){
			ch = instructions.charAt(i); // 逐个读取字符
			if(ch == 'L'){
				if(dir == 0)
					dir = 3;
				else
					dir --;
			}
			if(ch == 'R'){
				if(dir == 3)
					dir = 0;
				else
					dir ++;
			}
			if(ch == 'G'){
				switch(dir){
				case 0: y ++; break;
				case 1: x ++; break;
				case 2: y --; break;
				case 3: x --; break;
				}
			}
		}
		// 情况1: 走完一轮回到原点
		if(x == 0 && y == 0)
			return true;
		// 情况2: 走完一轮,只要方向改变了(即不是直走了),最后不管走多少轮总会回到起点
		if(dir != 0)
			return true;
		
		return false;
		
    }