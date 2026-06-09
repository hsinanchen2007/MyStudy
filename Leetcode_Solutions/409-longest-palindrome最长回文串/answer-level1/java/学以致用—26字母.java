### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
		boolean m = false,n = false;//作为标记flag
		char[] c = new char[58];
		int sum = 0;
		for(char cc : s.toCharArray()){//标记出现的字母的次数
			c[(int)(cc-'A')] += 1;
		}
		for(int i=0;i<c.length;i++){//次数为偶数和大于1的相加，标记
			if(c[i]%2 == 0){//次数为偶数相加
				sum += c[i];
			}else{
				if(c[i]>1){
					sum += (c[i] - 1);//大于1的相加，且标记一下
					m=true;
				}
				if(c[i] == 1){//出现等于1的标记
					n = true;
				}
			}
		}
		if(m || n){//判断是否出现单数的字母
			sum = sum +1;//出现就加上
		}
		return sum;
    }
}
```