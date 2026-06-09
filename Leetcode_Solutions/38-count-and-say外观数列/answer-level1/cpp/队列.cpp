### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {  //队列的方法，尽管有点慢，但是吧，对队列熟悉了很多
        if(n==0) return "";
        string s="1";
        string tmp;
        int count=1;
        queue<string>que;
        que.push("1");
        n=n-1;
        while(n){
            s=que.front();
            que.pop();
            int size=s.length();
            for(int i=0;i<size;i++){
                while(s[i]==s[i+1]&&i<size-1) {
                    count++;
                    i++;
                    continue;
                }
                
            tmp=tmp+to_string(count)+s[i];
            count=1;
            }
            que.push(tmp);
            tmp="";
            count=1;
            n--;
        }
        return que.front();
    }
};
```