### 解题思路
奇怪的知识，，，，先分组，分成若干段可分的独立区间，在每个区间中从左往右，如果当前到最大深度的一半了，那么从他开始刷1，一直刷到刷1的这些左括号和右括号的数量一样，然后就不刷，继续向后找，如果深度又攒到一半了，继续刷，这个输入保证绝对合法挺好，不用xjb判断了

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
vector<int> flag(seq.length(),0);
int sum=0;
int maxn=0;
int st;
int ed;
for(int i=0; i<seq.length(); i++){
    if(sum==0)
        st=i;
    if(seq[i]=='('){
        sum++;
        if(sum>maxn)
            maxn=sum;
    }
    if(seq[i]==')')
        sum--;
    if(sum==0){
        ed=i;
        int lv=maxn/2+1;
        maxn=0;
        int sumtmp=0;
        int flag1=0;
        for(int t=st; t<=ed; t++){
            if(sumtmp<=lv-1)
                flag1=0;
                if(seq[t]=='('){
                    sumtmp++;
                    if(sumtmp==lv&&flag1==0)
                        flag1=1;    
                }
                if(seq[t]==')')
                    sumtmp--;
                if(flag1==1)
                    flag[t]=1;
        }
    }    
}
return flag;
    }
};
```