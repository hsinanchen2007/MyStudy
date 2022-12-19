`28ms` `13.8MB`
```
#include "Solution1249.h"
#include <stack>          // 使用栈stack
#include <vector>         // vector
#include <string>
using namespace std;
class Solution1249 {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack1;
        vector<int> vector1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stack1.push(i);
            }else if(s[i]==')'){
                if(!stack1.empty()){
                    stack1.pop();
                }else{
                    vector1.push_back(i);
                }
            }
        }
        int x = vector1.size();
        while(!stack1.empty()){
            vector1.insert(vector1.begin()+x,stack1.top());//此处为了保证按序存储
            stack1.pop();
        }
        int i = 0, j = 0;
        string ans = "";
        while(i<s.length()){
            if(j<vector1.size()&&i==vector1[j]){
                i++;
                j++;
                continue;
            }
            ans += s[i++];
        }
        return ans;
    }
};
```
