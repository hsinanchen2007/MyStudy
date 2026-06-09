// **自己的代码写的又臭又长**
// ```
class Solution {
public:
   
    struct node{
        char ch;
        int count[30];
        node(){
            memset(count, 0, sizeof(count));
        }
        friend bool operator <(node a,node b){
            for (int i=0; i<26; i++) {
                if(a.count[i]>b.count[i]) return 1;
                if(a.count[i]<b.count[i]) return 0;
            }
            return a.ch<b.ch;
            
        }
    };
   
    string rankTeams(vector<string>& votes) {
        string ans;
        vector<node>v;set<char>st;
        for (int i=0; i<votes.size(); i++) {
            for (int j=0; j<votes[i].size(); j++) {
                
                if(st.count(votes[i][j])==0){
                    st.insert(votes[i][j]);
                    node ex;ex.ch=votes[i][j];ex.count[j]++;
                    v.push_back(ex);
                }else{
                    for (int k=0; k<v.size(); k++) {
                        if (v[k].ch==votes[i][j]) {
                            v[k].count[j]++;
                            break;
                        }
                    }
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); i++)
            ans+=v[i].ch;
        return ans;
        
    }
};

**膜拜一下Rank1的代码**
// ```
// class Solution {
// public:
//     string rankTeams(vector<string>& votes) {
//         int m = votes.size();
//         string v = votes[0];
//         map<char, map<int, int>> f;
//         for (auto s : votes)
//         {
//             for (int i = 0; i < s.size(); ++ i)
//                 f[s[i]][i] ++;
//         }
//         sort(v.begin(), v.end(), [&](char a, char b) -> bool
//         {
//             for (int i = 0; i < v.size(); ++ i)
//             {
//                 if (f[a][i] > f[b][i]) return 1;
//                 if (f[a][i] < f[b][i]) return 0;
//             }
//             return a < b;
//         });
//         return v;
//     }
// };
// ```

**Rank1代码的sort部分看不懂😂**
// ```
// sort(v.begin(), v.end(), [&](char a, char b) -> bool
// ```
**谁能解释一下么**