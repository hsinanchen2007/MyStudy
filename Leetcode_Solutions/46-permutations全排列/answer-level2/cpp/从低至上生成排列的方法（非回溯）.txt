### 解题思路
数据[1,2,3]
    开始                                1
    插入2                           12               21
    插入3                      312 132 123      321  231 213
    ....                            ...                ...

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0){
            return vector<vector<int>>{vector<int>()};
        }
        vector<vector<int>> temp;
        temp.push_back(vector<int>{nums[0]});
        for(int i=1;i<nums.size();i++){
                vector<vector<int>> tp2;
                int len=i+1;
                for(int j=0;j<temp.size();j++){
                    for(int k=0;k<len;k++){
                        vector<int> tp3(len,0);
                        for(int n=0;n<k;n++)
                            tp3[n]=temp[j][n];
                        tp3[k]=nums[i];
                        for(int n=k+1;n<len;n++){
                              tp3[n]=temp[j][n-1];
                        }
                        tp2.push_back(tp3);
                    }
                }
                temp.swap(tp2);
            }
        return temp;
    }
};
```