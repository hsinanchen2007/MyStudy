### 解题思路
1.定义count数组存储deck中每个数的出现次数,
2.辗转相处法gcd求count中每个数字出现次数的最大公约数g

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
		int[] count = new int[10000];
		int g = -1;
		for (int i = 0; i < deck.length; i++) {
			count[deck[i]]++;
		}
		for (int i = 0; i < count.length; i++) {
			if(count[i]!=0){
				if(g==-1){
					g = count[i];
				}else{
					g = gcd(g,count[i]);
				}
			}
			
		}
		
		return g>=2;
    }
	public int gcd(int x,int y){
		if(y==0){
			return x;
		}
		return gcd(y, x%y);
	}
}
```