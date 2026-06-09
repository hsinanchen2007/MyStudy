在Sunt答案的基础上增加了对p中字母数量的检测与维护。如果s中未检测字母数量比p中字母数量小则不可能匹配成功。最后对p中剩余字符的检测也换成了对剩余字母数量的检测。p中字母数量只在s，p对应位置处字母相同或p对应位置为'?'时才会下降。执行时间从4次20ms 20ms 16ms 16ms 缩短到都是4ms。
```
bool isMatch(string s, string p)
{
	int pp = 0;
	int letter = 0;
	for (auto & it : p)
	{
		if (it != '*')
			letter++;
	}//尝试用字母数优化

	for (int star = 0, ps = 0, last = 0, lastLetter; ps<s.length() && (s.size() - ps >= letter);){
		if (pp < p.size() && (s[ps] == p[pp] || p[pp] == '?')){
			++ps;
			++pp;//最简单的情况
			letter--;
		}
		else if (pp < p.size() && p[pp] == '*'){
			last = ps;
			star = ++pp;
			lastLetter = letter;
		}
		else if (star != 0){
			ps = ++last;
			pp = star;
			letter = lastLetter;
		}
		else return 0;
	}

	
	if (letter > 0)
		return false;
	else
		return true;
}
```
