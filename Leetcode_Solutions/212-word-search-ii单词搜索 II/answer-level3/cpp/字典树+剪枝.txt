主要的思想还是字典树+回溯算法，建议参看官方的解题，我这里通过为字典树中的节点加入use用来实现对字典树的剪枝
```
struct tire{//use 用于节点的剪枝，当use==0时即可将其剪去
    int use,val;
    bool is_word;
    map<int,tire*>childern;
    tire(int value,bool flag){val=value;is_word=flag;for(int i=0;i<26;i++)childern[i]=NULL;use=1;}
};
class Solution {
public:
    tire *word_tire=new tire(-1,false);
    string mid;
    vector<string> res;
    int used[30][30];
    int n,m;//记录board的大小
    void insert_word(string word){
        int i=0,n=word.size();
        tire *now=word_tire;
        while(i<n){
            int c=((int)word[i])-97;
            if(now->childern[c]){
                now=now->childern[c];
                now->use++;
            }
            else{
                tire *new_one=new tire(c,false);
                now->childern[c]=new_one;
                now=new_one;
            }
            i++;
        }
        now->is_word=true;
    }
    int trace_back(vector<vector<char>> board,int i,int j,tire* root){//返回值用于剪枝
        int cut=0;int a,child_cut;
        if(root->is_word){//找到一个单词,注意这里不构成递归结束的条件，因为可能还有更长的word
            root->is_word=false;
            root->use--;
            res.push_back(mid);
            cut++;
        }
        //分别对四个方向进行试探
        if(i+1<n&&!used[i+1][j]&&root->childern[(int)board[i+1][j]-97]){
            a=(int)board[i+1][j]-97;
            used[i+1][j]=1;
            mid.push_back(board[i+1][j]);
            child_cut=trace_back(board,i+1,j,root->childern[a]);
            root->use-=child_cut;
            cut+=child_cut;
            used[i+1][j]=0;
            mid.pop_back();
            if(!root->childern[a]->use)root->childern[a]=NULL;
        }
        if(i-1>=0&&!used[i-1][j]&&root->childern[(int)board[i-1][j]-97]){
            a=(int)board[i-1][j]-97;
            used[i-1][j]=1;
            mid.push_back(board[i-1][j]);
            child_cut=trace_back(board,i-1,j,root->childern[a]);
            root->use-=child_cut;
            cut+=child_cut;
            used[i-1][j]=0;
            mid.pop_back();
            if(!root->childern[a]->use)root->childern[a]=NULL;
        }
        if(j+1<m&&!used[i][j+1]&&root->childern[(int)board[i][j+1]-97]){
            a=(int)board[i][j+1]-97;
            used[i][j+1]=1;
            mid.push_back(board[i][j+1]);
            child_cut=trace_back(board,i,j+1,root->childern[a]);
            root->use-=child_cut;
            cut+=child_cut;
            used[i][j+1]=0;
            mid.pop_back();
            if(!root->childern[a]->use)root->childern[a]=NULL;
        }
        if(j-1>=0&&!used[i][j-1]&&root->childern[(int)board[i][j-1]-97]){
            a=(int)board[i][j-1]-97;
            used[i][j-1]=1;
            mid.push_back(board[i][j-1]);
            child_cut=trace_back(board,i,j-1,root->childern[a]);
            root->use-=child_cut;
            cut+=child_cut;
            used[i][j-1]=0;
            mid.pop_back();
            if(!root->childern[a]->use)root->childern[a]=NULL;
        }
        return cut;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        memset(used,0,sizeof(used));
        n=board.size();m=board[0].size();
        for(auto word:words){//初始化字典树
            insert_word(word);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=((int)board[i][j])-97;
                if(word_tire->childern[c]){
                    mid.push_back(board[i][j]);
                    used[i][j]=1;
                    trace_back(board,i,j,word_tire->childern[c]);
                    mid.clear();
                    used[i][j]=0;
                    if(!word_tire->childern[c]->use)word_tire->childern[c]=NULL;
                }
            }
        }
        return res;
    }
};
```
