判断a-b为正数还是负数,int类型负数首位为1，正数为0
所以右移31位 得到正负数 0或1 然后与a，b相乘得结果
由于溢出问题，int转为long进行右移
```
 public int maximum(int a, int b) {
	        long c=a;long d=b;
	    int res=(int)((c-d)>>>63);// >>>和>>区别 >>>无符号右移
	        return b*res+a*(res^1);
	    }
```
