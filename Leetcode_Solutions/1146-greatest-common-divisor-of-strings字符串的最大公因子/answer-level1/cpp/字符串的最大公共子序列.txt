### 解题思路
从大的公约数开始尝试（这一步感觉可以用辗转相除法代替）
分别检测单个字符串是否关于NUM循环
最后两个字符串的循环体是否相同

### 代码

```cpp
class Solution {
    bool isDiv(string &str1,int num){
        bool ans=true;
        for(int i=num;i<str1.size();++i){
            if(str1[i]!=str1[i-num]){
                return false;
            }
        }
        return ans;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int maxsize=min(str1.size(),str2.size());
        int iterationNum=0;
        for(int i=1;i<=maxsize;++i){
            int num=maxsize/i;
            if(maxsize%i!=0){
                continue;
            }
            if((str1.size()%num)||(str2.size()%num)){
                continue;
            }
            if((str1.size()%num==0)&&(str2.size()%num==0)){
                if(isDiv(str1,num)&&isDiv(str2,num)){
                    iterationNum=num;
                    break;
                }
            }
        }
        for(int i=0;i<iterationNum;++i){
            if(str1[i]!=str2[i]){
                iterationNum=0;
                break;
            }
        }
        string ans;
        if(iterationNum!=0){
            ans=str1.substr(0,iterationNum);
        }
        return ans;
    }
};
```