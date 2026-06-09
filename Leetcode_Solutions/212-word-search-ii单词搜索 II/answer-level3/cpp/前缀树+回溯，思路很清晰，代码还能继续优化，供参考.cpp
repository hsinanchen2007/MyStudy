```
class Solution {
struct Trie
{
    bool is_Word;
    unordered_map<char,Trie*> next;
    Trie()
    {
        is_Word = false;
    }
};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(auto& str:words)
        {
            insert(root,str);
        }
        vector<string> ret;
        set<string> s;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        string str;
         for(int i = 0; i<board.size(); i++)
         {
             for(int j = 0; j<board[0].size(); j++)
             {
                if(root->next.count(board[i][j])) 
                {
                    helper(s,str,i,j,visited,board,root);
                    visited[i][j] = false;
                }    
             }
         }
         for(auto& str:s)
            ret.push_back(str);
        return ret;
    }
    void insert(Trie* root,string str)
    {
        for(auto& ch:str)
        {
            if(!root->next.count(ch))
                root->next[ch] = new Trie();
            root = root->next[ch];
        }
        root->is_Word = true;
    }
    void helper(set<string>& s, string str, int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& board, Trie* root)
    {
        //题目的难点在于时间复杂度，这里visited必须用引用才能通过
        str.push_back(board[i][j]);
        root = root->next[board[i][j]];
        visited[i][j] = true;
        if(root->is_Word)
        {
            s.insert(str);
        }
        if(i+1<board.size() && !visited[i+1][j] && root->next.count(board[i+1][j]))
        {
            helper(s,str,i+1,j,visited,board,root); 
            visited[i+1][j] = false;   
        }
        if(i-1>=0 && !visited[i-1][j] && root->next.count(board[i-1][j]))
        {
            helper(s,str,i-1,j,visited,board,root);
            visited[i-1][j] = false;
        }
        if(j-1>=0 && !visited[i][j-1] && root->next.count(board[i][j-1]))
        {
            helper(s,str,i,j-1,visited,board,root);
            visited[i][j-1] = false;
        }
        if(j+1<board[0].size() && !visited[i][j+1] && root->next.count(board[i][j+1]))
        {
            helper(s,str,i,j+1,visited,board,root);
            visited[i][j+1] = false;
        }
    }
};
```
