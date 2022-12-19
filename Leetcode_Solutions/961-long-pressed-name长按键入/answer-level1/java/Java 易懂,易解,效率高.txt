1.核心while循环,如果字符一样则两个指针都加一,如果不一样,则长按键字符指针加1;
2.最后判断p1是否等于name的长度即可;
3.完结。


    public boolean isLongPressedName(String name, String typed) {
		char[] c1 = name.toCharArray();
		char[] c2 = typed.toCharArray();
		
		int p1 = 0, p2 = 0;
		while (p1 < c1.length && p2 < c2.length) {
			if (c1[p1] == c2[p2]) {
				p1++;
			}
			p2++;
		}

		return p1 == c1.length;
	    }