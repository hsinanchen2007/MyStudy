运行到第156个用例时就超时了，哪位大佬帮再优化下。

```
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ret;
        set<int> st;   //不能用vector来进行深度优先搜索，因为vector没有去重的功能

        for (int i = 0; i < pid.size(); i++) {
            /*原先只能通过8个用例，增加了下面这个if分支的代码就通过了155个用例。
            原先代码第9个用例开始就总是运行超时，需要进行优化。
            下面的优化的含义是如果要删除的kill是整棵树的根节点，说明所有的进程都需要删除。*/
            if (pid[i] == kill && ppid[i] == 0) {
                ret.assign(pid.begin(), pid.end());
                return ret;
            }

            /*因为要删除的kill进程有可能是一个叶子节点，没有孩子了。因此先在子进程中搜索一下，
            如果能够搜索到，直接把这个要删除的kill进程放入到st中，然后就跳出。
            之所以跳出是为了节省时间，pid中的进程号不可能重复，只要找到了一个，就不需要继续往下搜索了*/
            if (pid[i] == kill) {
                st.insert(kill);
                break;
            }
        }  

        /*递归搜索，深度优先遍历*/
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid[i] == kill) {        
                killProc(pid, ppid, kill, st);
            }
        }

        ret.assign(st.begin(), st.end());
        return ret;

    }

    void killProc(vector<int>& pid, vector<int>& ppid, int killproc, set<int>& st) {
        //vector<int> vc;
        st.insert(killproc);

        //vector<int>::iterator it = ppid.find(killproc);  //vector没有find这个库函数
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid[i] == killproc) {
                killProc(pid, ppid, pid[i], st);                
            }
        }
        /*
        if (it != ppid.end()) {
            vc.push_back(killproc);

            killProc(pid, ppid, pid[it - ppid.begin()], vc);
        }
        */
        return;
    }
};
```


