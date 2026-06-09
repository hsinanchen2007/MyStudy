#### 调试半天
```
typedef long long ll;
class Solution {
public:
    bool isValid(ll first,ll second,int start,string s){
        if(start==s.length())return true;
        
        second=first+second;
        if(second>INT_MAX)return false;
        first=second-first;
        string sum=to_string(second);
        int len=sum.length();
        return sum==s.substr(start,len)&&isValid(first,second,start+len,s);
    }
    vector<int> splitIntoFibonacci(string s) {
        vector<int>res;
        int n=s.length();
        cout<<n<<endl;
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp[n-1]=='0'){
            for(int i=0;i<n;i++){
                int num=s[i]-'0';
                res.push_back(num);
            }
            return res;
        }
        
        for(int i=1;i<=n/2;i++){//表示第一个字符的长度
            if(i>1&&s[0]=='0')return res;
            ll first=stoll(s.substr(0,i));
            if(first>INT_MAX)break;
            for(int j=1;n-i-j>=max(i,j);j++){//表示第二个字符的长度
                if(j>1&&s[i]=='0')break;
                ll second=stoll(s.substr(i,j));
                if(second>INT_MAX)break;
                if(isValid(first,second,i+j,s)){
                    int len=i+j;
                    //int sum=first+second;
                    res.push_back(first);
                    res.push_back(second);

                    while(len<=n){
                        second=first+second;
                        first=second-first;
                        string s1=to_string(second);
                        int len1=s1.length();
                        if(len+len1<=n){
                            res.push_back(second);
                            len=len+len1;
                            //cout<<len<<endl;
                        }else{
                            break;
                        }
                    }
                    //cout<<res.size()<<endl;
                    return res;
                }
            }
        }
        return res;
    }
};
```