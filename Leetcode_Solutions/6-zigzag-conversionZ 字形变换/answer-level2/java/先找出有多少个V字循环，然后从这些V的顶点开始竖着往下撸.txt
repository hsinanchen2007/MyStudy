执行用时 : 13 ms, 在ZigZag Conversion的Java提交中击败了90.95% 的用户
内存消耗 : 40.8 MB, 在ZigZag Conversion的Java提交中击败了80.52% 的用户

解得凑合，尽力了。头都大了

这个算法是先找出有多少个V字循环，然后从这些V的顶点开始竖着往下撸。不大好描述，看代码吧。


	public static String convert1(String s, int numRows) {
        //如果行数是1，不需要做转换
        if(numRows == 1){
            return s;
        }
        //字符串总长度
        int len = s.length();
        if (len <= 2) {
			return s;
		}

        StringBuilder sb = new StringBuilder(len);
        if (numRows == 2) {		//2的单独处理
			for (int i = 0; i < len / 2; i++) {
				sb.append(s.charAt(i * 2));
			}
			if (len % 2 != 0) {
				sb.append(s.substring(len - 1, len));
			}
			for (int i = 0; i < len / 2; i++) {
				sb.append(s.charAt(i * 2 + 1));
			}
			return sb.toString();
		}

        //每个单元之间间隔字母的左空间长度
        int leftSpace = 2 * numRows - 2;

        int mround = 0;
        int mnum = 0;
        while (true) {
        	mround += leftSpace;
        	mnum++;
        	if (mround + numRows > len) {
				break;
			}
		}
        
        for (int i = 0; i < numRows; i++) {
			for (int j = 0; j <= mnum; j++) {
				if (i % leftSpace == 0) {  //V字的上顶点
					if (i + j * leftSpace < len) {
						sb.append(s.charAt(i + j * leftSpace));
					}
				} else {
					if ((i + 1) % numRows == 0) {  //V字的下顶点
						if (j != 0 && j * leftSpace - i < len) {
							sb.append(s.charAt(j * leftSpace - i));
						}
					} else {  //V字的身子
						if (j != 0 && j * leftSpace - i < len) {
							sb.append(s.charAt(j * leftSpace - i));
						}
						if (i + j * leftSpace < len) {
							sb.append(s.charAt(i + j * leftSpace));
						}
					}
				}
			}
		}

        return sb.toString();
    }