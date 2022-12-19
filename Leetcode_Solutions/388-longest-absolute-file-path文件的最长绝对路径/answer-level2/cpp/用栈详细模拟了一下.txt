```c++
- 有目录如下：
dir
|    subdir1
|    |       file.ext
|    subdir2 |
|    |       |
0    1       2
```
- 根据\t的个数判断当前为第几层，用栈来保存从根目录到当前目录的上一层路径以及每层目录的
所在层数。例如栈里的元素从栈底到栈顶是<dir,0>,<subdir1,1>当前遍历到的是file.ext其层数
是2,如果当前目录层数小于等于上一层说明该层目录已经遍历完了，将栈顶元素出栈继续比较当
前层数是否小于等于上一层深度，否则将当前路径进栈。所以将file.ext进栈。碰到了 '.'说明
是一个文件，更新答案长度，同时要注意加上'/'的数量。此时栈里的元素从栈底到栈顶是
<dir,0>,<subdir1,1>,<file.ext,2>.遍历到subdir2时此时深度为1栈顶元素深度是2，小于栈顶
元素,说明subdir1已经遍历完了将<file.ext,2>弹出,同时当前路径长度要减去弹出的目录的长度,
此时栈顶是<subdir1,1>深度相等继续弹栈,当前路径长度减去弹出的目录的长度...一直到判断结束

```c++
class Solution {
public:
    typedef pair<string,int> P;
    int lengthLongestPath(string input) {
        int n = input.size(),lastdeep=-1,start=0,curlen=0,res=0;
        stack<P>s;
        for(int i=0;i<=n;i++){
            if(i==n || input[i]=='\n'){
                string path = input.substr(start,i-start);  //一层路径
                int j=0;
                while(j<i-start && path[j]=='\t')j++;   //根据\t的数量判断在第几层
                start = i + 1;
                while(!s.empty() && j<=lastdeep){       //当前层数小于等于上一层深度弹栈,当前长度减去对应的目录长度
                    curlen -= s.top().first.size();
                    s.pop();
                    if(!s.empty())lastdeep = s.top().second;
                }
                lastdeep = j;
                string dir = path.substr(j);        //否则将当前目录进栈
                s.push({dir,j});
                curlen+=dir.size();
                if(dir.find('.')!=-1)res = max(res,curlen+j);   //碰到'.'更新答案
            }   
        
        }
        return res;
    }
};
```