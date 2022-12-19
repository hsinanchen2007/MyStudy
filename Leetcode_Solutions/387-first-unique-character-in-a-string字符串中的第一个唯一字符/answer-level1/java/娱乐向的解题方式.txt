遍历一遍，借助contains方法判断是否包含遍历的字符，如果包含就下一轮判断。遍历过程中要把当前遍历的字符在字符串中先删去，不然contains永远能找到。
```
public int firstUniqChar(String s) {
        for(int i = 0; i < s.length(); i++) {
			String s1 = s.substring(0, i) + s.substring(i + 1);
			boolean flag = s1.contains(String.valueOf(s.charAt(i)));
			if(!flag)
				return i;
		}
		return -1;
    }
```
当然了，1.4s的时间，就当个乐子吧。
