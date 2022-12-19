### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countArrangement(int N) {
       int t=0;
       vector<bool> visit(N+1,false);
       vector<int> v;
       count(N,t,visit,v);
       return t; 
    }
    void count(int N,int &t,vector<bool> &visit,vector<int> &v){
        if(v.size()==N){
            t++;
            return;
        }
        for(int i=1;i<=N;i++){
            if(visit[i]==true)continue;
            if(i%(v.size()+1)==0 || (v.size()+1)%i==0){
                v.push_back(i);
                visit[i]=true;
                count(N,t,visit,v);
                visit[i]=false;
                v.pop_back();
            }
        }
    }
};
```