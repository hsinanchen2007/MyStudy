```

class Solution {
    //先算出初始A中的所有偶数和SUM。再判断改变的项对原偶数和有什么影响。
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int > end {};
        vector<int > even_index{};
        int temp =0 ;
        int sum =0;
        int num =0;
        
        for(auto& c:A){
            if (c%2==0){
                sum +=c; 
            }
        }
        
        for(int i = 0; i< queries.size();i++){
            num=queries[i][1];
           
            temp = A[num];
            A[num] += queries[i][0];
            

            if(temp%2==0&& A[num]%2 == 0 ){
                sum = sum -temp+A[num];
                end.push_back(sum);

            }
            if(temp%2==0&& A[num]%2 !=0){
                sum -= temp;
                end.push_back(sum);

            }
            if(temp%2!=0&&A[num]%2 == 0){
                sum +=A[num];
                end.push_back(sum);
            }
            if(temp%2!=0 && A[num]%2!=0){
                end.push_back(sum);
            }

        }
        return end;

        
    }
};
```
![image.png](https://pic.leetcode-cn.com/eb3f97f2eb4516c55756074fbbd65fe3c7a80f7cdc14e97fc2cd6a8fe79967ca-image.png)
