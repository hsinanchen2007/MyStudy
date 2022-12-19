48ms 97.41%
```
    bool canThreePartsEqualSum(vector<int>& s) {
        if(s.size()<3) return 0;
        int sum=accumulate(s.cbegin(),s.cend(),0);
        if(sum%3) return 0;
        return point_find(s,0,sum,2);
    }
    bool point_find(vector<int>& s,int start,int sum,int k){
        if(k==0) return 1;
        for(int tmp=0;start<s.size()-k;++start){
            tmp+=s[start],sum-=s[start];
            if(tmp*k==sum)
                if(point_find(s,start+1,sum,k-1))
                    return 1;
        }
        return 0;
    }
```
