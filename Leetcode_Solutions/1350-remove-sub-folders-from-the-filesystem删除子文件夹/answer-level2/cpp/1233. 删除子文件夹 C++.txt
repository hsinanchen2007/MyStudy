### 解题思路
思路：
1.排序，排序后，根文件夹一定在前面，子文件夹一定在后面
2.设置set，如果当前文件夹的前缀在set中不存在，则说明是根文件夹，否则是子文件夹丢弃；


### 代码

```cpp
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());
        unordered_set<string> strset;
        vector<string> result;

        strset.insert(folder[0]);
        result.push_back(folder[0]);
        for (int i = 1; i < folder.size();i++){
            string &str =folder[i];
            string s ="/";
            bool find = false;
            for (int j = 1; j < str.size();j++){
                if(str[j] == '/'){
                    if(strset.count(s)){
                        find = true;
                        break;
                    }
                }

                s += str[j];
            }

            if(!find){
                strset.insert(str);
                result.push_back(str);
            }
        }

        return result;
    }
};
```
进一步优化，由于是字典序排序，因此如果是根文件夹，则后面的子文件夹一定以它为开头，否则，则是根文件夹

```cpp
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());
        vector<string> result;
        string root = folder[0];

        result.push_back(root);
        for (int i = 1; i < folder.size();i++){
            if(folder[i].find(root+"/") == 0){
                continue;
            }else{
                root = folder[i];
                result.push_back(root);
            }
        }

        return result;
    }
};
```
