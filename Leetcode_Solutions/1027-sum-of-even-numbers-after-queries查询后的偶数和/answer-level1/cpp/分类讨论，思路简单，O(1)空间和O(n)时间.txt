### 解题思路
1.遍历数组A，把所有的偶数元素相加得到sum（这么做是为了后面val和index操作的时候不用重新遍历数组A）
2.按照题意进行操作，得到val和index
3.(重点)分四种情况讨论，对sum进行操作：
    A[index]%2==0 && A[index]-val)%2==0
    A[index]%2==0 && A[index]-val)%2!=0
    A[index]%2!=0 && A[index]-val)%2==0
    A[index]%2!=0 && A[index]-val)%2!=0
4.返回res
### 代码

```cpp
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int val =0,index=0;
        int len = A.size();
        int sum =0;
        for(int i =0;i<len;i++){
            if(A[i]%2==0){
                sum += A[i];
            }
        }
        for(int i =0;i<len;i++){
            val = queries[i][0];
            index = queries[i][1];
            A[index] = A[index]+val;
            if(A[index]%2==0&&(A[index]-val)%2==0){
                sum = sum + val;
            }else if(A[index]%2==0&&(A[index]-val)%2!=0){
                sum = sum + A[index];
            }else if(A[index]%2!=0&&(A[index]-val)%2==0){
                sum = sum - (A[index]-val);
            }else{
                sum =sum;
            }
            res.push_back(sum);
        }
        return res;
    }
};
```