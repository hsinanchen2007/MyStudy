思路：
根据题目意思，我们可以把secret和guess中的对应关系分为以下三种：
(1) A：数字和位置都对
(2) B：数字对但是位置不对
(3) C：secret中的某些数字guess中没有
举例：
String secret = "8910"
String guess = "2611";
C这类情况对应上例中的“8”，“9”；A这类情况相对也非常好求得；最复杂的是统计B类情况。
SUM(A,B,C) = length(secret)
所以我们只需要求得A和C这两类情况，就可以求得B。

方法：
因为题目说明，字符串只包含数字，所以设置一个int[] show，大小为10,用来统计secret和guess中数字出现的情况。
1. 初始时，show[i]为0.
2. 遍历secret和guess字符串数组，出现secret的数字，对应位置的show + 1.
出现guess的数字，对应位置的show - 1.

当执行完一次遍历后，show > 0 的元素表明，该位置代表的数字出现在了secret中，但是没有出现在guess中。因为在secret和guess中同时出现的元素会被+1/-1抵消。

具体看代码：
```
 public String getHint(String secret, String guess) {
        /*公牛A：位置数字均对
		公牛B：数字对，位置不对*/
		if(secret==null||guess==null || secret.length()==0 ||
			secret.length()!=guess.length()) return null;

		char[] se = secret.toCharArray();
		char[] gue = guess.toCharArray();

		int[] show = new int[10];
		int a=0,b=0;
		//1.统计A; C:secret出现但guess未出现 show[i] > 0
		for(int i=0;i<se.length;i++) {
			show[se[i]-'0'] += 1;
			show[gue[i]-'0'] -= 1;
			if(se[i] == gue[i])
			    a++;
		}
		for(int cnt:show)
			if(cnt>0) b+= cnt;
		b = secret.length()-a-b;;
		String res = a+"A"+b+"B";
		return res;
    }
```
运行时间击败100% Java代码。