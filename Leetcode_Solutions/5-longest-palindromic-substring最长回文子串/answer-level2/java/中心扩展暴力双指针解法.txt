### 解题思路
此处撰写解题思路
中心扩展暴力双指针解法，从左到右遍历回文字符串，指针begin和end从中心扩散遍历，中心我分为二种，偶数的和奇数的，偶数指针begin从i-1位置开始出发，奇数则从i出发，循环过程中记录回文字符串的长度，与上一次比较，如果较大就使用count记录此位置，否则重复此过程
### 代码

```java
class Solution {
    public String longestPalindrome(String s) {

		char[] chs = s.toCharArray();
		int count = 0;
		String maxstr = "";
		int getbegin = 0;
		int end = 0;
		int getbegin2 = 0;
		int end2 = 0;
		int tmp3 = 0;
		if(chs.length<=1) {
			return s;	
		}
		if (chs.length ==2) {
            if(chs[0]!=chs[1]){
            return maxstr+chs[0];
            }	
		   return maxstr + chs[0] + chs[1];
		}
		for (int i = 1; i < chs.length; i++) {
			int tmp = 0;
			int tmp2 = 0;
			if(i<chs.length-1) {
			if (chs[i - 1] != chs[i] && chs[i - 1] != chs[i + 1]) {
				continue;
			} else {
				if (chs[i - 1] == chs[i]) {
					int j = i - 1;
					int k = i;
					getbegin = getBeginAndEnd(chs, j, k)[0];
					end = getBeginAndEnd(chs, j, k)[1];
					tmp = end - getbegin + 1;
				}		
				if (chs[i - 1] == chs[i + 1]) {
					int j = i;
					int k = i;
					getbegin2 = getBeginAndEnd(chs, j, k)[0];
					end2 = getBeginAndEnd(chs, j, k)[1];
					tmp2 = end2 - getbegin2 + 1;
				}			
			}
			if (tmp > tmp2) {
				count = tmp;
			} else {
				count = tmp2;
			}
			if (count > tmp3) {
				tmp3 = count;
				maxstr = "";
				if (count % 2 == 0) {
										maxstr= s.substring(getbegin,end+1);

				} else {
										maxstr= s.substring(getbegin2,end2+1);

				}
			}

			}
			
			else {
           if(count<2) {
        	   if(chs[i-1]==chs[i]) {
   				return maxstr=maxstr+chs[i-1]+chs[i];
   				
   			}	
               else {		 
   				 return maxstr+chs[0];
   			 }
			}
			
				
			}
		}
		return maxstr;
	}

	public static int[] getBeginAndEnd(char[] s, int begin, int end) {
		int getbegin = begin;
		if (begin == 0) {
			return new int[] { getbegin, end };
		}
		for (getbegin = begin; begin > 0; begin--) {
			if (end < s.length - 1) {
				if (s[begin - 1] != s[end + 1]) {
					getbegin = begin;
					break;
				} else {
					getbegin--;
					end++;
					continue;
				}
			}
		}
		return new int[] { getbegin, end };
	}
}
```