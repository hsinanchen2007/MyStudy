将前面的行数作为当前所要求的行的返回值，然后递归的一般过程就是当前行和上一行的对应关系，代码如下：
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex==0)return vector<int> (1,1);
        if(rowIndex==1)return vector<int> (2,1);
        vector<int> vecc=getRow(rowIndex-1);
        vector<int> vecz(vecc.size()+1,1);
        for(int i=1;i<vecc.size();i++)
        {
            vecz[i]=vecc[i-1]+vecc[i];
        }
        return vecz;
    }

};
```