### 解题思路
此处撰写解题思路

### 代码

```cpp
bool comp(const pair<char, int>& left, const pair<char, int>& right)
{
    if(left.second > right.second){
        return true;
    }else if(left.second == right.second){
        return left.first < right.first;
    }else{
        return false;
    }
}

class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char, int> count;
        for(int i = 0; i < s.size(); i++){
            count[s[i]]++;
        }
        vector<pair<char, int>> midle;
        for(map<char, int>::iterator ite = count.begin(); ite != count.end(); ite++){
            midle.push_back(make_pair(ite->first, ite->second));
        }
        sort(midle.begin(), midle.end(), comp);
        for(vector<pair<char, int>>::iterator ite = midle.begin(); ite != midle.end(); ite++){
            res += string(ite->second, ite->first);
        }
        return res;
    }
};
```