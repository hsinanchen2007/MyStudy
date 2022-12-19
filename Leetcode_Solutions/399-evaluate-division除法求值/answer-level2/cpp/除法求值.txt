### 解题思路
用邻接表建立图，用哈希表建立字母到邻接表对应头结点的对应，用DFS搜寻结果


### 代码

```cpp

#define Vertex string
#define WeightType double
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
    AdjVNode(string v,WeightType weight):AdjV(v),Weight(weight),Next(NULL){}
};

unordered_map<string,bool> mapVisited;
double DFS(unordered_map<string,PtrToAdjVNode>& mapEquations,string first,string second)
{
    // if(mapEquations.find(first)==mapEquations.end()||mapEquations.find(second)                      ==mapEquations.end())
    // {
    //     return 0;
    // }
    if(first==second)
    {
        return 1.0;
    }

    mapVisited[first]=true;
    PtrToAdjVNode node=mapEquations[first];
    double res=0;
    while(node->Next)
    {
        PtrToAdjVNode tmpNode=node->Next;
        if(mapVisited[tmpNode->AdjV]==false)
        {
            
            res=tmpNode->Weight*DFS(mapEquations,tmpNode->AdjV,second);
            if(res!=0)
                break;
        }
        
        

        node=node->Next;
    }
    return res;

}

void resetVisited(unordered_map<string,PtrToAdjVNode>& mapEquations)
{
     for(auto iter=mapEquations.begin();iter!=mapEquations.end();iter++)
        {
            mapVisited[iter->first]=false;
        }
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {


        std::unordered_map<string,PtrToAdjVNode > mapEquations;
        //用邻接表建立图
        for(int i=0;i<equations.size();i++)
        {
            vector<string> tmpVec=equations[i];
            if(tmpVec[0]!=tmpVec[1])
            {
                if(values[i]==0)
               {
                    //如果被除数为0
                    PtrToAdjVNode newNode=new AdjVNode(tmpVec[0],0);//这个权重存为0
                    mapEquations[tmpVec[0]]=newNode;
                }
                else {

                
                if(mapEquations.find(tmpVec[0])==mapEquations.end())
                {
                    //如果还没存在
                    PtrToAdjVNode newNode=new AdjVNode(tmpVec[0],-1);//头结点权重存为-1
                    mapEquations[tmpVec[0]]=newNode;

                }
              
                    //把tmpVec[1]插入tmpVec[0]
                    PtrToAdjVNode newNode1=new AdjVNode(tmpVec[1],values[i]);
                    newNode1->Next=mapEquations[tmpVec[0]]->Next;
                    mapEquations[tmpVec[0]]->Next=newNode1;
                

                if(mapEquations.find(tmpVec[1])==mapEquations.end())
                {
                    //如果还没存在
                    PtrToAdjVNode newNode2=new AdjVNode(tmpVec[1],-1);
                    mapEquations[tmpVec[1]]=newNode2;

                }
               
                    //把tmpVec[0]插入tmpVec[1]
                    PtrToAdjVNode newNode3=new AdjVNode(tmpVec[0],(double)1/values[i]);
                    newNode3->Next=mapEquations[tmpVec[1]]->Next;
                    mapEquations[tmpVec[1]]->Next=newNode3;
              

                }

            }
        }

       
        vector<double> result;
        for(int i=0;i<queries.size();i++)
        {
            //重置mapVisited数组
            resetVisited(mapEquations);
            vector<string> stringVec=queries[i];
            if(mapEquations.find(stringVec[0])==mapEquations.end()||mapEquations.find       (stringVec[1])==mapEquations.end())
            {
                result.push_back(-1);
            }
            else if(mapEquations[stringVec[0]]->Weight==0)//如果除数为0
            {
                result.push_back(0);
            }
            else{
                double res=DFS(mapEquations,stringVec[0],stringVec[1]);
                if(res==0)
                    result.push_back(-1);
                else 
                    result.push_back(res);
            }

        }

        return result;

    }
};
```