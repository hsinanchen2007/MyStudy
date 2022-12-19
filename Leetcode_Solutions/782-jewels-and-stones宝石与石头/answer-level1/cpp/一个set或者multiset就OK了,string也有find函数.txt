```
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		set<int> s;
		for (int i = 0; i < J.length(); i++){
			s.insert(J[i]);
		}
		int count = 0;
		for (int i = 0; i < S.length(); i++){
			if (s.find(S[i]) != s.end())
				count++;
		}
		return count;
	}
};
```


```
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		multiset<int> s;
		for (int i = 0; i < S.length(); i++){
			s.insert(S[i]);
		}
		int count = 0;
		for (int i = 0; i < J.length(); i++){
			count += s.count(J[i]);
		}
		return count;
	}
};
```
```
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int count = 0;
		for (int i = 0; i < S.length(); i++){
			if (J.find(S[i]) != J.npos)
				count++;
		}
		return count;
	}
};
```
