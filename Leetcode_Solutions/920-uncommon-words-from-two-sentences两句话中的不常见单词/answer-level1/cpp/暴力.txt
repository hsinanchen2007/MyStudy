没哈好说的

```
class Solution {
public:
    
    vector<string> split(const string &str, const string &pattern) {
        //const char* convert to char*
        char * strc = new char[strlen(str.c_str())+1];
        strcpy(strc, str.c_str());
        vector<string> resultVec;
        char* tmpStr = strtok(strc, pattern.c_str());
        while (tmpStr != NULL)
        {
            resultVec.push_back(string(tmpStr));
            tmpStr = strtok(NULL, pattern.c_str());
        }

        delete[] strc;

        return resultVec;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        auto array1 = split(A, " ");
        map<string, int> map;
        for (auto s : array1) {
            if (map.count(s) == 0) {
                map[s] = 1;
            } else {
                map[s] = 2;
            }
        }
        auto array2 = split(B, " ");
        for (auto s : array2) {
            if (map.count(s) == 0) {
                map[s] = 1;
            } else {
                map[s] = 2;
            }
        }
        
        vector<string> res;
	    for(auto iter = map.begin(); iter != map.end(); iter++) {
	        if (iter->second == 1) {
	            res.emplace_back(iter->first);
	        }
	    }
        return res;
        
    }
};
```