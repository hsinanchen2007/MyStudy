### 解题思路
核心思路：此题的实质就是对一个可能含重复字符的字符串，求它重新排列各字符后的字符串集（不能含重复字符串），因此利用递归处理。
执行用时 :364 ms, 在所有 C++ 提交中击败了8.61%的用户
内存消耗 :25.5 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
    
public:
    vector<string> permutation(string s) {
        unordered_set<string>uset;
        vector<bool>visited(s.size(),false);
        vector<string>result;
        permutation(s,"",uset,visited,result);
        return result;
    }
    void permutation(string s,string r,unordered_set<string>&uset,vector<bool>&visited,vector<string>&result){
        if(s.size()==r.size()){
            if(uset.find(r)==uset.end()){
                uset.insert(r);
                result.push_back(r);
            }   
            return;
        }
        for(int i=0;i<s.size();i++){
            if(visited[i])continue;
            visited[i]=true;
            permutation(s,r+s[i],uset,visited,result);
            visited[i]=false;
        }
    }
};
```