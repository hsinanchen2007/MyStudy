```cpp
class Solution {
public:
    struct Node{
        int idx;
        int step;
        Node(){}
        Node(int Idx, int Step):idx(Idx),step(Step){}
    };
    vector<Node> mQueue[2];
    vector<bool> vis[2];
    unordered_map<string, int> m;
    int qHead[2],qTail[2];
    int n;
    int matching_qNo,matching_idx, matching_step=0;
    bool DBFS(string beginWord, string endWord,vector<string>& wordList){
        vis[0].resize(n, false);
        vis[1].resize(n ,false);

        mQueue[0].resize(n);
        mQueue[1].resize(n);
        
        qHead[0]=qHead[1]=0;
        qTail[0]=qTail[1]=0;

        mQueue[0][qTail[0]++]=Node(m[beginWord],1);
        mQueue[1][qTail[1]++]=Node(m[endWord],1);

        vis[0][m[beginWord]]=true;
        vis[1][m[endWord]]=true;
        while(qHead[0]!=qTail[0]&&qHead[1]!=qTail[1]){
            int qNo=0;
            if(qHead[0]==qTail[0]) qNo=1;
            else if(qHead[1]==qTail[1]) qNo=0; 
            else if(qTail[0]-qHead[0]>qTail[1]-qHead[1]){ //选择更新的队列
                qNo=1;
            }
            Node node=mQueue[qNo][qHead[qNo]++];
            string str=wordList[node.idx]; //队列头元素
            for(int i=0;i<str.length();i++){
                for(char ch='a';ch<='z';ch++){
                    string tmp=str;
                    tmp[i]=ch;
                    if(tmp==str) continue;
                    if(m.find(tmp)!=m.end()){
                        if(vis[1-qNo][m[tmp]]){ //在另一个队列中出现，说明找到路径
                            matching_qNo=qNo;
                            matching_idx=m[tmp];
                            matching_step=node.step;
                            return true;
                        }
                        if(!vis[qNo][m[tmp]]){
                            mQueue[qNo][qTail[qNo]]=Node(m[tmp],node.step+1);
                            vis[qNo][m[tmp]]=true;
                            qTail[qNo]++;
                        }   
                    }
                }
            }
        }
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {     
        wordList.push_back(beginWord);
        n=wordList.size();
        for(int i=0;i<n;i++) m[wordList[i]]=i;
        if(m.find(endWord)==m.end()) return 0;
        bool isMatch=DBFS(beginWord, endWord, wordList);
        for(int i=qHead[1-matching_qNo];i<=qTail[1-matching_qNo];i++){
            Node node=mQueue[1-matching_qNo][i];
            if(node.idx==matching_idx){
                matching_step+=node.step;
            }
        }
        return matching_step;
    }
};
```
![TIM图片20200324005441.png](https://pic.leetcode-cn.com/eba2446f7f078d40771eee49a1cd94eefe1e0d8f8196fd093b00a287952fd544-TIM%E5%9B%BE%E7%89%8720200324005441.png)
