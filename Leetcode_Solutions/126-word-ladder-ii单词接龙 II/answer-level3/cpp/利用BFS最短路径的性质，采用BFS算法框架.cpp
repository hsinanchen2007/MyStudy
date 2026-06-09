（一）首先想到要用宽搜，因为宽搜有个性质就是：源节点到任何节点的path都是最短路径。
（二）算法的框架有了就是无向图的宽搜框架BFS。那么接下来就要考虑一些细节性的关键问题了。这里的关键问题有：1）如何建图；2）如何保存每个最短路径,在127题中，只需要记录当前节点的步数即可，不需要保存每个路径上的节点；3）如何即不重复上一层已访问过的邻接点，又能重复下一层的拥有不同父节点的邻接点。
（三）对策：1）对于第一个问题，采用邻接表建立无向图，可以建立节点抽象数据结构，然后存储指针的方式；我这里采用STL的map，主要是利用其find（）的功能，当然这样做显然要比用指针慢了。2）这个可能是最难的一个细节了，我这里对Q队列进行了修改，采用vector实现，主要是考虑到便于随机访问，因为后面需要对Q中的节点按路径取出来；另外Q的节点也进行了修改，因为每个节点既要记录其单词信息，也要记录其所在的层数（即步数），还要记录a其上层节点在Q中的位置信息，这样基本上把节点的所有主要信息都记录了下来（**可见在宽搜的框架中，队列Q的作用非常重要，使用上也可以根据需要灵活选择节点的形式**）；因为要记录每条路径，而当路径上某个节点有不同的父节点时，则这个子节点需要重复放入Q，这时就会产生第3）个问题。3）用一个map，关键字是节点单词，值为其所在的层数（或步数），如果邻接点单词在这个map中且当前节点的层数小于该邻接点层数，说明该邻接点是路径上的点（而且拥有不同的上层父节点），把该邻接点放进队列；否则就说明该邻接点是当前节点的上层节点，此时不把该节点放进队列。
```
//第一步建图
bool Isneighbors(const string &str1,const string &str2){
    int count=0;
    for(int i=0;i<str1.length();i++){
        if(str1[i]!=str2[i]){
            count++;
        }
    }
    return count==1;
}

void BuiltGragh(string &beginWord,vector<string>& wordList,map<string,vector<string>>&Gragh){
    int flag=0;
    for(int i=0;i<wordList.size();i++){
        if(wordList[i]==beginWord){
            flag=1;
        }
        Gragh[wordList[i]]={};
    }
    //cout<<Gragh.size()<<endl;
    if(flag==0){
        wordList.push_back(beginWord);
    }
    for(int i=0;i<wordList.size();i++){
        for(int j=i+1;j<wordList.size();j++){
            if(Isneighbors(wordList[i],wordList[j])){
                Gragh[wordList[i]].push_back(wordList[j]);
                Gragh[wordList[j]].push_back(wordList[i]);
            }
        }
    }
    //cout<<Gragh.size()<<' '<<Gragh["dog"][0]<<endl;
}

//队列中元素的数据结构
struct Qitem{
    string node;
    int parent_position;
    int step;
    Qitem(string a,int i,int n):node(a), parent_position(i),step(n){}
};



//第二步，BFS
void BFS_minipath(string beginWord,string endWord,map<string,vector<string>>&Gragh,
                vector<Qitem>&Q, vector<int>&endword_position){
    //cout<<"haha"<<endl;
    map<string,int>visit;
    visit[beginWord]=1;
    Q.push_back(Qitem(beginWord,-1,1));
    int endWord_step=0;//用于记录endWord所在的步数
    int front=0;
    //cout<<"haha~"<<endl;//测试
    while(front!=Q.size()){//循环结束的条件有两个
       // cout<<"haha~"<<endl;//测试
        Qitem item=Q[front];
        int now_step=item.step;
            //front=item.parent_position;
        if(endWord_step!=0&&endWord_step<now_step){
            break;
        }
        if(item.node==endWord){
            endWord_step=now_step;
            endword_position.push_back(front);
        }
        vector<string>&neighbors=Gragh[item.node];
        for(int i=0;i<neighbors.size();i++){
            if(visit.find(neighbors[i])==visit.end()||        visit[neighbors[i]]==now_step+1){
                visit[neighbors[i]]=now_step+1;
                Q.push_back(Qitem(neighbors[i],front,now_step+1));
            }
        }
        front++;
    }
}
class Solution {
public:
     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //这一步先建图，调用建图函数
        map<string,vector<string>>Gragh;
        BuiltGragh(beginWord,wordList,Gragh);
        //这一步要通过广度优先算法来寻找最短路径，调用BFS_minipath函数
        vector<vector<string>>result;//保存最终结果
        vector<Qitem>Q;//保存广搜时的路径节点
        vector<int>endword_position;//保存endWord在Q中的位置信息，以便从Q中获得每条路径
        BFS_minipath(beginWord,endWord,Gragh,Q,endword_position);
       // cout<<endword_position.size()<<endl;//测试
        for(int i=0;i<endword_position.size();i++){
            int n=Q[endword_position[0]].step;
            vector<string>item(n);
            //cout<<item[0]<<endl;//测试
            //cout<<"hahaha"<<endl;//测试
            int j=endword_position[i];
            while(j>-1){
                item[n-1]=Q[j].node;
                j=Q[j].parent_position;
                n--;
            }
            result.push_back(item);
            //cout<<result.size()<<endl;//测试
        }
        return result;
    }
};
```

运行时间比较慢，空间消耗也比较大。应该还有比较大的优化空间
