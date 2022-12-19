```
class Solution {
public:
    void getSubIP(string remain_s, string prefix, int remain_parts, vector<string>& ans){
        // remain_s 是剩下待确定的字符串，prefix是已经确定的(开头多一个.)，parts是还剩几段可以分配
        if(remain_s.size() == 0 && remain_parts == 0){   //只有两者同时为0才是合法解
            prefix.erase(prefix.begin());   //此时是类似于.1.1.1.1的格式，要删除第一个多余的.
            ans.push_back(prefix);
            return ;
        }
        else if(remain_s.size() == 0 || remain_parts == 0){     //不然只有一个为0都不是合法解
            return ;
        }
        if(remain_s.size() > 3*remain_parts)        // 因为每一段最多三位，所以可以通过这个剪枝
            return ;
        int cnt = 0;
        string tmp;
        while(remain_s.size()>0 && cnt <3){     //一个ip一段最多三位
            cnt ++;
            tmp += remain_s[0];
            if(cnt == 3 && tmp > "255")
                break;
            remain_s.erase(remain_s.begin());
            getSubIP(remain_s, prefix+'.'+tmp, remain_parts-1, ans);
            if(tmp == "0")      //如果0出现在前面，则只能是单独一个0，不能做为高位，故结束上面一行后break;
                break;
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        getSubIP(s, "", 4, ret);
        return ret;
    }
};
```
