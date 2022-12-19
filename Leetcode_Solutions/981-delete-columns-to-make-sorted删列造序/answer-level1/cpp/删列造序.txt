### 解题思路
理解题的意思很重要，本题实际上就是求降序的列数，然后返回；
可以把次题想成一个2维数组，里面放着字符（小写字母），然后利用俩个for循环计算降序的列数。

### 代码

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.empty()){
            return 0;
        }

        int ans=0;
        int rows=A.size(),cols=A[0].size();

        for(int j=0;j<cols;j++){
            for(int i=0;i<rows-1;i++){
                if(A[i][j]>A[i+1][j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
```