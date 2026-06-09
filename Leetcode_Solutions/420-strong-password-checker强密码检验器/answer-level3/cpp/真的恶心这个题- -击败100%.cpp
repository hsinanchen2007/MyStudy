编了个排序函数，把所有>=3的连续长度按照除以3的余数递增排序，每次循环一遍后重新排序把小于三的过滤出去
```
class Solution {
public:
    static bool cmp(const int &a,const int &b){
        if(a>=3&&b<3) return true;
        if(a<3&&b>=3) return false;
        return a%3<b%3;
    }
    int strongPasswordChecker(string s) {
        if(s.empty()) return 6;
        int d=0,i=0;
        vector<int>samecnt;
        if(s.size()<6) i=6-s.size();
        if(s.size()>20) d=s.size()-20;
        vector<int>dp(s.size(),0);
        bool upper=false,lower=false,number=false;
        for(int j=0;j<s.size();j++){
            if(isupper(s[j])) upper=true;
            else if(islower(s[j])) lower=true;
            else if(isdigit(s[j])) number=true;
            if(j&&s[j]==s[j-1]) dp[j]=dp[j-1]+1;
            else if(j&&s[j]!=s[j-1]&&dp[j-1]) samecnt.push_back(1+dp[j-1]);
        }
        if(dp.back()) samecnt.push_back(dp.back()+1);
        int c=3-upper-lower-number;
        if(!i&&!d){
            int res=0;
            for(int x:samecnt) res+=x/3;
            return max(res,c);
        }
        else if(!i){
            int ald=0;
            sort(samecnt.begin(),samecnt.end(),cmp);
            int j=0;
            while(ald<d){
                if(samecnt.empty()||samecnt[0]<3) break;
                if(j==samecnt.size()||samecnt[j]<3){
                    j=0;
                    sort(samecnt.begin(),samecnt.end(),cmp);
                }
                else if(samecnt[j]>=3&&samecnt[j]%3==0){
                    samecnt[j]--;
                    ald++;
                    j++;
                }
                else if(samecnt[j]>=3&&samecnt[j]%3==1){
                    if(d-ald<2){
                        samecnt[j]-=d-ald;
                        ald=d;
                        break;
                    }
                    samecnt[j]-=2;
                    ald+=2;
                    j++;
                }
                else if(samecnt[j]>=3&&samecnt[j]%3==2){
                    if(d-ald<3){
                        samecnt[j]-=d-ald;
                        ald=d;
                        break;
                    }
                    samecnt[j]-=3;
                    ald+=3;
                    j++;
                }
            }
            int res=0;
            if(ald<d) return d+c;
            for(int x:samecnt) res+=x/3;
            return max(res,c)+ald;
        }
        else{
            if(i==1&&samecnt.size()&&samecnt.back()==5) return 2;
            int res=0;
            for(int x:samecnt) res+=x/3;
            if(i>res) res=i;
            return max(res,c);
        }
    }
};
```