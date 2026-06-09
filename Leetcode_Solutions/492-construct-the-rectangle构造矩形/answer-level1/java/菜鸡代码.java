### 解题思路
没有思路，干就完事儿了。
### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
int L=area,W=1;
int [] num=new int [2];
num[0]=L;
num[1]=W;
int count=L-W;
while(L>=W) {
L--;
if(L>0){
	if(area%L==0) {
		W=area/L;
		if(L>=W&&(L-W)<count) {
			count=L-W;
			num[0]=L;
			num[1]=W;
			continue;
		}
		
	}else {
		
		continue;
		
	}
	
}
	
	
}
 	
    return num;
    }
}
```