### 分析
* '.'匹配任意单个字符
* 'x*'匹配0个或多个x字符

'.'好处理，但是*前面既可以是普通字符也可以是'.',而且0个或多个也使得情况更加复杂,使得匹配情况和当前位置前后都有关联。不妨从局部开始考虑，用递归的方式来解决。
### 回溯
设输入文本串s,模式串为p,当前s的匹配位置为sIndex，p的位置为pIndex。函数doMatch(s,sIndex,p,pIndex)表示s串从sIndex开始的子串与模式串p中从pIndex开始的子串是否匹配（均包括Index位置）。
1. 当前位置的匹配情况为:
```c++
bool currentMatch = s[sIndex] == p[pIndex] || p[pIndex] == '.';
```
2. 除了当前位置的情况，还应该考虑到p中下一个位置可能是'*'：
    * 如果当前位置是不匹配，则要想结果匹配，只能使x\*匹配0个x字符。即使当前位置匹配，仍有可能实际要跳过x*才能使得最终的结果匹配，例如：s = abbc, p = ab\*bbc,b\*必须一个都不匹配才能使得p中后面两个bb与s中的bb匹配。因此，只要下一个位置是\*,就要考察跳过x\*,此时sIndex不变，令pIndex += 2跳过\*即可:
    ```c++
    doMatch(s, sIndex, p, pIndex + 2)
    ```
    * 如果当前位置匹配，则直接令sIndex+1考察sIndex的下一个位置（是否匹配x*）:
    ```c++
    doMatch(s, sIndex + 1, p, pIndex)
    ```
3. 当p中下一个位置不是\*时：
    * 当前位置不匹配,则以这个位置开始的字串也不会匹配，返回false
    * 当前位置匹配，则继续考察下一个位置：
    ```c++
    doMatch(s, sIndex + 1, p, pIndex + 1);
    ```
### 代码
```c++
    // 40ms
    bool isMatch(const string& s,const  string& p)
    {
        return doMatch(s, 0, p, 0);
    }
    // 考察s串从sIndex开始的子串与模式串p中从pIndex开始的子串是否匹配（均包括开始位置直到末尾）。
    bool doMatch(const string& s, int sIndex, const string& p, int pIndex)
    {
		if (pIndex >= pSize) return sIndex >= sSize;

		bool currentMatch = sIndex < sSize && (s[sIndex] == p[pIndex] || p[pIndex] == '.');

        if(pIndex + 1 < pSize && p[pIndex + 1] == '*')
        {
			// *匹配0个字符(无论当前字符匹不匹配这都有可能s = abbc, p = ab*bbc) || 当前字符匹配并尝试s中的下一个字符
			return doMatch(s, sIndex, p, pIndex + 2) || (currentMatch && doMatch(s, sIndex + 1, p, pIndex));
        }
        else // 没有*
        {
			// 正常匹配，包括了.
            // 匹配上就考察下一个，否则 return false
			return currentMatch && doMatch(s, sIndex + 1, p, pIndex + 1);
        }
    }
```

### 动态规划
考虑s = "aaaaaaaaaaaaab",p = "a*a*a*a*a*a*a*a*a*a*c",通过控制台打印就会发现有大量重复的相同参数的doMatch调用，这主要是出现在存在x\*的情况下，回溯时出现的，此时可以考虑动态规划，记录下已经遇到过的情况。
### 代码
```c++
// 4ms
bool isMatch(const string& s,const  string& p)
{
    mem = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
    return doMatch(s, 0, p, 0);
}
bool doMatch(const string& s,int sIndex, const string& p, int pIndex)
{
	if (mem[sIndex][pIndex] != -1)
	{
		return mem[sIndex][pIndex];
	}
	bool res;
    if(pIndex >= p.size()) res = (sIndex >= s.size());
    else
    {
        bool currentMatch = (sIndex < s.size() && (s[sIndex] == p[pIndex] || p[pIndex] == '.'));
        if(pIndex+1 < p.size() && p[pIndex+1] =='*')
        {
            res = doMatch(s, sIndex, p, pIndex+2) || // 忽略x*
                currentMatch&&doMatch(s, sIndex + 1, p, pIndex); // 如果*前的字符匹配，则将s前进一位
        }
        else
        {
            res = currentMatch&&doMatch(s, sIndex+1, p, pIndex + 1);
        }
    }
    mem[sIndex][pIndex] = res;
    return res;
}
```