
> 刚开始的思路是不使用栈，直接取出每个单独子串加在一起，不够的位数补0即可。 后来有错误，对于测试用例 "1.1" "1.10"本来应该输出-1，但经过补尾零后判断相等，输出0.
后来想到，每个被' . '分割的数字串具有独立性，即使补尾零我们也应该独立添加，不应和前面结合。于是使用queue。

```c++
class Solution {
public:
    int compareVersion(string version1, string version2) {
	 queue<int> q1, q2;
	 string s1, s2;
	   //提取version1中的数字串
	 for (int i = 0; i<version1.size(); i++){
		 if (version1[i] != '.')s1 += version1[i];
		 else{
			 q1.push(stoi(s1));
			 s1.clear();
		 }
	 }
	 if (s1 != "") q1.push(stoi(s1));
   //提取version2中的数字串
	 for (int i = 0; i<version2.size(); i++){
		 if (version2[i] != '.')s2 += version2[i];
		 else{
			 q2.push(stoi(s2));
			 s2.clear();
		 }
	 }
	 if (s2 != "") q2.push(stoi(s2));
   //如果需要，补尾零
	 if (q1.size()<q2.size()){
		 while (q1.size() != q2.size())
			 q1.push(0);
	 }
	 else if (q1.size()>q2.size()){
		 while (q1.size() != q2.size())
			 q2.push(0);
	 }
     //逐个取出，判断大小
	 while (!q1.empty()){
		 if (q1.front()>q2.front())return 1;
		 else if (q1.front()<q2.front()) return-1;
		 q1.pop(); q2.pop();
	 }
	 return 0;
 }

};

```