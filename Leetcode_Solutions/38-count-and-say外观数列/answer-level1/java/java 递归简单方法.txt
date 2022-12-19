```

public static void main(String[] args) {
		
		
		String ans = countAndSay(6);
		System.out.println(ans);
	}

	
	private static String countAndSay(int i) {
		String ans = "";
		if(i == 1) {
			return "1";
		}
		//后一项依赖前一项 想到递归
		String last = countAndSay(i-1);
		char[] charArray = last.toCharArray();
		for(int j=0;j<charArray.length;j++) {
			int same = 1;//从这个位置开始往后有几个相同的
			while(j<charArray.length-1 && charArray[j] == charArray[j+1]) {
				same++;
				j++;//j也要增加，比如11121,j=0开始,当便利到第3个1时,same=3,如果此处j不递增,j就会=1,就会重复,（这是本题的关键）
			}
			ans = ans + same + charArray[j];
		}
		return ans;
	}
```
