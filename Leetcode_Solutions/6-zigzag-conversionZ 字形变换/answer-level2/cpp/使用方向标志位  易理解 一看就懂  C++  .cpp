```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string> matrix(min(numRows,int(s.size())));
        /*字符串组成的一维数组可以看作字符组成的二维数组
        min()的作用：例如s的长度为4 numRows为10， 此时matrix的行数为4即可
        */
        int direction=1; //方向标志
        int i=0;
        for(char c:s){
            matrix[i].push_back(c);
            if(direction==1&&i==numRows-1)
                direction=-1;
            else if(direction==-1&&i==0)
                direction=1;
            i+=direction;
        }
        string res;
        for(string row:matrix)
            res+=row;
        return res;
        
        
    }
};
```
