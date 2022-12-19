比较直接的方法：
首先找到所有目标字符的位置，然后分成三部分，第一个目标字符，中间目标字符和末尾目标字符，分成三段插入最短距离，
感觉我的代码好麻烦。。。
```
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
    vector<int>Cpos;
    for(int i=0;i<S.length();++i){
        if(S[i]==C)
            Cpos.push_back(i);
    }
    vector<int>array;
    for(int i=Cpos[0];i>=0;--i){//根据第一个字符位置
        array.push_back(i);
    }
    for(int i=0;i<Cpos.size()-1;++i){//根据中间两个相连的字符位置
        if((Cpos[i+1]-Cpos[i])==1){
            array.push_back(0);
        }
        else if((Cpos[i+1]-Cpos[i])==2){
                array.push_back(1);
                array.push_back(0);
        }
        else{
            for(int j=1;j<=(Cpos[i+1]-Cpos[i])/2;++j){
                array.push_back(j);
            }
            for(int j=((Cpos[i+1]-Cpos[i])%2==0?(Cpos[i+1]-Cpos[i])/2-1:(Cpos[i+1]-Cpos[i])/2);j>=0;--j){
                array.push_back(j);
            }
        }
    }
    for(int i=1;i<S.length()-Cpos[Cpos.size()-1];++i){//根据最后一个字符位置
        array.push_back(i);
    }
        return array;
    }
};
```
