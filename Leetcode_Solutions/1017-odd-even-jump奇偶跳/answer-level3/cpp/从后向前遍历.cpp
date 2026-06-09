如果用二分法，复杂度可以降到nlog(n)，现在的复杂度是n2
```
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        if(A.size()==0)return false;
        vector<int> temp(A);
        sort(temp.begin(),temp.end());
        map<int,int> m;
        int num=1;
        int last=temp[0];
        m[temp[0]]=0;
        for(int i=1;i<temp.size();++i){
            if(temp[i]==last){
                continue;
            }
            last=temp[i];
            m[temp[i]]=num;
            ++num;
        }
        vector<int> mirror(num,-1);
        vector<pair<bool,bool>> bp(A.size(),{false,false});
        int ans=1;
        bp[A.size()-1]={true,true};
        mirror[m[*A.rbegin()]]=A.size()-1;
        for(int i=A.size()-2;i>=0;--i){
            int temp=m[A[i]];
            pair<bool,bool> pa;
            while(temp<mirror.size()&&mirror[temp]==-1){
                ++temp;
            }
            if(temp==mirror.size()){
                pa.first=false;
            }
            else{
                pa.first=bp[mirror[temp]].second;
            }
            temp=m[A[i]];
            while(temp>=0&&mirror[temp]==-1){
                --temp;
            }
            if(temp==-1){
                pa.second=false;
            }
            else{
                pa.second=bp[mirror[temp]].first;
            }
            if(pa.first==true){
                ++ans;
            }
            mirror[m[A[i]]]=i;
            bp[i]=pa;

        }
        return ans;

    }
};
```
