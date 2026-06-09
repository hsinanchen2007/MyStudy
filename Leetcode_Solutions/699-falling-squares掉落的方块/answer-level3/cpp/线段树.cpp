普通线段树开的数组过大，显示超过内存限制，为解决这个问题，通过离散化解决，运用set和map
```
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> s;
        for(int i=0;i<positions.size();++i){
            s.insert(positions[i][0]);
            s.insert(positions[i][0]+positions[i][1]);
        }
        int maxSize=0;
        map<int,int> m;
        for(auto a:s){
            ++maxSize;
            m[a]=maxSize;
        }
        vector<int> A(maxSize+1,0);
        vector<int> Sum(maxSize<<2);
        Build(1,maxSize,1,Sum,A);
        vector<int> ans;
        int maxNow=INT_MIN;
        for(int i=0;i<positions.size();++i){
            int first=m[positions[i][0]];
            int second=m[positions[i][1]+positions[i][0]];
            int temp;
            if(second>first+1){
                temp=Query(first+1,second-1,1,maxSize,1,Sum);
            }
            else{
                temp=min(Query(first,first,1,maxSize,1,Sum),Query(second,second,1,maxSize,1,Sum));
            }
            temp+=positions[i][1];
            maxNow=max(temp,maxNow);
            ans.push_back(maxNow);
            for(int j=first;j<=second;++j){
                Update(j,temp,1,maxSize,1,Sum);
            }
        }
        return ans;

    }
    void pushUp(int root,vector<int> &Sum){
        Sum[root]=max(Sum[root<<1],Sum[root<<1|1]);
    }

    void Build(int l, int r, int root,vector<int>& Sum,const vector<int>& A){
        if(l==r){
            Sum[root]=A[l];
            return;
        }
        int mid=(l+r)>>1;
        Build(l,mid,root<<1,Sum,A);
        Build(mid+1,r,root<<1|1,Sum,A);
        pushUp(root,Sum);
    }

    //A[L]+=C
    void Update(int L,int C,int l,int r,int root,vector<int>& Sum){
        if(l==r){
            Sum[root]=C;
            return;
        }
        int mid=(l+r)>>1;
        if(L<=mid){
            Update(L,C,l,mid,root<<1,Sum);
        }
        else{
            Update(L,C,mid+1,r,root<<1|1,Sum);
        }
        pushUp(root,Sum);
    }

    int Query(int L,int R, int l,int r,int root,const vector<int>& Sum){
        if(L<=l&&R>=r){
            return Sum[root];
        }
        int mid=(l+r)>>1;
        int ans=INT_MIN;
        if(mid>=L){
            ans=max(ans,Query(L,R,l,mid,root<<1,Sum));
        }
        if(mid<R){
            ans=max(ans,Query(L,R,mid+1,r,root<<1|1,Sum));
        }
        return ans;
    }


};
```
