### 解题思路
一开始的时候,由于题目里面并没有给出数据量,又看到这是个中等题,我就下意思地使用了dfs,前几组数据勉强还行,后面数据量一大,就TLE了,我以为是wordlist的问题,就先对wordlist进行了优化,然后再submit,结果还是TLE,这个时候我才意识到dfs是行不通的,果断转战dp,结果喜人,下面贴出我的提交记录和代码



### 第一次尝试

```java
class Solution {
    	public boolean wordBreak(String s, List<String> wordDict) {

		HashSet<String> set=new HashSet<>();
		for(String t:wordDict){
			set.add(t);
		}
		return finder(s, set);
	}

	boolean finder(String s, Set<String> set) {
		if(s.equals("")){return true;}
		for (int i = 1; i <= s.length(); i++) {
			if (set.contains(s.substring(0, i)) && finder(s.substring(i), set)) {
				return true;
			}
		}
		return false;
	}
}
```
### 第二次尝试(对wordlist进行优化,去除wordlist里面的赘余,比如"a","b","ab"就去除"ab",显然没啥用)

```java
class Solution {
    	public boolean wordBreak(String s, List<String> wordDict) {

		HashSet<String> set=new HashSet<>();
		for(String t:wordDict){
			set.add(t);
		}
		wordDict.sort(new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o2.length()-o1.length();
			}
		});
		for(String t:wordDict){
			set.remove(t);
			if(!finder(t,set)){
				set.add(t);
			}
		}
		return finder(s, set);
	}

	boolean finder(String s, Set<String> set) {
		if(s.equals("")){return true;}
		for (int i = 1; i <= s.length(); i++) {
			if (set.contains(s.substring(0, i)) && finder(s.substring(i), set)) {
				return true;
			}
		}
		return false;
	}
}
```
### ac代码

```java
class Solution {
   public boolean wordBreak(String s, List<String> wordDict) {

		HashSet<String> set=new HashSet<>();
		for(String t:wordDict){
			set.add(t);
		}
		int len=s.length();
		boolean[] dp = new boolean[len + 1];
		dp[0]=true;
		for(int i=1;i<=len;i++){
			for (int j = i - 1; j >= 0; j--) {
				if(set.contains(s.substring(j,i))&&dp[j]){
					dp[i]=true;
					break;
				}
			}
				
		}
		
		return dp[len];
		
	}
}
```
![image.png](https://pic.leetcode-cn.com/1e521cbb7505e96c340ba14a7e8318ed0d761d1e9047abf8b2e192a3809f538f-image.png)