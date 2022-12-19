### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int fun(int[] deck,int a,int b) {
		for(int i=a+1;i<=b;i++) {
			if(deck[i]!=deck[i-1]) {
				return 0;
			}
		}
		return 1;
	}
	public static boolean hasGroupsSizeX(int[] deck) {
        Arrays.sort(deck);
		int i,j,temp;
		for(i=1;i<deck.length;i++) {
			temp=i+1;
			if(deck.length%temp!=0) {
				continue;
			}
			for(j=i;j<deck.length;j+=temp) {
				if(fun(deck,j-i,j)==0) {
					break;
				}
			}
			if(j==deck.length-1+temp) {
				return true;
			}
		}
		return false;
    }
}
```