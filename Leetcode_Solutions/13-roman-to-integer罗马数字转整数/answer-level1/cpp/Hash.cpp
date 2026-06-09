### 解题思路
使用初学的哈希表如下

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
 unordered_map<string,int> m = {{"I", 1}, {"IV", 4}, {"IX", 9}, {"V", 5}, {"X", 10}, {"XL", 40}, {"XC", 90}, {"L", 50}, {"C", 100}, {"CD", 400}, {"CM", 900}, {"D", 500}, {"M", 1000}};
 int sum=0;
 auto it=m.begin();
 for(int i=0;i<s.length();i++)
 {
 	if(m[s.substr(i,1)]>=m[s.substr(i+1,1)])
 	{
 		it=m.find(s.substr(i,1));	
 		sum=sum+it->second;
	 }
	 else
	 {
	 	it=m.find(s.substr(i,2));
	 	sum=sum+it->second;
	 	i++;
	 }
 }
 return sum;
    }
};
```