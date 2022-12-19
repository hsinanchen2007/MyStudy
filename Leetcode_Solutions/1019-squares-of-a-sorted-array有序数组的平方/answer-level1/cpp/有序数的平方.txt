//代码的思路就是两头访问A，进行绝对值比较后，选择大数进行平方后从B的尾往前输入。
vector<int> sortedSquares(vector<int>& A) {
        vector<int>::iterator be = A.begin();
        vector<int>::iterator en = A.end() - 1;
        int L = A.size();
        vector<int> B(L,0);
        vector<int>::iterator enB = B.end() - 1;
        while (L--)
        {
            if(*en <= 0 || (*be < 0 && -*be >= *en))
            {
                *enB = *be * *be;
                enB--;
                be++;
            }
            else if((*be < 0 && -*be <= *en) || *be >= 0)
            {
                *enB = *en * *en;
                enB--;
                en--;
            }
        }
        return B;