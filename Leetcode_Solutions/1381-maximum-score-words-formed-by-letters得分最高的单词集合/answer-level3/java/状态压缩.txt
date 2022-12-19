因为单词数量只有14这么大，因此我们可以用14位的二进制表示当前我们用了哪些串，然后看这些串能不能同时取到（换句话说，就是看我们送的字母是不是超支了！），然后我们从所有状态里找到最大值即可。
```
class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] dp=new int[(1<<14)+1];
        int[] a=new int[26];
        int[] b=new int[26];
        int[] c=new int[26];
        int[] values=new int[words.length];
        for(int i=0;i<letters.length;i++)
        	a[letters[i]-'a']++;
        for(int i=0;i<words.length;i++) {
        	boolean flag=false;
        	for(int j=0;j<26;j++) {b[j]=a[j];c[j]=0;}
        	for(int j=0;j<words[i].length();j++) {
        		b[words[i].charAt(j)-'a']--;
        		if(b[words[i].charAt(j)-'a']<0) flag=true;
        		c[words[i].charAt(j)-'a']++;
        	}
        	if(flag) values[i]=0;
        	else {
        		for(int j=0;j<26;j++)
        			values[i]+=c[j]*score[j];
        	}
        }
        for(int i=0;i<(1<<words.length);i++) {
        	int sum=0;
        	for(int j=0;j<26;j++) b[j]=a[j];
        	for(int j=0;j<words.length;j++) {
        		if(((i>>j)&1)!=0) {
        			for(int h=0;h<words[j].length();h++)
        				b[words[j].charAt(h)-'a']--;
        			sum+=values[j];
        		}
        	}
        	boolean flag=false;
        	for(int j=0;j<26;j++)
        		if(b[j]<0)
        			flag=true;
        	if(!flag) dp[i]=sum;
        }
        int ans=0;
        for(int i=0;i<(1<<words.length);i++) 
        	ans=Math.max(ans, dp[i]);
        return ans;
    }
}

```
