
![捕获.PNG](https://pic.leetcode-cn.com/28e2ca635fab841c61f650b58cbcd34b23a1cf8352ae904dbf5180aa37d9dbad-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>a={1},b={1,1};
        if(rowIndex==0)return a;
        if(rowIndex==1)return b;
        for(int i=2;i<=rowIndex;i++){
            a.clear();
            a.push_back(1);
            for(int j=1;j<=i;j++){
                if(j==i){
                    a.push_back(1);
                }
                else{
                    a.push_back(b[j-1]+b[j]);
                }
            }
            b.clear();
            b=a;
        }
        return b;
    }
};
```