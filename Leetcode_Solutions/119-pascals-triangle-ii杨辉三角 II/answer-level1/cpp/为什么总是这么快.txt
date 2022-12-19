![image.png](https://pic.leetcode-cn.com/c4c5604c796ba998f519ecd017b0baee4be32ba38bfd813f1057d6f1c2ff5f14-image.png)

```C++ []
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tempLast;
        for(int i = 0; i<=rowIndex; i++){
            vector<int> temp(i+1,0);
            *temp.begin()=1;
            *(temp.end()-1)=1;
            if(i>1){
                for(int j=1; j!=temp.size()-1; j++){
                    temp[j] = tempLast[j-1]+tempLast[j];
                }
            }
            tempLast = temp;
        }
        return tempLast;
    }
};
```

