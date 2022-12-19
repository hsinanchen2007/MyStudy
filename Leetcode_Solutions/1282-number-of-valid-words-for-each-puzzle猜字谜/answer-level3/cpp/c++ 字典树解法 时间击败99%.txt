### 解题思路
首先这题重复的字母可以去掉，同时字母顺序也没有影响，故将words中的词排序去重，然后加入到字典树中。
查询时也先把puzzle改为升序进行查询，但需要注意的是必须要在路径中包含了第一个字母后，才能将值累加到结果里面。

### 代码

```cpp
class Solution {
  struct node{
    node* ch[26]={nullptr};
    int val=0;
  };
  node* root;
  char need;
  int need_idx;
  int tmp;
  
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
      root=new node();
       
      for(auto& word:words){
        sort(word.begin(),word.end());
                    word.resize(unique(word.begin(),word.end())-word.begin());

        node* now=root;
        for(auto& c:word){
          if(now->ch[c-'a']==nullptr){now->ch[c-'a']=new node();}
          now=now->ch[c-'a'];
        } 
        now->val++;
      }
      vector<int>res;
      for(auto& p:puzzles){
        tmp=0;
        need=p[0];
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();++i) if(p[i]==need) {need_idx=i;break;}
        dfs(root,-1,p,false);
        res.push_back(tmp);
      }
      return res;
    }
    void dfs(node* now,int last_idx,string& p,bool ok){
      if(last_idx>=need_idx&&!ok) return;
      if(!now) return;
      if(ok) tmp+=now->val;
      for(int i=last_idx+1;i<p.size();++i){
        if(i==need_idx) dfs(now->ch[p[i]-'a'],i,p,true);
        else dfs(now->ch[p[i]-'a'],i,p,ok);
      }
    }
};

```