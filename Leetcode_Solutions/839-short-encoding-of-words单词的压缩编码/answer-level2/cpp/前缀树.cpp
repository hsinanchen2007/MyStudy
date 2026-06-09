### 解题思路
此处撰写解题思路
这里主要是在考前缀树，定义结构体Trie,v用来存放当前节点是不是尾结点，如果是尾结点就置为1，否则为0；采用逆序遍历字符串的每个字符，当有字符串是另一个的子字符串是，记得将v置为0，用sum记录所有尾结点的长度，n记录最后数的根节点的个数。
### 代码

```cpp
typedef struct Trie
{
	Trie*next[26];
	int v;
}Trie;


class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		if (words.size() == 0)
			return 0;
		int nums = words.size();
		Trie *root=new Trie();

		int sum = 0;
		int n = 0;
		for (int i = 0;i < nums;i++)
		{
			//sweap(words[i]);
			insert(*root,words[i],sum, n);
		}
		
		//for (int i = 0;i < counts.size();i++)
		//	sum += counts[i];
		sum += n;
		return sum;
	}

	void insert(Trie& root, string s,int &sum,int&nums)
	{
		int len = s.length();
		Trie *p = &root;
		Trie *q;
		//有没有新加
		bool isAdd = false;
		for (int i = len-1;i >=0;i--)
		{
			int id = s[i] - 'a';
			if (p->v==1)
			{
				sum = sum - (len - i-1);
				nums--;
				p->v = 0;
			}
			if (p->next[id]==NULL)
			{
				q = new Trie();
				p->next[id] = q;
				q->v = 0;
				p = p->next[id];
				isAdd = true;
			}
			else {
				p = p->next[id];
			}

		}
		
		
		//有新加的
		if (isAdd)
		{
			sum = sum + len;
			nums++;
			p->v = 1;
		}
	}
};
```