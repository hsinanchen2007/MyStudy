之前理解错了，0行就是第一行  ，所以后面有加1操作
```
class Solution {
public:
    vector<int>fun(vector<int>&res,int i){
        vector<int>temp;
        for(int j=1;j<=i;j++){
            if(j==1||j==i)
                    temp.push_back(1);
            else
                temp.push_back(res[j-2]+res[j-1]);
            }
        return temp;

    }
    vector<int> getRow(int rowIndex) {
        vector<int>res;
            if(rowIndex==0){
             res.push_back(1);
             return res;
        }
           
        res.push_back(1);
         for(int i=2;i<=rowIndex+1;i++)
                res=fun(res,i);
        return  res;
    }
};
```
