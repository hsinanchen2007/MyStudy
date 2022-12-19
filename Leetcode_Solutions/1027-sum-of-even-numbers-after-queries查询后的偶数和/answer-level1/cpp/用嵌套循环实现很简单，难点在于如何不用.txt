```
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        
        vector<int> output;
        
        int sum_even = 0;
        
        for(int i=0; i<A.size(); i++){//遍历元数组，求出赋值前的偶数和
            
            if(A[i]%2==0)
                sum_even += A[i];
        }
        
        
        for(int i=0; i<queries.size(); i++){
            
            int temp = A[queries[i][1]];//创建一个指针指向val赋值前的A[index]
            
            A[queries[i][1]] += queries[i][0];//将val加到A[index]上
            
            if(temp%2==0 && queries[i][0]%2==0)//如果赋值前A[index]是偶数，赋值val也是偶数，则sum要加上val
                sum_even += queries[i][0];
            else if(temp%2==0 && queries[i][0]%2!=0)//如果赋值前A[index]是偶数，赋值val是奇数，则sum要减去赋值前的A[index]
                sum_even -= temp;
            else if(temp%2!=0 && queries[i][0]%2!=0)//如果赋值前A[index]是奇数，赋值val也是奇数，则sum要加上赋值后的A[index]
                sum_even += A[queries[i][1]];
            
            output.push_back(sum_even);
        }
        

        
        return output;
        
        
    }
};
```
