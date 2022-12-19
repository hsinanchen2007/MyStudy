### 解题思路
本质上可以理解为给一个排序规则，按照这个规则排序，就把这个规则用bool函数写出来就好了，只是这个题不需要用这个规则排序，只需要用这个规则检验一下前后元素是不是都符合这个规则而已。
其实用下面的排序函数可以直接对words进行排序，
	sort(words.begin(),words.end(),paix);
	for(string it:words) cout<<it<<" ";

### 代码

```cpp
class Solution {
public:
	string p;
	bool paix(string& a,string& b){
		int i=0;
		while(i<a.length()&&i<b.length()&&a[i]==b[i]) ++i;
		if(i==a.length()||i==b.length()) return a.length()<b.length();
		return p.find(a[i])<p.find(b[i]);	
	}

	bool isAlienSorted(vector<string>& words, string order) {
		p=order;
		int len=words.size();
		for(int i=1;i<len;++i){
			if(!paix(words[i-1],words[i])) return false;
		}
		return true;
	}
};
```