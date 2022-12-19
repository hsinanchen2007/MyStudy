需要注意：
（1）如果每次更新都遍历A求偶数和，会涉及两层循环，提交超时。所以，只能使用动态规划：提前算出A中偶数和，每次更新去调整这个值即可；
（2）负奇数对2取模的值是-1，正奇数对2取模的值是1，偶数（不分正负）对2取模的值都是0，因此，如果判断奇数只能使用val%2!=0


```
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> answer;
        int sum = 0;
        for(int j=0;j<A.size();j++)
        {
            if(A[j]%2==0)
                sum += A[j];
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            A[index] += val;
            
            if(A[index]%2==0)
            {
                if(val%2==0)
                    sum += val;
                else
                    sum += A[index];
            }
            else
            {
                if(val%2!=0)
                    sum -= (A[index] - val);
            }
            answer.push_back(sum);
        }
        return answer;
    }
};



```