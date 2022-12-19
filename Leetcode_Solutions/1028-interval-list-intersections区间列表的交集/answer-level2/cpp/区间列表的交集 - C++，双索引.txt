```
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int AIndex = 0;   // A数组的索引
        int BIndex = 0;   // B数组的索引
        vector<vector<int>> result; //存储结果值
        result.reserve(A.size() + B.size()); //一次创建足够容纳所有数据的空间
        while(AIndex != A.size() && BIndex != B.size()){ //当A,B的访问索引均没有跳出范围时
            vector<int> A_one = A[AIndex]; //得到A的当前区间
            vector<int> B_one = B[BIndex]; //得到B的当前区间
            
            int leftValue = max(A_one[0],B_one[0]); //得到两个当前区间的左值的较大值 
            int rightValue = min(A_one[1],B_one[1]); //得到两个当前区间的右值的较小值 
            
            if (leftValue <= rightValue) //判断是否存在交集区间
                result.push_back({leftValue,rightValue});
            
            //分三种情况进行索引递增操作
            if (A_one[1] < B_one[1]) 
                AIndex++;
            else if(A_one[1] == B_one[1])
                {AIndex ++; BIndex ++;}
            else
                BIndex++;        
        }
        return result;        
    }
};
```