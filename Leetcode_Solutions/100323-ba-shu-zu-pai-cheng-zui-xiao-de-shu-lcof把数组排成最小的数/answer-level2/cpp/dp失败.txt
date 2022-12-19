### 解题思路
dp思想：全排列，剪枝树
在第202个测试用例超时T^T

### 代码

```cpp
string res = "";
bool comparestring(string str1, string str2)
{
	return str1 + str2>str2 + str1;
}
void permutation(vector<string>& strs, int n)
{
	if (n == 1)
	{
		string tmp = "";
		for (int i = 0; i<strs.size(); ++i)
			tmp += strs[i];
		if ((res == "") || (tmp<res)) res = tmp;
		return;
	}
	bool flag = true;//如果在某一步后面的都大于当前的，则全被剪掉了
	for (int i = strs.size() - n; i<strs.size(); ++i)
	{
		if (comparestring(strs[strs.size() - n], strs[i]))
		{
			string temp = strs[i];
			strs[i] = strs[strs.size() - n];
			strs[strs.size() - n] = temp;

			permutation(strs, n - 1);

			temp = strs[i];
			strs[i] = strs[strs.size() - n];
			strs[strs.size() - n] = temp;
			flag = false;
		}
	}
	if (flag) permutation(strs, n - 1);//强制进入下一层递归

}
string minNumber(vector<int>& nums) {
	vector<string> strs;
	for (int i = 0; i < nums.size(); ++i)
	{
		strs.push_back(to_string(nums[i]));
		res += to_string(nums[i]);
	}
	permutation(strs, strs.size());
	return res;

}
```
最后抄了个答案，失败。。。
```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(auto num:nums)
            strs.push_back(to_string(num));
        sort(strs.begin(),strs.end(),compare);
        for(auto str:strs)
            res+=str;
        return res;
    }
private:
    static bool compare(const string &a,const string &b)
    {
        return a+b<b+a;
    }
};
```