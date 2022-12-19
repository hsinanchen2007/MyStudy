哈希map 记录所有元音字符的前缀异或值，及当前位置
当哈希表中可以查到该异或值时，说明当前位置与查到的位置之间的子串是满足题意的
举个例子：

"qacaba"
1
初始：没有元音，前缀异或值0，位置记为 -1；m[0] = -1
i = 0，没有元音，前缀异或值0，0 存在map，len = 0-(-1) = 1，最长“q”；
i = 1，出现元音a，前缀异或值a，位置 1；m[a] = 1
i = 2，没有元音，前缀异或值a，len = 2-m[a] = 1；
i = 3，出现元音a，前缀异或值a^a=0，len = 3-m[0] = 3-(-1) = 4，最长“qaca”；
i = 4，没有元音，前缀异或值0，len = 4-m[0] = 4-(-1)=5，最长“qacab”；
i = 5，出现元音a，前缀异或值0^a=a，len = 5-m[a] = 5-1 = 4，最长“caba”；

所以最长的是5个字符qacab

[https://michael.blog.csdn.net/article/details/104725634](https://michael.blog.csdn.net/article/details/104725634)

```
class Solution {
public:
    int findTheLongestSubstring(string s) {
    	unordered_map<int,int> m;	// 前缀异或值，对应的位置
    	int XOR = 0, i, maxlen = 0;
    	m[0] = -1;	//没有元音，位置为-1，方便计算个数
    	for(i = 0; i < s.size(); i++) 
    	{
    		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
    		{
    			if(m.count(XOR))
    				maxlen = max(maxlen, i-m[XOR]);
    		}
    		else //s[i] 是元音
    		{
    			XOR ^= s[i];//元音异或值
    			if(m.count(XOR))
    				maxlen = max(maxlen, i-m[XOR]);
    			else
    				m[XOR] = i;
    		}
    	}
    	return maxlen;
    }
};

```
