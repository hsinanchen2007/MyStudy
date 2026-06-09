### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
#define SIZE 26
    struct node;
    struct chc
    {
        int ncount;//以这个节点为结束点的单词的数量
        node * pL;//指针

    };
    struct node
    {
        chc dict[SIZE];
    };
    int minimumLengthEncoding(vector<string>& words) {
        //如果没得#号这题目没法做 待会儿可以思考下
        //全局最优 一看到就想到动态规划
        //n+1最优=>n最优
        //从尾部开始的包含子串，如果存在包含就拼在一起
        //构建1颗树
        //而他只是求最小长度，未必要把树构建出来
        //一边构建一边统计
        int nLength=0;
        int nSize=words.size();
        node *pRoot=new node();
        memset(pRoot,0,sizeof(node));
        int nWordLen=0;
        chc * pFather=nullptr;
        node * pCurrentNode=nullptr;
        for(int i=0;i<nSize;++i)
        {
            nWordLen=words[i].size();
            pFather=nullptr;//父节点指针
            pCurrentNode=pRoot;//当前节点
            //bool bNew=false;
            int nLongestWordLen=0;//找到的跟他路径重叠，被包含的最长的字符串
            if(nWordLen<=0)
            {
                continue;
            }
            for(int j=nWordLen-1;j>=0;--j)
            {
                if(pCurrentNode==nullptr)
                {
                    //需要申请新的节点了
                    //表示产生了新的节点 有更长的字符串出现
                    pCurrentNode=new node();
                    memset(pCurrentNode,0,sizeof(node));
                    pFather->pL=pCurrentNode;
                    //bNew=true;
                }
                if(pCurrentNode->dict[words[i][j]-'a'].ncount>0)
                {
                    //这里已经处理了 后面再处理一样长的不好
                    nLongestWordLen= nWordLen-j;//更新被包含的最长字符串
                    pCurrentNode->dict[words[i][j]-'a'].ncount=0;//因为这个字符串已经被覆盖了，那么他的痕迹就抹掉
                }
                pFather=&(pCurrentNode->dict[words[i][j]-'a']);//改变父节点
                pCurrentNode=pCurrentNode->dict[words[i][j]-'a'].pL;//改变当前节点
            }
            //这指针肯定不为空
            ++(pFather->ncount);
            //然后进行统计
            if(pCurrentNode!=nullptr)
            {
                //表示这是个被包含的字符串，忽略掉
                --(pFather->ncount);
                continue;
            }
            //到了这里 那么 新字符串要么更长，要么跟某个字符串一样长
            if(nLongestWordLen==0)
            {
                //没公共部分
                nLength+=nWordLen+1;//整个都是新字符串
            }
            else
            {
                nLength+=nWordLen-nLongestWordLen;
            }
        }
        return nLength;
    }
};
```
如果不定义 ncount 这个字段 ，内存会小，构建完毕字典树之后重新扫描一遍