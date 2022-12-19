1.board中的字母是按字母表顺序的，所以坐标可以算出.
2.比较特殊的位置，最后一行的'z'不能向右，字母'v','w','x','y'无法向下，一个解决办法是让路径优先向上，向左走;
3.pos是当前走到的位置，temp是计算出的下一个字母的位置，(x,y)是这两个坐标的差值(或者说向量)，根据(x,y)往s中插入什么字母以及插入字母的个数
```
class Solution {
public:
    string alphabetBoardPath(string target) {
       // vector<string> board={"abcde","fghij","klmno","pqrst","uvwxy","z"};
        string s="";
        pair<int,int> pos;//起点
        pos.first=0;pos.second=0;
        for(int i=0;i<target.length();i++){
            pair<int,int> temp;//目标值
            temp.first =int(target[i]-'a')%5;
            temp.second=int(target[i]-'a')/5;
            int x =temp.first-pos.first;
            int y=temp.second-pos.second;
            if(x<0)
                while(x<0){
                    s+='L';
                    x++;
                }
            if(y<0)
            while(y<0){
                s+='U';
                y++;
            }
            if(x>0)
            while(x>0){
                s+='R';
                x--;
            }
            if(y>0)
            while(y>0){
                s+='D';
                y--;
            }
            s+='!';
            pos.first=temp.first;
            pos.second=temp.second;
        }
        return s;
    }
};
```
