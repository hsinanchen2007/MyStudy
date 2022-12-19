### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> split(const string& s, const char& deli){
        istringstream is(s);
        vector<int> ret;
        string temp;

        while(getline(is, temp, deli)){
            if(temp.empty())
                continue;
            ret.push_back(stoi(temp));
        }

        if(!s.empty() && s.back() == deli)
            ret.push_back(0);
        
        return move(ret);
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1, '.');
        vector<int> v2 = split(version2, '.');

        int i = 0, j = 0;

        while(i < v1.size() || j < v2.size()){
            int c1 = i<v1.size()?v1[i]:0;
            int c2 = j<v2.size()?v2[j]:0;

            if(c1 > c2)
                return 1;
            else if(c1 < c2)
                return -1;
            
            i++, j++;
        }

        return 0;
    }
};
```