### 解题思路
都写在注释了
### 代码

```cpp
class Solution
{
private:


	bool _match(const string& s, int sindex, const string& p, int pindex)
	{
		if(sindex == s.size() ) return no_more_match(p,pindex);  //如果标准串匹配完了，检测模式串是否都为 "a*" 类型，因为*的可以表示0次
        if(pindex == p.size()) return false;                     //因为在上一个判断的下面，保证了标准串没有匹配完，所以如果模式串匹配完则返回false
        if(pindex + 1 < p.size() && p[pindex+1] == '*' ){        // 查看是否满足模式串的第二个为*
            if(s[sindex] == p[pindex] || p[pindex] == '.')       // 并且第一个是满足条件
                return _match(s, sindex+1, p, pindex) || _match(s, sindex, p, pindex+2);   // 递归 第一个去掉，可能多个 | *去掉，可能表示0个
            else
                return _match(s, sindex, p, pindex+2);          // 第一个不满足，直接递归 * 去掉，可能表示0个的情况
            
        }
        else if(s[sindex] == p[pindex] || p[pindex] == '.')     // 如果不满足第二个是 * ，查看第一个是否满足
            return _match(s, sindex+1, p, pindex+1);            // 满足则都进1

        return false;
	}
    // 查看是否有多个可以省去的部分 例如 "a*"  "b*"
    bool no_more_match(const string& p,int pindex){            
        int i = pindex;
        for(;i <p.size();i+=2){
            if((i+1 < p.size() && p[i+1] != '*'))
                return false;
        }
        return i == p.size();
    }

public:
	bool isMatch(string s, string p)
	{
		return _match(s, 0, p, 0);
	}
};
```