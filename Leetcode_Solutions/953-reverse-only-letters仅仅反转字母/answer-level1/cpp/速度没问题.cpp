![2.PNG](https://pic.leetcode-cn.com/ed42a28b9cf1061ca69d1a61a517ec76e69fbf3cd2ef254915f6aa113c6b8c2f-2.PNG)
```
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i=0,j=S.size()-1;
        int tmp;
        while(i<=j){
        	//i定位最左边未反转的字母下标，j类似为最右边 
        	while((S[i]<'A'||S[i]>'Z'&&S[i]<'a'||S[i]>'z')&&i<=j)
        		i++;
			while((S[j]<'A'||S[j]>'Z'&&S[j]<'a'||S[j]>'z')&&i<=j)
        		j--; 
        	if(i<=j){
        		tmp=S[i];
        		S[i]=S[j];
        		S[j]=tmp;
			}
			i++;
			j--;
		}
		return S;
    }
};
```


