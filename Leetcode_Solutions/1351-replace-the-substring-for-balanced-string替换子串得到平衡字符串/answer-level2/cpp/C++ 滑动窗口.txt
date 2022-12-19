**借鉴评论区大佬整合：滑动窗口寻找满足诉求的区间，前缀数组优化**
1. **首先题意**可替换**的字串先预处理找出要替换的字符以及对应的替换个数**。
2. 前缀数组precount保存长度为i的字串中'W''E''R''Q'的个数以便在寻找区间时快速判断是否满足诉求
3. 滑动窗口筛选更小的区间【start,end】,当[start,end]满足诉求时，start++，进一步缩小区间，不满足时end++,以寻求符合诉求的区间。
4.  ```class Solution {
public://滑动窗口
    map<char,int> mp ;//字符对应数字
    int precount[1000007][4];//前缀数组，在第i位之前的每个元素有多少个
    int n;
    int count[4]={0,0,0,0};//s字符串各个字符的个数
    int expect;
    int length;//查找的区间长度
    void pretreatment(string s){
        mp['Q']=0,mp['W']=1,mp['E']=2,mp['R']=3;
        for(int i=0;i<n;i++){
            count[mp[s[i]]]++;//统计字符串中各字符的个数
                for(int j=0;j<4;j++)
                    precount[i+1][j]=precount[i][j];
                    precount[i+1][mp[s[i]]]++;
        }//前缀数组
        for(int i=0;i<4;i++){
            if(count[i]>expect){
                count[i]-=expect;
                length+=count[i];
            }
            else
                count[i]=-1;
        }
    }
    bool is(int start,int end){
        for(int i=0;i<4;i++){
            if(count[i]!=-1){
                if(!(precount[end][i]-precount[start][i]>=count[i]))
                    return false;
            }
        }
        return true;
    }
    int balancedString(string s) {
    n=s.size();
        expect=n/4;
        length=0;
        pretreatment(s);
        if(length==0){
            return 0;
        }
        int start=0,ans=n,end=length;
        while(end<=n){
            if(is(start,end)){
                ans=min(ans,end-start);
                start++;
            }
            else
                end++;
        }
        return ans;
    }
};

```
