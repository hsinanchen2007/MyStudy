### 解题思路
![119.杨辉三角2.mp4](ffddb93a-4cfd-4fbc-a25d-188799a48a73)

总的来说就是利用杨辉三角形后一行与前一行的关系。
更新过程为：从倒数第二个元素开始往前更新 它等于原来这个位置的数 + 前一个位置的数
行[i] = 行[i] + 行[i-1]

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> kRows(rowIndex+1);//第K行的vector大小为 rowIndex+1
        for(int i = 0; i <= rowIndex; i++)//利用前一行求后一行，第K行要循环K遍
            {
            kRows[i] = 1;//行末尾为1
            for(int j = i; j > 1; j--)//每一行的更新过程
                {
                    kRows[j-1] = kRows[j-2] + kRows[j-1];
                }
            }
        return kRows;   
    }
};
```