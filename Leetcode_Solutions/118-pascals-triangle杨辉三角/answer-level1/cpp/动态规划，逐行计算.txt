``` C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        vector<int> temp;
        for(int i=1;i<=numRows;i++)
        {
            if(i==1)
                temp.push_back(1);
            else
            {
                vector<int> help=temp;              //辅助容器，直接用temp不可以
                for(int j=0;j<temp.size()-1;j++)
                {
                    temp[j+1]=help[j]+help[j+1];
                
                }
                temp.push_back(1);   //最后一个数是1
            } 
            res.push_back(temp);
        }
        return res;
    }
};
```