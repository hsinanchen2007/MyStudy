C++

一开始想的dfs，很明显，会超时。。。
```
class Solution {
public:
    void dfs(vector<string>& str_num, string& tmp, string& str_min, 
                int& len, bool visited[])
    {
        if(tmp.size() == len)
        {
            if(tmp < str_min || str_min == "")
                str_min = tmp;
            return;
        }
        for(int i = 0; i < str_num.size(); i++)
        {
            if(visited[i] == false)
            {
                tmp += str_num[i];
                visited[i] = true;
                dfs(str_num, tmp, str_min, len, visited);
                visited[i] = false;
                for(auto j: str_num[i])
                    tmp.pop_back();
            }
        }
    }

    string minNumber(vector<int>& nums)
    {
        int len = 0;
        vector<string> str_num;
        for(int i: nums){
            str_num.push_back(to_string(i));
            len += str_num[str_num.size()-1].size(); 
        }

        string str_min = "", tmp = "";
        bool visited[nums.size()];
        memset(visited, 0, sizeof(bool)*nums.size());

        dfs(str_num, tmp, str_min, len, visited);

        return str_min;
    }
};
```

利用stl，自定义排序。
```
class Solution {
public:
    static bool cmp(string a, string b)
    {
        if(a[0] == b[0])
            return a+b < b+a;
        return a[0] < b[0];
    }

    string minNumber(vector<int>& nums)
    {
        vector<string> str_num;
        for(int i: nums)
            str_num.push_back(to_string(i));

        sort(str_num.begin(), str_num.end(), cmp);

        string rec = "";
        for(string i: str_num)
            rec += i;

        return rec;
    }
};
```

