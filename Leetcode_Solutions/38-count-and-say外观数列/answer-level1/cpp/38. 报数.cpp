## 迭代法
```cpp
class Solution {
public:
    int count(string &s, int &j){ //j是引用
        int len=s.size(), cnt=0;
        for(; j<len; j++){
            if(cnt==0) cnt++;
            else if(s[j]==s[j-1]) cnt++;
            else break;
        }
        return cnt;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++){
            string temp;
            int len = ans.size(), cnt;
            int j=0;
            while(j<len){
                cnt = count(ans, j);//j会自己增加              
                temp += (char)cnt+'0';
                temp += ans[j-1];
            }
            ans = temp;
        }
        return ans;
    }
};
```
## 用栈辅助
**存在的问题：用string数组存储迭代的过程数据，用栈存储相同元素，消耗了很多时间和内存**
```cpp
class Solution {
public:
    string countAndSay(int n) {
        string strs[31];
        strs[1] = "1";
        strs[2] = "11";
        for(int i=2; i<n; i++){
            stack<char> st;
            char ch;
            int cnt, len = strs[i].size();
            for(int j=0; j<len; j++){
                ch = strs[i][j];
                if(!st.empty() && ch!=st.top()){
                    cnt = st.size();
                    strs[i+1].push_back((char)(cnt+'0'));
                    strs[i+1].push_back(st.top());
                    while(!st.empty()) st.pop();
                }
                st.push(ch);
            }
            cnt = st.size();
            strs[i+1].push_back((char)(cnt+'0'));
            strs[i+1].push_back(st.top());
        }
        return strs[n];
    }
};
``