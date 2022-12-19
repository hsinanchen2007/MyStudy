```
class Solution {
public:
    vector<string> printVertically(string s) {
        //stringstream ss(s);
        string temp="";//初始赋值成空
        int n=s.length();
       // cout<<n<<endl;
        vector<string>ans;
        for(int i=0;i<=n;i++){//注意这里的等于要加上，否则最后一个字符会没有算上
            if(i==n||s[i]==' '){
                ans.push_back(temp);
                temp="";//还原成初始状态
            }else{
                temp+=s[i];
            }
        }
        int num=ans.size();
        //cout<<num;
        int mx=0;
        for(int i=0;i<num;i++){//求出某一个最长单词的长度
            int k=ans[i].size();
            mx=max(mx,k);
        }
        for(int i=0;i<num;i++){//不够长补空格
            if(ans[i].size()<mx){
                int ta=mx-ans[i].size();
                while(ta--){
                    ans[i]+=" ";
                }
            }
        }
        //输出
        vector<string>res;
        for(int i=0;i<mx;i++){//总共需要输出mx个单词，就是输出单词的个数，等于单词的长度
            string tp1="";
            for(int j=0;j<num;j++){
                tp1+=ans[j][i];
            }
            int nu=tp1.size();
            while(nu>0&&tp1[nu-1]==' ')nu--;//删除多余的空格
            tp1=tp1.substr(0,nu);
            res.push_back(tp1);
        }
        return res;


    }
};
```
