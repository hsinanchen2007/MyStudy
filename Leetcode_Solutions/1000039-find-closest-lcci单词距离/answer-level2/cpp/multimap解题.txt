- 用multimap（底层是红黑树，平衡二叉搜索树）
- `key` 是单词，`value` 是 序号
- 该结构有序

```
class Solution {
	multimap<string,int> m;
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        for(int i = 0; i < words.size(); ++i)
        	m.insert(make_pair(words[i],i));
        auto it1 = m.lower_bound(word1), end1 = m.upper_bound(word1);
        auto it2 = m.lower_bound(word2), end2 = m.upper_bound(word2);
        int dis = INT_MAX;
        while(it1 != end1 || it2 != end2)
        {
        	while(it1 != end1 && it2 != end2 && it1->second < it2->second)
        		dis = min(dis, it2->second - it1++->second);
        	while(it1 != end1 && it2 != end2 && it2->second < it1->second)
        		dis = min(dis, it1->second - it2++->second);
        	if(it1 == end1 && it2 != end2)
        	{
        		it1--;
        		while(it2 != end2)
        		{
        			dis = min(dis, abs(it1->second - it2++->second));
        		}
        		it1++;
        	}
        	else if(it1 != end1 && it2 == end2)
        	{
        		it2--;
        		while(it1 != end1)
        		{
        			dis = min(dis, abs(it2->second - it1++->second));
        		}
        		it2++;
        	}
        }
        return dis;
    }
};
```
[我的博客](https://michael.blog.csdn.net/article/details/104315448)
