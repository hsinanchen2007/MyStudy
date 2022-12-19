C++ d 很笨的解题方法
奥里给！


```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vec;
        vec = split(str,  " ");
        if(vec.size() != pattern.size()){
            return false;
        }

        map<string, char> s_map;
        set<char> c_set;

        for(int i = 0; i < vec.size(); ++ i){
            if(s_map.find(vec[i]) == s_map.end()){
                s_map[vec[i]] = pattern[i];
                int set_t =  c_set.size();
                c_set.insert(pattern[i]);
                if(c_set.size() == set_t){
                    return false;
                }

            }
            else{
                if(s_map[vec[i]] != pattern[i]){
                    return false;
                }
            }

        }


        return true;
    }

private:
    vector<string> split(const string &str, const string &pattern)
    {
        //cout << "1111" << endl;
        vector<string> res;
        if(str == "")
            return res;
        //在字符串末尾也加入分隔符，方便截取最后一段
        string strs = str + pattern;
        size_t pos = strs.find(pattern);

        while(pos != strs.npos)
        {
            string temp = strs.substr(0, pos);
            res.push_back(temp);
            //去掉已分割的字符串,在剩下的字符串中进行分割
            strs = strs.substr(pos+1, strs.size());
            pos = strs.find(pattern);
        }
        return res;
    }
};
```