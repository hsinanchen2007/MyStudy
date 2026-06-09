### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        pair<int,int> now(0,0);//now表示当前的字母位置
        for(int i=0;i<target.size();i++){
            int p=target[i]-'a';
            pair<int,int> next(p%5,p/5);//next表示下一个字母的位置
            pair<int,int> pis;//pis表示偏移量
            bool flag=0;
            if(next.first==0&&next.second==5&&(now.first!=0||now.second!=5)){//下一个字母是Z，先移动到u，然后在最后加上一个‘D’
                pis.first=0-now.first;
                pis.second=4-now.second;
                flag=1;
            }
            else if((next.first!=0||next.second!=5)&&now.first==0&&now.second==5){//当前字母是Z
                ans+='U';//先上移到U
                pis.first=next.first-0;
                pis.second=next.second-4;
            }
            else {//两个都不是Z或者两个都是Z的情况
                pis.first=next.first-now.first;
                pis.second=next.second-now.second;
            }
            now=next;
            if(pis.second>0){
                ans+=string(pis.second,'D');
            }
            else{
                ans+=string(-pis.second,'U');    
            }
            if(pis.first>0){
                ans+=string(pis.first,'R');
            }
            else ans+=string(-pis.first,'L');
            if(flag) ans+='D';//对应于下一个地址是Z的情况
            ans+='!';
        }
        return ans;
    }
};
```