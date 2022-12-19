> bitCount实现的功能是计算一个（byte,short,char,int统一按照int方法计算）int,long类型的数值在二进制下“1”的数量。

```Java
class Solution{
	public List<String>readBinaryWatch(int num){
		List<String>times=new ArrayList<>();
		for(int h=0;h<12;h++){
			for(int m=0;m<60;m++){
				if(Integer.bitCount(h)+Integer.bitCount(m)==num)
					times.add(String.format("%d:%02d",h,m));
			}
		}
		return times;
	}
}
```
-----------------------
这是它在JDK1.8下的源码
```Java
public static int bitCount(int i) {
        // HD, Figure 5-2
        i = i - ((i >>> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
        i = (i + (i >>> 4)) & 0x0f0f0f0f;
        i = i + (i >>> 8);
        i = i + (i >>> 16);
        return i & 0x3f;
}
```