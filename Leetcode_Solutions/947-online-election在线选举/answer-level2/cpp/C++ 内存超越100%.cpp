```
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int len=persons.size();
        flag.reserve(len);
        vector<int> _count(len+1,0);
        int maxx=0;
        int maxx_person=-1;
        for(int i=0;i<len;i++) {
            _count[persons[i]]++;
            if(_count[persons[i]]>=maxx) {
                maxx=_count[persons[i]];
                maxx_person=persons[i];
            }
            flag.push_back(maxx_person);
        }
        p=&times;
    }
    
    int q(int t) {
        vector<int>& pp=*p;
        int l=0,r=pp.size()-1;
        int res;
        while(l<=r) {
            int mid=(l+r)/2;
            if(pp[mid]<=t) {
                res=flag[mid];
                l=mid+1;
            }else {
                r=mid-1;
            } 
        }
        return res;
    }
private:
    vector<int> flag;
    vector<int> * p;
};
```
