### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int a[150];
    int b[150];
    int ans[500]; 
    string multiply(string num1, string num2) {
        int len_a=num1.size();
        int len_b=num2.size();
        string res="";
        fill(ans,ans+499,0);
        for(int i=0;i<len_a;i++){
            a[len_a-i]=num1[i]-'0';
        }
        for(int i=0;i<=len_b;i++){
            b[len_b-i]=num2[i]-'0';
        }
        //for(int i=1;i<=len_b;i++){
        //   cout<<b[i];
        // }
        int len_ans=0;
        for(int i=1;i<=len_a;i++){
            for(int j=1;j<=len_b;j++){
                int temp=ans[i+j-1]+a[i]*b[j];
                //cout<<"当前ans["<<i+j-1<<"]="<<ans[i+j-1]<<endl;
                ans[i+j-1]=temp%10;
                ans[i+j]+=temp/10;
                if(i+j-1>len_ans) len_ans=i+j-1;
                //cout<<a[i]<<"*"<<b[j]<<"="<<ans[i+j-1]<<endl;
            }
        }
        //最后一位进位
        if(ans[len_ans+1]>0){
            len_ans++;
        }
        //为了避免全0
        int flag=true;
        for(int i=1;i<=len_ans;i++){
            if(ans[i]!=0) flag=false;
            res=to_string(ans[i])+res;
        }
        if(flag) return "0";
        return res;
    }
};
```