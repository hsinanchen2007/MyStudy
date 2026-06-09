### 解题思路
easy 
itorate and get the count.


### 代码

```cpp
class Solution {
public:
    void Strtoi(int num,char* ret){
        sprintf(ret,"%d",num);
    }
    void add(int&count,string&ret,char S){
                 char temp[5];
                Strtoi(count,temp);
                ret+=temp;
                ret+=S;
                count = 1;
    }
    string compressString(string S) {
        if(S.size() == 0)
        return S;
        int count = 1;
        string ret;
        ret+=S[0];
        for(int i=1;i<S.size();i++){
            if(S[i] == S[i-1])
                count++;
            else
            {   
                add(count,ret,S[i]);
            }
        }
            add(count,ret,NULL);
            return ret.size()>S.size()?S:ret;
    }
};
```