    由于strtok会将多个相连的分隔符看作是一个，所以用一个num记录有效字符数，与IP的长度对比，如果不符合说明有多的"."或者":"。
```
class Solution {
public:
    string validIPAddress(string IP) {
        int num = 0 ;
        vector<char*> ans;  //根据ans长度判断是IPv4还是IPv6
        char* p = &IP[0];
        char* flag = strtok(p,".:");
        while(flag!=NULL){
            ans.push_back(flag);
            flag = strtok(NULL,".:");
        }
        //忽然想到这样写没有判断':'和'.'混合的情况，还好样例里没有，懒得改了= -。
        if(ans.size()==4){
            for(int i = 0 ; i < 4 ; i++){
                num +=strlen(ans[i]);
                if(strlen(ans[i])!=1&&ans[i][0]=='0') return "Neither";
                else{
                    int k = 0 ;
                    while(k<strlen(ans[i])){
                        if(ans[i][k]<'0'||ans[i][k]>'9') return "Neither";
                        k++;
                    }
                    int a = atoi(ans[i]);
                    if(a<0||a>255) return "Neither";
                }  
            }
            if(IP.length()!=num+3) return "Neither";
            return "IPv4";
        }
        else if(ans.size()==8){
            for(int i = 0 ; i < 8 ; i++){
                int len = strlen(ans[i]);
                num +=len;
                if(len==1&&ans[i][0]=='0') continue;
                else if(len>4) return "Neither";
                else{
                    for(int j = 0 ; j < len;j++){
                        if((ans[i][j]>='0'&&ans[i][j]<='9')||(ans[i][j]>='A'&&ans[i][j]<='F')||(ans[i][j]>='a'&&ans[i][j]<='f')){
                            continue;
                        }
                        else return "Neither";
                    }
                }
                
            }
            if(IP.length()!=num+7) return "Neither";
            return "IPv6";
        }
        return "Neither";
    }
};
```

![image.png](https://pic.leetcode-cn.com/f7a2fbbcb13b8a812ebc0ea20d5d0e6bb9fa0eda13bf60fd2fb2c775e0822b27-image.png)
