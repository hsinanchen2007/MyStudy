### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        int dot=0;
        int ec=0;
        int j=0,k=s.length()-1;
        while(s[j]==' ')j++;
        while(s[k]==' ')k--;
        s=s.substr(j,k-j+1);
        bool isdigit=false;;
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(i==0){
                if(s[i]!='+'&&s[i]!='-'){
                    if(s[i]>='0'&&s[i]<='9'){
                        isdigit=true;
                    }
                    else if(s[i]=='.'){
                        dot++;
                    }
                    else return false;
                }
            }
            else{
                if(s[i]=='e'||s[i]=='E'){
                    if(isdigit==false)return false;
                    isdigit=false;
                    flag=true;
                    dot=0;
                    ec++;
                    if(i==s.length())return false;
                    else{
                        if(s[i+1]=='+'||s[i+1]=='-'){
                            ;
                        }
                        else if(s[i+1]>='0'&&s[i+1]<='9'){
                            isdigit=true;
                        }
                        else return false;
                    }
                }
                else if(s[i]=='+'||s[i]=='-'){
                    if(i>1&&(s[i-1]=='e'||s[i-1]=='E'));
                    else return false;
                }
                else if(s[i]=='.')dot++;
                else if(s[i]>='0'&&s[i]<='9'){
                    isdigit=true;
                }
                else return false;
            }
            if(dot>1)return false;
            if(dot>0&&flag==true)return false;
            if(ec>1)return false;
        }
        if(isdigit==false)return false;
        return true;
    }
};
```