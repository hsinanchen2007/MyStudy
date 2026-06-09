先转换成字符串，再将字符串转换成int
```

        private static int reverse(int a) {
		String str = String.valueOf(a);
		int flag = a < 0 ? -1 : 1;
		if(flag == -1) {
			String str1 = str.substring(1);
			StringBuffer sb1 = new StringBuffer(str1);
			sb1.reverse();
			str1 = new String("-"+sb1);
			try {
			int result =Integer.parseInt(str1);
			return result;}
			catch(Exception e) {
				return 0;
			}
		}else {
		
		StringBuffer sb = new StringBuffer(str);
		sb.reverse();
		str = new String(sb);
		try {
			int result = Integer.parseInt(str);
			return result;
		}catch(Exception e) {
			return 0;
		}
		}
	}
```