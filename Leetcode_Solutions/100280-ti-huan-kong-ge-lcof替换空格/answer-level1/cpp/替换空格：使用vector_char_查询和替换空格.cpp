class Solution {
public:
    string replaceSpace(string s) {
        /*
        1.找出空格
        2.按字符分别替换掉
        */
        vector<char> vs;
        vs.assign(s.begin(), s.end());
        vector<char> ans;
        for(int i=0; i<vs.size(); i++)
        {
            if(vs[i]!=' ')
                ans.push_back(vs[i]);
            else if(vs[i]==' ')
            {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
        }
        string str_ans;
        str_ans.assign(ans.begin(), ans.end());
        return str_ans;
    }
};