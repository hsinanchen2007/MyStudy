其实一开始本能反应是字典树，奈何我许久没做过字典树的题，有些遗忘了。后来一想不用字典树也可以做得出来，运用STL里的multiset就可以。
为什么想到用multiset呢？
1. 需要对字符串排序。
2. 需要根据searchWord删除不匹配的字符串。
3. 可能会出现重复的字符串。
因此，我们需要一个一直排好序的，插入删除都为O(lgn)的数据结构----红黑树multiset.
```c++
class Solution {
public:
    vector<vector<string> > suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string> > ans;    
        multiset<string> st;
        multiset<string>::iterator t;
		for(int i = 0;i < products.size();i++) st.insert(products[i]);  //先将全部字符串插入集合
		for(int i = 0;i < searchWord.length();i++)  //遍历searchWord每个字符
		{
			for(t = st.begin();t != st.end();t++)   //将不匹配的字符串删掉
			{
				string tmp = *t;
				if(tmp[i] != searchWord[i]) st.erase(t);
			}
			int cnt = 0;    //计数
			vector<string> res; 
			for(t = st.begin();t != st.end() && cnt < 3;t++)    //在满足匹配条件的集合中选前3个(或小于3个)加进去。
			{
				res.push_back(*t);
				cnt++;
			}
			ans.push_back(res);
		} 
		return ans;
    }
};
```
