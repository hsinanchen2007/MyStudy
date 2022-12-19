### 解题思路
具体分析各种情况即可。[https://blog.csdn.net/qq_23134039/article/details/103769493]()
### 代码

```java
class Solution {
    public boolean buddyStrings(String A, String B) {
       if(A.length()!=B.length()) {
			return false;
		}
		if(A.equals(B)) {//AB相同则判断是否出现重复字符
			int[] datas = new int[26];  //缓存各字符的出现次数
			for(int i=0;i<A.length();i++) {
				int m=A.charAt(i)-'a';
				if(datas[m]==1) { //第二次出现
					return true;
				}else {//第一次出现
					datas[m]=1;
				}
			}
			return false;//无重复字符
		}else {
			int mi=-1;//第一次差异
			char []as=A.toCharArray();
			char []bs=B.toCharArray();
			for(int i=0;i<as.length;i++) {
				if(as[i]!=bs[i]) {
					if(mi!=-1) {//不是第一次出现差异
						char c= as[mi];//交换一对，则两组应当相同
						as[mi]=as[i];
						as[i]=c;
						return Arrays.equals(as, bs);
					}else {//第一次差异
						mi=i;
					}
				}
			}
			return false; //仅出现一次差异
		}
    }
}
```