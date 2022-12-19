### 解题思路
或许我讲解的不够明确，请大家谅解
因为要考虑数据溢出，所以可以先转换成long类型防止溢出
思路在下面我就不一一描述了，我主要讲下代码含义吧
String y=String.valueOf(x2);//把x2转为String类型
new StringBuffer(y).reverse().toString()//利用java自带的函数进行反转
Long.parseLong()和Integer.parseInt()//把String转换成Long或者Integer包装类
呃，，，我感觉我还是没将清楚


### 代码

```java
class Solution {
    public int reverse(int x) {
      	if(x<0) {
			long x2=(long)x;
			x2=-x2;
			String y=String.valueOf(x2);
			if(-Long.parseLong(new StringBuffer(y).reverse().toString())<Integer.MIN_VALUE)
				return 0;
			else
				return -Integer.parseInt(new StringBuffer(y).reverse().toString());
		}else {
			String y=String.valueOf(x);
			if(Long.parseLong(new StringBuffer(y).reverse().toString())>Integer.MAX_VALUE)
				return 0;
			else
				return Integer.parseInt(new StringBuffer(y).reverse().toString());
		}
}
}
```