```c++
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size()<=1)
            return 0;
        vector<int> del; del.clear();
        for(int i=0;i<A[0].length();i++)
        {
            int flag = 1;
            for(int j=0;j<A.size()-1;j++)
            {
                if(A[j][i]<=A[j+1][i])
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                del.push_back(i);
        }
        return del.size();
    }
};