将字符串分成两部分：第一个字符+后面的字符串
首先通过交换 让每一个字符都出现在第一位一次
然后固定第一个字符，求后面所有字符的排列
递归执行第二步
最后将结果集去重

### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        if(s.size() == 0) return res;
        // if(s.size() == 1){
        //     res.push_back("s[0]");
        //     return res;
        // } 
        string r;
        int pos=0;
        depart(s,pos,r,res);
        //结果去重
        sort(res.begin(), res.end());
	    res.erase(unique(res.begin(), res.end()), res.end());

        return res;

    }

    void depart(string s,int pos,string& r,vector<string>& res){
        if(s.size() == 1){
            r+= s[0];
            res.push_back(r);
            r.erase(r.end()-1);
            return;
        }
        while(pos != s.size()){
            char temp = s[0];
            s[0] = s[pos];
            s[pos] = temp;
            r += s[0];
            string ss = s.substr(1);
            depart(ss,0,r,res);
            r.erase(r.end()-1);
            pos++;
        }

    }
};
```