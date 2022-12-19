![捕获.PNG](https://pic.leetcode-cn.com/7e6eae2c062d3357b25a9e4a4eb09a5d78df73090be71ce9a7f522fbf3bedea8-%E6%8D%95%E8%8E%B7.PNG)

class Solution {
public:

    string shortestCompletingWord(string licensePlate,vector<string>& words) {
        int a[26]={0};
        int i,j;
        int re;
        vector<int> ans;
        for(i=0;i<licensePlate.size();i++){//数组a存牌照所含字母情况 
        	if(licensePlate[i]>='a'&&licensePlate[i]<='z')
        		a[licensePlate[i]-'a']++;
        	else if(licensePlate[i]>='A'&&licensePlate[i]<='Z')
        		a[licensePlate[i]-'A']++;
		}		
		for(i=0;i<words.size();i++){
			int b[26]={0};//存放每个单词所含字母情况 
			for(j=0;j<words[i].size();j++)
				b[words[i][j]-'a']++; 
			for(j=0;j<26;j++) 
				if(a[j]>b[j])
					break;
			if(j==26)//匹配成功 
				ans.push_back(i);
		}
		re=ans[0];
		for(i=1;i<ans.size();i++)
			if(words[ans[i]].size()<words[re].size())
				re=ans[i];
		return words[re];
    }
};