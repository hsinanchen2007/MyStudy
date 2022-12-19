对于每个前缀构建个堆，堆大小为 3 ，最后遍历 searchword 的前缀就可以了。
```
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      map<string,priority_queue<string,vector<string>,less<string> > >p;
      for(auto i :products){
        for(int j = 1;j <= i.length();++j){
          string subs = i.substr(0,j);
          if(p.find(subs) == p.end()){
            priority_queue<string,vector<string>,less<string>> que;
            p.insert(make_pair(subs,que));
          }
          p[subs].push(i);
          if(p[subs].size() > 3) p[subs].pop();
        }
      }

      vector<vector<string>> ans(searchWord.length());
      for(int j = 1, sz = searchWord.length();j <= sz;++j){
        string subs = j == sz ? searchWord :searchWord.substr(0,j);
        map<string,priority_queue<string> > ::iterator ret = p.find(subs);
        if(ret != p.end()){
          priority_queue<string,vector<string>,less<string> >que = (ret->second);
          while(que.size() > 0){
            ans[j-1].push_back(que.top());que.pop();
          }
          reverse(ans[j-1].begin(),ans[j-1].end());
        }
      }
      
      return ans;
    }
```
