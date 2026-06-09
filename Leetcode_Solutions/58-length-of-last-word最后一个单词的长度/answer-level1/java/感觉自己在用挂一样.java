
首先判断s是否为空串（由多个空格组成，这里不考虑是否为null）
再利用切割字符串的方法split，按照空格切割，取数组最后一个元素，就ok了
数组是split方法切割字符串后返回的数组
```
    public static int lengthOfLastWord(String s) {
    	if(s.trim().length() == 0){
    		return 0;
    	}
    	return s.trim().length() == 0?0:s.split(" ")[s.split(" ").length-1].length();
    }
```
