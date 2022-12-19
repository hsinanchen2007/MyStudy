### 解题思路
暴力+字符串hash，c++直接暴力超时了，emmm

### 代码

```cpp
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        
        int cnt=0;
        set<long long unsigned> st;
        long long unsigned f[2007];
        long long unsigned p[2007];
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        p[0]=1;
        for(int i=1;i<=text.size();i++){
            f[i]=f[i-1]*131+text[i-1]-'a'+1;
            p[i]=p[i-1]*131;
        }
        for(int len=1;len<=text.size()/2;len++){
            for(int begin=1;begin+len-1+len<=text.size();begin++){
                int end=begin+len-1;
                //begin   end
                
                int end2=end+len;
                
                //end+1  end2
                
                if(f[end]-f[begin-1]*p[end-begin+1]==f[end2]-f[end]*p[end2-end]){
                    long long unsigned s3=f[end]-f[begin-1]*p[end-begin+1];
                    if(st.find(s3)==st.end()){
                        cnt++;
                        st.insert(s3);
                        //cout<<s3<<endl;
                    }
                }
            }
        }
        return cnt;
    }
};
```