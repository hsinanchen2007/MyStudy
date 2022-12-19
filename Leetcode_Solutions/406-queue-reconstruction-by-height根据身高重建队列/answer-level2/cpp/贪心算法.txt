### 解题思路
先考虑高的人，矮的人可以认为对高的人不可见。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        vector<vector<int>> item(people);
        int* check = new int[people.size()];
        for(int i=0;i<people.size();i++){
            check[i]=0;
        }
        int maxInt = -1;
        int flag = 0;
        for(int i=0;i<people.size();i++){
            if(check[i]==0){
                flag = 1;
                break;
            }
        }
        while(flag==1){
            maxInt = -1;
            vector<vector<int>> inputArray;
            for(int i=0;i<item.size();i++){
                if(item[i][0]>maxInt&&check[i]==0){
                    maxInt = item[i][0];
                }
            }
            for(int i=0;i<item.size();i++){
                if(item[i][0]==maxInt){
                    check[i]=1;
                    inputArray.push_back(item[i]);
                }
            }
            for(int i=1;i<inputArray.size();i++){
                for(int j=0;j<inputArray.size()-i;j++){
                    if(inputArray[j+1][1]<inputArray[j][1]){
                        swap(inputArray[j+1],inputArray[j]);
                    }
                }
            }
            for(int i=0;i<inputArray.size();i++){
                result.insert(result.begin()+inputArray[i][1], inputArray[i]);
            }
            flag = 0;
            for(int i=0;i<people.size();i++){
                if(check[i]==0){
                    flag = 1;
                    break;
                }
            }
        }
        return result;
    }
};
```