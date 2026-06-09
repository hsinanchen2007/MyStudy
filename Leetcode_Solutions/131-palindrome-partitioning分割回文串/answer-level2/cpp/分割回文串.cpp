### 解题思路
直观思路就是找到所有划分，然后判断划分是否回文组成。
针对如何找到所有划分，实际就是排列组合，可用回溯法解决。
首先画树形路径，节点为可选集。路径由每一步的选择组成。
```
              aab
           /   |  \
         ab    b   {}
        / \    |
       b  {}   {} 
```



回溯算法，设置三大变量：当前路径集合，当前路径，当前可选集。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
    vector<vector<string>> paths;
    if(s.length()==0){
        return paths;
    }
    if(s.length()==1){
        paths.push_back(vector<string>({s}));
        return paths;
    }
    vector<string> path;
    string choices = s;
    
    backTrack(paths,path,choices);
    /*
    for(int i=0;i<paths.size();i++){
        for(int j=0;j<paths[i].size();j++){
            cout<<paths[i][j];
        }
        cout<<endl;
    }*/
    return paths;
    }
    int backTrack(vector<vector<string>> &paths, vector<string> &path, string s){
        if(s.length()==0){
            paths.push_back(path);
        }
        
        for(int i=0;i<s.length();i++){
            string c = s.substr(0,i+1);
            if(isHuiWen(c)){
            path.push_back(c);
            s = s.substr(i+1);
            //cout<<s<<endl;
            backTrack(paths,path,s);
            s = c + s;
            path.pop_back();
            }
        }
        return 0;
    }
    int isHuiWen(string s){
        int left = 0;
        int right = s.length()-1;
        while(left<=right){
            if(s[left]!=s[right])
                return 0;
            else{
                left++;
                right--;
            }
        }
        return 1;
    }
};
```