### 解题思路
先对字符串向量进行排序，然后再进行比对。由于是排序后的，所以，如果存在子文件夹的话，一定会在最小文件路径后面。因此，可以使用一个字符串来进行标记。判定是否需要丢弃。
这里有几个坑需要注意下：
- 空字符串或 ' / '
- 文件夹的名称可能是多个字符

只要注意这两个问题，通过这道题目就问题不大。

### 代码

```cpp
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //不能去掉'/'，不然的话，会丢失信息
        string last_str;
        vector<string> res;
        sort(folder.begin(),folder.end());
        for(int i=0;i<folder.size();i++){
            cout << folder[i] << " ";
            //只保存含有有效路径的
            bool is_delete = true;
            if(folder[i].size() > 1 && folder[i][0] == '/'){
                if(last_str.size() == 0){
                    last_str = folder[i];
                    is_delete = false;
                }
                else{
                    int min_size =  min(folder[i].size(), last_str.size());
                    for(int j=0;j<min_size;j++){
                        if(last_str[j] != folder[i][j]) is_delete = false;
                    }
                    if(is_delete && folder[i][min_size] != '/') is_delete = false; 
                    if(!is_delete) last_str = folder[i];
                }
                if(!is_delete) res.push_back(last_str);
            } 
        }
        return res;
    }
};
```