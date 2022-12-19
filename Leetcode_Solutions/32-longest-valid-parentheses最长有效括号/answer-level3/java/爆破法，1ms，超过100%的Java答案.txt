爆破法：当一串括号从开始配对到爆破时，爆破之前的完全配对。之后的配对肯定隔离着本次的配对，意味着本趟就是一个有效整体，记录下本趟的配对长度。之后再开始下一趟的爆破。当最后一趟没有爆破时，检查是否配对完全，若完全，则找到了本趟的有效整体，否则，就从反方向对本趟进行爆破（必定可以找到有效整体，因为正向没爆破意味着所有反括号都能配对成功，意味着反向爆破的最后一趟只能是爆破或者完全配对）

```
代码块class Solution {
    public int longestValidParentheses(String s) {
          int len_s=s.length();
		    //从左遍历
	        int  matchl = 0, leftres = 0;
	        int  startleft=0;//记录每一趟的开头
			for(int i = 0; i < len_s; i++) {
				if(s.charAt(i) == '(')
					matchl+=1;
				else
					matchl+=-1;
				if(matchl==-1) {//爆了，输出前面的长度就可以了
					int len=i-startleft;//此趟的配对长度
					leftres=(len>leftres)?len:leftres;
					matchl=0;//清零。开始下一趟
					startleft=i+1;
				}
			}
			if(startleft==s.length()) return leftres;//最后一趟爆了
			if(matchl==0) {//最后一趟没爆，但是也刚好配对完成
				int len=s.length()-startleft;
				leftres=len>leftres?len:leftres;
				return leftres;
			}
			
			//从右遍历
			int  matchr=0,rightres = 0;
			int  startright=len_s-1;//记录每一趟的开头
			for(int i = len_s - 1; i > startleft-1; i--) {
				if(s.charAt(i) == '(')
					matchr+=1;
				else
					matchr+=-1;
				if(matchr==1) {//爆了
					int len=startright-i;
					rightres = len>rightres?len:rightres;
					matchr=0;//清零。开始下一趟
					startright=i-1;
				}
			}
			
			if(startright>startleft-1) {//最后一趟没爆
				int len=startright-startleft+1;
				rightres=len>rightres?len:rightres;
			}
			return leftres>rightres?leftres:rightres;
    }
}
```


