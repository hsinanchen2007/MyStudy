### 解题思路
DP有时候很难想，但是记忆化搜索更加容易思考，因为这种自顶向下的思考方式更适合人类的思维习惯。

1.需要自己设计hash函数，将4个参数hash成一个int，这样才可以用hashmap，算是一种小trick。

2.算法上每次枚举起始点，但是起始点一定是在当前字符中，否则肯定距离更远了，因为最初始的0肯定是最近的。

嗯，其实这题我比赛没做出来，dfs超时了，改记忆化搜索的时候好像是hash函数写错了，过了10分钟才AC....

### 代码

```cpp
class Solution {
public:
    int minimumDistance(string word) {
        if(word.size()==2) return 0;
        int minMove=INT_MAX;
        unordered_map<int,int> hashMap;
        for(int ch1=0;ch1<word.size();ch1++){
            for(int ch2=ch1+1;ch2<word.size();ch2++){
                int x1;
                int y1;
                int x2;
                int y2;
                position(word[ch1],x1,y1);
                position(word[ch2],x2,y2);
                minMove=min(minMove,dfs(x1,y1,x2,y2,word,0,hashMap));
            }
        }
        return minMove;
    }
    
    int dfs(int x1,int y1,int x2,int y2,string& word,int i,unordered_map<int,int>& hashMap){
        if(i==word.size()) return 0;
        int current=i+y2*1000+x2*10000+y1*100000+x1*1000000;
        if(hashMap.count(current)!=0) return hashMap[current];
        int x;
        int y;
        position(word[i],x,y);
        int plan1=dfs(x,y,x2,y2,word,i+1,hashMap)+distance(x1,y1,x,y);
        int plan2=dfs(x1,y1,x,y,word,i+1,hashMap)+distance(x2,y2,x,y);
        hashMap[current]=min(plan1,plan2);
        return min(plan1,plan2);
    }
    
    int distance(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    
    void position(char ch,int& i,int& j){
        int pos=ch-'A';
        i=pos/6;
        j=pos%6;
        return ;
    }
};
```