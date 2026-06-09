  首先为了简单起见，我们约定[a-z]代表a-z中的任意单个字符，即a或b或c...z，匹配模式p为P，待匹配字符串s为S。

  我们先分析一下P，P中可能出现[a-z]、.以及*。.可以匹配任意的[a-z]。由此我们得到4个基本的匹配模式
```
  1. [a-z] (匹配a或b或c...等)
  2. . (匹配任意单个的a-z)
  3. [a-z]* (匹配0个或多个的a或b或c...)
  4. .* (匹配0个或任意多个的a-z)
```
  由于[a-z]*和.*的特殊性，我们进一步得出
```
  1. 任意多个连续的[a-z]*等价于一个[a-z]*
  2. 任意多个连续的.*等价于一个.*
```
  注意这里必须是连续的，否则不成立。
  根据匹配的规则我们可以得到这样一个定义，**存在某种组合，使得P能完全匹配S，即P和S同时从起始位置匹配，匹配结束后P和S都能同时走到结束的位置，这时候P和S就是匹配的，反之P和S不匹配**。
  [a-z]和.没有任何难度，这两种模式能且只能一个字符，并且[a-z]是精确匹配，难点在于[a-z]*和.*，这两种模式可以匹配0或任意的长度，还有各种边界条件。
  以下几种情况可以认为是此次匹配失败的：
```
  1. P中[a-z]和S中对应位置字符不匹配
  2. S已经结束，P还未结束，并且P中的剩余位置包含有[a-z]或.
  3. P已经结束，S还未结束
```
   由于.*可以匹配任意长度，[a-z]*可以匹配任意长度的a-z，这两种模式我们总是采取贪婪算法，即总是先匹配最长的，当后面的模式不匹配时，再回退到这里减少一个匹配。
  开始匹配前，先扫描一遍P，生成上面的4种匹配模式并保存状态，再用生成的模式匹配S，[a-z]*和.*需要回溯，用一个栈来保存[a-z]*和.*的回溯，遇到[a-z]*和.*时就把当前状态入一次栈，后面模式不匹配时就把上一次的状态出栈再继续匹配，直到栈为空时仍匹配失败，则P和S匹配失败

示例代码

```
enum e_regex_type {
    e_char = 1,
    e_dot,
    e_char_wildcard,
    e_dot_wildcard,
    e_invalid
};

struct regex_rollback_t {
    string::const_iterator start;
    string::const_iterator end;
    int regex_idx;
    enum e_regex_type rtype;
};

class Solution {
public:
    void regex_backpoint_put(vector<struct regex_rollback_t> &vrrb,
							 const string::const_iterator &start, 
                             const string::const_iterator &end, int idx, 
                             enum e_regex_type rtype)
    {
        struct regex_rollback_t rrb;
        
        rrb.start = start;
        rrb.end = end;
        rrb.regex_idx = idx;
        rrb.rtype = rtype;
        vrrb.push_back(rrb);
    }
    
	void regex_backpoint_get(vector<struct regex_rollback_t> &vrrb,
		string::const_iterator &pos, int &idx)
	{
		struct regex_rollback_t rrb;
		
		rrb = vrrb.back();
		vrrb[vrrb.size() - 1].end--;
		if (rrb.end - 1 == rrb.start)
			vrrb.pop_back();
		pos = rrb.end - 1;
		idx = rrb.regex_idx;
	}
	
    bool isMatch(string s, string p) {
        pair<enum e_regex_type, string::const_iterator> sta;
        vector<pair<enum e_regex_type, string::const_iterator>> mstat;
        vector<struct regex_rollback_t> vrrb;
        struct regex_rollback_t rrb;
        string::const_iterator send = s.cend();
        string::const_iterator it, it2, it3, it4;
        enum e_regex_type rtype;
        int i, ri;
        
		/* scan regex expression and construct state machine */
        for (it = p.cbegin(), it2 = p.cend(); it != it2; it++) {
            switch (*it) {
                default:
                    mstat.push_back(make_pair(e_char, it));
                    break;
                case '.':
                    mstat.push_back(make_pair(e_dot, it));
                    break;
                case '*':
                    if (!mstat.empty()) {
                        sta = mstat.back();
                        mstat.pop_back();
                        rtype = sta.first;
                        it3 = sta.second;
                        switch (rtype) {
                            case e_char:
                                if (!mstat.empty()) {
                                    sta = mstat.back();
                                    rtype = sta.first;
                                    it4 = sta.second - 1;
                                    if (rtype == e_char_wildcard && *it3 == *it4)
                                        mstat.pop_back();
                                }
                                sta = make_pair(e_char_wildcard, it);
                                break;
                            case e_dot:
                                if (!mstat.empty()) {
                                    sta = mstat.back();
                                    rtype = sta.first;
                                    if (rtype == e_dot_wildcard)
                                        mstat.pop_back();
                                }
                                sta = make_pair(e_dot_wildcard, it);
                                break;
                            default:
                                sta = make_pair(e_invalid, it);
                                break;
                        }
                    } else {
                        return false;
                    }
                    mstat.push_back(sta);
                    break;
            }
        }
		
        /* do actually regex match */
        i = 0;
		ri = mstat.size() - 1;
        it = s.cbegin();
        while (1) {
            while (i < ri) {
                sta = mstat[i];
                rtype = sta.first;
                it2 = sta.second;
                
                switch (rtype) {
                    case e_char:
                        if (it == send || *it2 != *it) {
                            if (vrrb.empty())
                                return false;
                            else {
                                regex_backpoint_get(vrrb, it, i);
                            }
                        } else {
                            i++;
                            it++;
                        }
                        break;
                    case e_dot:
						if (it == send) {
						    if (vrrb.empty())
                                return false;
                            else {
                                regex_backpoint_get(vrrb, it, i);
                            }
						} else {
							i++;
							it++;
						}
                        break;
                    case e_char_wildcard:
                        it3 = it;
                        while (it3 != send && *it3 == *(it2 - 1))
                                it3++;           
						if (it3 > it) {
							regex_backpoint_put(vrrb, it, it3, i + 1, e_char_wildcard);
							it = it3;
						}
                        i++;
                        break;
                    case e_dot_wildcard:
						if (it != send)
							regex_backpoint_put(vrrb, it, send, i + 1, e_dot_wildcard);
                        it = send;
                        i++;
                        break;
                    default:
                        i++;
                        it++;
                        break;
                };
            }
            
            if (i <= ri) {
                sta = mstat[i];
                rtype = sta.first;
                it2 = sta.second;

                switch (rtype) {
                case e_char:
                    if (it == send - 1 && *it == *it2)
                        return true;
                    if (vrrb.empty())
                        return false;
                    else
                        regex_backpoint_get(vrrb, it, i);
                    break;
                case e_dot:
                    if (it == send - 1)
                        return true;
                    if (vrrb.empty())
                        return false;
                    else
                        regex_backpoint_get(vrrb, it, i);
                    break;
                case e_char_wildcard:
                    it3 = it;
                    while (it3 != send && *it3 == *(it2 - 1))
                        it3++;
                    if (it3 == send)
                        return true;
                    if (vrrb.empty())
                        return false;
                    else
                        regex_backpoint_get(vrrb, it, i);
                    break;
                case e_dot_wildcard:
                    return true;
                default:
                    return false;
                }
            } else {
                if (it == send)
                    return true;
                return false;
            }
        }
    }
};
```
