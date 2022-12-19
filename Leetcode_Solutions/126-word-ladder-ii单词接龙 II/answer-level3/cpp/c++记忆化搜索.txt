```
struct node{
        int i;
        int no=0;
        string nw;
        vector<vector<string> > path;
    };
    vector<vector<string> > ans;
    
    queue<struct node> q1;
    
    int flag1[10000];
    map<int,struct node> st;
    
    bool search(string a,string b){
        int res=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) res++;
        }
        return res==1?true:false;
    }
    void BFS(int endNum,vector<string>& wordList){
        struct node tem;
        vector<string> vtem;
    while(1){
        while(!q1.empty()){
            tem=q1.front();
            q1.pop();
        
            if(tem.i==-1){
                for(int j=0;j<wordList.size();j++){
                    if(search(tem.nw,wordList[j])){
                        struct node tt;
                        tt.i=j;
                        tt.no=tem.no+1;
                        tt.nw=tem.nw;
                   
                        vector<string> vv1;
                        vv1.push_back(tt.nw);
                        vv1.push_back(wordList[j]);
                    
                        tt.nw=wordList[j];
                        //cout<<"tt.nw:"<<tt.nw<<endl;
                        tt.path.push_back(vv1);
                        st[j]=tt;
                    }
                }
            }
            if(tem.i!=-1){
              
                flag1[tem.i]=1;
                for(int j=0;j<wordList.size();j++){
                    if(flag1[j]==0&&search(tem.nw,wordList[j])){
                       
                        auto iter=st.find(j);
                        if(iter==st.end()){
                            struct node tt;
                            tt.i=j;
                            tt.no=tem.no+1;
                            tt.nw=wordList[j];
                            for(int m=0;m<tem.path.size();m++){
                                vtem=tem.path[m];
                                vtem.push_back(wordList[j]);
                                tt.path.push_back(vtem);
                            }
                            st[j]=tt;
                        }
                        else{
                        
                            for(int m=0;m<tem.path.size();m++){
                                vtem=tem.path[m];
                                vtem.push_back(wordList[j]);
                                iter->second.path.push_back(vtem);
                            }
                        }
                    }
                }
            }
        }
        
        if(st.empty()) {return;}
        auto iter=st.find(endNum);
        if(iter!=st.end()){
           
            ans=iter->second.path;
            return ;
        }
        else{
            for(auto iter1=st.begin();iter1!=st.end();++iter1){
                if(flag1[iter1->first]==0){
                    flag1[iter1->first]=1;
                    //cout<<wordList[iter1->first]<<" ";
                    q1.push(iter1->second);
                }
            }
            //cout<<endl;
            st.clear();
        }
    }
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(int i=0;i<wordList.size();i++){
            flag1[i]=0;
        }
        int flag=0;
        int num=-1;
        for(int i=0;i<wordList.size();i++){
            if(endWord==wordList[i]){
                flag=1;
                num=i;
                break;
            }
        }
       
        if(flag==0) return ans;
        struct node tt={-1,0,beginWord};
        q1.push(tt);
        BFS(num,wordList);

        return ans;
    }

```
