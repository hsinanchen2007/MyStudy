![image.png](https://pic.leetcode-cn.com/4030c1787e09352d40c63ffe6220805a4a208d68a2a0adf9ccf4ce5ed4a08bb5-image.png)



```C++ []
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {};
        if(numRows == 0){
            return result;
        }
        vector<int> tempLast;
        for(int i = 0; i< numRows; i++){
            vector<int> temp(i+1,0);
            *temp.begin()=1;
            *(temp.end()-1)=1;
            if(i>1){
                for(int j=1; j!=temp.size()-1; j++){
                    temp[j] = tempLast[j-1]+tempLast[j];
                }
            }
            result.emplace_back(temp);
            tempLast = temp;
        }
        return result;
    }
};
```

