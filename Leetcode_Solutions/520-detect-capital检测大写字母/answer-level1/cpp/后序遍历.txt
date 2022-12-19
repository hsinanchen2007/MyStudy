后序遍历判断： 除第一个字母以外，其他肯定相同。从后往前判断不相等则直接判断为错误。
最后和第一个字母比较，最后一个大写 而第一个小写 错误
其余为真

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户内存消耗 :8.4 MB, 在所有 C++ 提交中击败了5.55%的用户
```
bool isHigh(char s)
{
if(s>=65 && s<=90) return true;
return false;
}
bool detectCapitalUse(string s) {
//从后面往前面判断
bool temp = isHigh(s[s.size()-1]);
// cout<<temp<<endl;
for(int i = s.size()-2; i>=1;i--)
{
// cout<<isHigh(s[i])<<endl;
if(temp != isHigh(s[i])) return false; //不一致 说明是错的
}
//最后一个大写 而第一个小写 错误
// cout<<isHigh(s[0])<<' '<<s[0];
if(temp==true && isHigh(s[0]) == false) return false;
return true;
}
```
