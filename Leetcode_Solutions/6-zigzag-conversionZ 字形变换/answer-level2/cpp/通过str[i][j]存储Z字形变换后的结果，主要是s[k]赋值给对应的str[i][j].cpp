### 解题思路
通过str[i][j]存储Z字形变换后的结果，主要是s[k]赋值给对应的str[i][j]

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(s.size()==0)
            return res;
        if(numRows==1)
            return s;
        int n=s.size(),x,y;
        x=n/(numRows*2-2);
        y=n%(numRows*2-2);
        if(y<=numRows)
            y=1;
        else
            y=y-numRows+1;
        y=x*(numRows-1)+y;
        x=numRows;
        char str[x][y];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                str[i][j]=' ';
        for(int k=0;k<s.size();k++){
            int i=0,j=0;
            i=(k+1)/(numRows*2-2);
            j=(k+1)%(numRows*2-2);
            cout<<i<<' '<<j<<endl;
            if(j==0){
                j=i*(numRows-1)-1;
                i=1;
            }
            else
                if(j<=numRows){
                    int temp=j;
                    j=i*(numRows-1);
                    i=temp-1;
                }
                else{
                    int temp=j;
                    j=i*(numRows-1)+j-numRows;
                    i=2*numRows-temp-1;
                }
            cout<<s[k]<<' '<<i<<' '<<j<<endl;
            str[i][j]=s[k];
        }
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                if(str[i][j]!=' ')
                    res+=str[i][j];
        return res;
    }
};
```