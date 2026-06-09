由于题目的特殊性，我声明4个辅助变量
1. vector<int> m_vecRedShort;//存储当前以红色边 入 的i节点最短路径
2. vector<int> m_vecBluShort;//存储当前以蓝色边 入 的i节点最短路径
3. vector<bool> m_vecIsCoverRed;//i节点出发的红边是否已经考虑了？用于剪枝
4. vector<bool> m_vecIsCoverBlu;//i节点出发的蓝边是否已经考虑了？用于剪枝
思路是：
从0节点出发，以广度优先的方式，寻找能构成红蓝交替的边，并更新路径长度。
这里注意，当 路径长度 更新减小时，需要重新设置相应的m_vecIsCover变量为false，用于更新与该节点相关的 其他路径长度。

```
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        m_iMax=std::numeric_limits<int>::max();
        for(int i=0;i<n;++i)//辅助空间初始化
        {
            m_vecRedShort.push_back(m_iMax);
            m_vecBluShort.push_back(m_iMax);
            m_vecIsCoverRed.push_back(false);//所有节点 以红边出 还未考虑
            m_vecIsCoverBlu.push_back(false);//所有节点 以蓝边出 还未考虑
        }
        m_vecRedShort[0]=0;
        m_vecBluShort[0]=0;
        m_iSize=n;
        core(0,red_edges,blue_edges);//从0起点开始，以广度优先的方式搜索
        vector<int> vecRes;
        for(int i=0;i<n;++i)//搜索后，比较 以红边结束路径 和  以蓝边结束路径 中最小值，保存结果 最后return
        {
            int iMin=std::min(m_vecRedShort[i],m_vecBluShort[i]);
            if(iMin==m_iMax)
                vecRes.push_back(-1);
            else
                vecRes.push_back(iMin);
        }
        return vecRes;
    }
    void core(int n,vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
    {
        if(n<0)
            return;
        bool isNeedRed=(m_vecBluShort[n]!=m_iMax)&&!(m_vecIsCoverRed[n]);//该节点有以蓝边进，所以需要红边出
        bool isNeedBlu=(m_vecRedShort[n]!=m_iMax)&&!(m_vecIsCoverBlu[n]);//该节点有以红边进，所以需要蓝边出
        set<int> setNeed;//存储能到达的下一节点
        for(int i=0;i<red_edges.size()&&isNeedRed;++i)//需要红边出，所以搜寻红边
        {
            if(red_edges[i][0]==n)
            {
                int iNextNode=red_edges[i][1];
                setNeed.insert(iNextNode);//存储能到达的下一节点
                if(m_vecRedShort[iNextNode]>m_vecBluShort[n]+1)//下一节点以红边进
                {    
                    m_vecRedShort[iNextNode]=m_vecBluShort[n]+1;
                    m_vecIsCoverBlu[iNextNode]=false;//因为节点最短路径值减小了，需要重新考虑计算
                }
            }
            m_vecIsCoverRed[n]=true;
        }
        for(int i=0;i<blue_edges.size()&&isNeedBlu;++i)//需要蓝边出，所以搜寻蓝边
        {
            if(blue_edges[i][0]==n)
            {
                int iNextNode=blue_edges[i][1];
                setNeed.insert(iNextNode);//存储能到达的下一节点
                if(m_vecBluShort[iNextNode]>m_vecRedShort[n]+1)//下一节点以蓝边进
                {    
                    m_vecBluShort[iNextNode]=m_vecRedShort[n]+1;
                    m_vecIsCoverRed[iNextNode]=false;//因为节点最短路径值减小了，需要重新考虑计算
                }
            }
            m_vecIsCoverBlu[n]=true;
        }
        
        for(int i=0;i<m_iSize;++i)//探索 能到达的 且 没有考虑到的  下一节点   最后统一迭代，实现广度优先搜索
        {
           if((setNeed.end()!=setNeed.find(i))&&(!m_vecIsCoverRed[i]||!m_vecIsCoverBlu[i]))
                core(i,red_edges,blue_edges);
        }
        return;
    }
    vector<int> m_vecRedShort;//存储当前以红色边 入 的i节点最短路径
    vector<int> m_vecBluShort;//存储当前以蓝色边 入 的i节点最短路径
    vector<bool> m_vecIsCoverRed;//i节点出发的红边是否已经考虑了？用于剪枝
    vector<bool> m_vecIsCoverBlu;//i节点出发的蓝边是否已经考虑了？用于剪枝
    int m_iMax;//int类型的最大值，用于初始化最短路径
    int m_iSize;//存储图节点数目
};
```
执行用时 :140 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :14.2 MB, 在所有 C++ 提交中击败了100.00%的用户
