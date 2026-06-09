### 解题思路
找到需要转换的元素，会发现其实比上三角的部分还要小，缓存第一个元素，然后逆时针一圈替换即可。
感觉代码执行比想象中的要慢。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        long n = matrix.size();
        if(n==1){
            return;
        }
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int tempi = i;
                int tempj = j;
                int temp = matrix[i][j];
                for(int x=0;x<3;x++){
                    matrix[tempi][tempj] = matrix[n-1-tempj][tempi];
                    int t = tempi;
                    tempi = n-1-tempj;
                    tempj = t;
                }
                matrix[tempi][tempj] = temp;
            }
        }
    }
    // void printres(vector<vector<int>> res){
    //     for(vector<int> i:res){
    //         for(int j=0;j<i.size();j++){
    //             cout<<i[j];
    //         }
    //         cout<<',';
    //     }
    //     cout<<endl;
    // }
};

```