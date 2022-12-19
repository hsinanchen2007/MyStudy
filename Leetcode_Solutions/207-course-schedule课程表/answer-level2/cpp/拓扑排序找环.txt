
```
//执行用时 : 20 ms, 在Course Schedule的C++提交中击败了99.80% 的用户
//欢迎访问我的博客了解详细解析：https://chenzhuo.blog.csdn.net/article/details/91127897

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          //拓扑排序
        //使用标志数组进行访问判别
        //标志数组如果是1/0的，则会产生重复遍历的消耗
        //如果是-1/0/1的，就可以避免重复计算。
        //1：从当前结点开始的拓扑是无环的
        //0：还未遍历过
        //-1：正在遍历
        vector<int> flag(numCourses,0);//标志
        vector<vector<int> > tmp(numCourses);
        if(prerequisites.empty()) return true; 
        for(int i=0;i<prerequisites.size();i++)
        {
            tmp[prerequisites[i][0]].push_back(prerequisites[i][1]);//对于该课程来说需要修的课
        }
        bool ans=true;;
        for(int i=0;i<numCourses;i++)
        {
            ans=ans&&dfs(i,flag,tmp);
        }
        return ans;
    }
    bool dfs(int i,vector<int> &flag,vector<vector<int> > &tmp)
    {
        if(flag[i]==-1)//回路.有环
        {
            return false;
        }
        if(flag[i]==1)
        {
            return true;//可以确定从该结点出发没有回路   
        }
        //第一次访问
        flag[i]=-1;//正在访问
        for(int j=0;j<tmp[i].size();j++)
        {
            if(dfs(tmp[i][j],flag,tmp))
            {
                continue;//这个地方没有回路
            }
            return false;
        }
        flag[i]=1;//该结点出去的每一个结点都访问完了，没有回路
        return true;
    }
};


```
