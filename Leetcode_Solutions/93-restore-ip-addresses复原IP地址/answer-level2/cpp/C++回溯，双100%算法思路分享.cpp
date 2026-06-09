### 解题思路
这道题是我在集中做回溯类问题时遇到的，因此一上来就打算用回溯的方法来解决。
该问题的关键是我们如何取构造树，来展示回溯的过程。
好多大佬的解答都是在每个状态下，有三种分支选择，即一位数，两位数，三位数。
我的策略是，每个分支都有两种选择，即选择点号分隔，还是选择该位数字与最近一次得到的
数字（代码中为变量lastnum)组成新的数字(nownum)。
该算法需要对剪支条件充分考虑，以达到最优效率。


### 代码

```cpp
class Solution {
public:
    vector<string> res;
    string path;
    string temp = "";
    bool pro_point = false;

    void dfs(int start,int len,int len_now,int point,int lastnum){
        if(len_now == len){
            res.push_back(path);
            return;
        }
        /*for(int i = start;i < len;i++){
        }*/
        char now = path[path.length()-1];
        if(point == 0 && len - start >= 3 && len - start <= 9 && now!='.'){
            path += '.';
            dfs(start,len,len_now,point+1,0);
            path.pop_back();
        }
        int nownum = lastnum*10 + (temp[start] - '0');
        if(point == 0 && len - start >= 4 && nownum <= 255 && !(now!='.' && lastnum==0)){
            path += temp[start];
            dfs(start+1,len,len_now+1,point,nownum);
            path.pop_back();
        }
        if(point == 1 && len - start >= 2 && len - start <= 6 && now!='.'){
            path += '.';
            dfs(start,len,len_now,point+1,0);
            path.pop_back();
        }
        if(point == 1 && len - start >= 3 && nownum <= 255 && !(now!='.' && lastnum==0)){
            path += temp[start];
            dfs(start+1,len,len_now+1,point,nownum);
            path.pop_back();
        }
        if(point == 2 && len - start >= 1 && len - start <= 3 && now !='.'){
            path += '.';
            dfs(start,len,len_now,point+1,0);
            path.pop_back();
        }
        if(point == 2 && len - start >= 2 && nownum <= 255 &&!(now!='.' && lastnum==0)){
            path += temp[start];
            dfs(start+1,len,len_now+1,point,nownum);
            path.pop_back();
        }
        if(point == 3 && len - start >= 1 && nownum <= 255 && !(now!='.' && lastnum==0)){
            path += temp[start];
            dfs(start+1,len,len_now+1,point,nownum);
            path.pop_back();
        }
    }


    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(len > 12 || len < 4)
            return res;
        if(s == "0000"){
            res.push_back("0.0.0.0");
            return res;
        }
        path += s[0];
        temp = s;
        int last = (path[0]-'0');
        dfs(1,len,1,0,last);
        return res;
    }
};
```