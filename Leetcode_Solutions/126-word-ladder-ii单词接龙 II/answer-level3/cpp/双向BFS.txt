
### 代码

```cpp
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> us(wordList.begin(),wordList.end());
        if(!us.count(endWord))return ans;
        unordered_set<string> beginset,endset;
        queue<vector<string>> qbegin,qend;
        qbegin.push({beginWord});
        qend.push({endWord});
        beginset.insert(beginWord);
        endset.insert(endWord);
        us.erase(beginWord);
        us.erase(endWord);
        while((!qbegin.empty())&&(!qend.empty())){
            if(qbegin.size()>qend.size()){
                swap(qbegin,qend);
                swap(beginset,endset);
            }
            int size=qbegin.size();
            vector<string> lalala;
            for(int i=0;i<size;++i){
                vector<string> temp=qbegin.front();
                string s=*temp.rbegin();
                
                qbegin.pop();
                for(int j=0;j<s.size();++j){
                    char old=s[j];
                    for(int m=0;m<26;++m){
                        s[j]='a'+m;
                        if(us.count(s)){
                            temp.push_back(s);
                            qbegin.push(temp);
                            beginset.insert(s);
                            lalala.push_back(s);
                            temp.pop_back();
                        }
                        else if(endset.count(s)){
                            queue<vector<string>> qtemp=qend;
                            while(!qtemp.empty()){
                                vector<string> vtemp=qtemp.front();
                                qtemp.pop();
                                if(*vtemp.rbegin()==s){
                                    vector<string> tempans;
                                    if(*vtemp.begin()==beginWord){
                                        tempans=vtemp;
                                        for(int a=temp.size()-1;a>=0;--a){
                                            tempans.push_back(temp[a]);
                                        }
                                    }
                                    else{
                                        tempans=temp;
                                        for(int a=vtemp.size()-1;a>=0;--a){
                                            tempans.push_back(vtemp[a]);
                                        }
                                    }
                                    ans.push_back(tempans);
                                }
                            }
                        }
                        s[j]=old;
                    }
                }
            }
            for(auto a:lalala){
                us.erase(a);
            }
            if(!ans.empty())
                break;
        }
        return ans;
    }
};
```