```cpp
struct charNode{
    vector<charNode *> next;
    charNode():next(vector<charNode *>(26, NULL)){}
};

class Solution {
public:
    int r;
    int minimumLengthEncoding(vector<string>& words) {
        charNode *root,*cur;
        cur=root=new charNode;
        for(int i=0; i<words.size(); i++){
            int j=words[i].size()-1; cur=root;
            for(; j>=0; j--){
                if(cur->next[words[i][j]-'a']==NULL)
                    cur->next[words[i][j]-'a']=new charNode;
                cur=cur->next[words[i][j]-'a'];
            }
        }
        r=0;
        traversal(root, 0);
        return r;
    }
    void traversal(charNode * cur, int curDepth){
        bool isLeaf=true;
        for(int i=0; i<cur->next.size(); i++){
            if(cur->next[i]!=NULL){
                traversal(cur->next[i], curDepth+1);
                isLeaf=false;
            }
        }
        if(isLeaf) r+=curDepth+1;
    }
};
```
