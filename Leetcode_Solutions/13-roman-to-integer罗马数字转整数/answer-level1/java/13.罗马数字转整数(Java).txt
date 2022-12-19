
一开始想到的是用哈希表来解决，字母和数字分别对应key和value存入哈希表，然后迭代哈希表，比较当前位置和下一位置的数字，决定当前数字是加还是减。

耗时10ms，哭唧唧 (╥╯^╰╥)
```
public int romanToInt(String s) {
	HashMap<Character, Integer> map = new HashMap<>() {//初始化哈希表
		{
			put('I', 1);
			put('V', 5);
			put('X', 10);
			put('L', 50);
			put('C', 100);
			put('D', 500);
			put('M', 1000);
		}
	};
		
	int len = s.length();
	int sum = map.get(s.charAt(len - 1));//最后一个数一定是加上
		
	for (int i = 0; i < len - 1; i++) {
		char c = s.charAt(i);//当前位置的字母
		char n = s.charAt(i + 1);//下一位置的字母
		int num = map.get(c);//当前位置对应的数字
		if((c=='I'&&(n == 'V' || n == 'X'))||(c=='X'&&(n == 'L' || n == 'C'))||(c=='C'&&(n == 'D' || n == 'M'))) {
			sum -= num;
		} else {
			sum += num;
		}
	}

	return sum;
}
```
然后，去掉哈希表，写一个可以返回对应值的函数，同样相邻位置做比
耗时减少了，4ms   ＼( ^▽^ )／
```
public int romanToInt(String s) {

	int len = s.length();
	int sum = valueOf(s.charAt(len-1));
	int prenum = 0;
		
	for (int i = 0; i < len; i++) {
		int nownum = valueOf(s.charAt(i));
		if (prenum < nownum) {
			sum -= prenum;
		} else {
			sum += prenum;
		}
		prenum = nownum;
			
	}
	return sum;
}

public int valueOf(char c) {
	switch (c) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return 0;
	}
}
```
