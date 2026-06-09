### 解题思路
没有思路，干就完事儿了

### 代码

```java
class Solution {
  	 public int[] getNoZeroIntegers(int n) {
int [] a=new int [2];
int x,y,count=1;
while(count<=n) {
x=count;
y=n-count;
String sx,sy;
sx=Integer.toString(x);
sy=Integer.toString(y);
if(!sx.contains("0")&&!sy.contains("0")) {
	a[0]=x;
	a[1]=y;
	break;
}
	count++;
}
	
return a;
    }
}
```