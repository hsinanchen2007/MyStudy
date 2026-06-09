### 解题思路


### 代码

```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int cnt=0;
        for (int i=0;i<row.size();i++){
            row[i]=int(row[i]/2);
        }
        for(int i=0;i<row.size();i+=2){
            int x=row[i];
            if(x==row[i+1]) continue;
            for (int j=i+2;j<row.size();j++){
                if (row[j]==x){
                    swap(row[j],row[i+1]);
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
```