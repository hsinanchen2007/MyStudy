class Solution {
public:
    int num = 0;
    int c[100];
    int totalNQueens(int n) {
        backtract(0,n);
        return num;
    }
    void backtract(int k,int n)
    {
        int i,j;
        if( k == n)
        {
            num ++;
            return ;
        }
        for(i = 0; i < n; i++)
        {
            c[k] = i;
            for(j = 0; j < k; j++)
            {
                if(c[j] == i||abs(k-j)==abs(i-c[j]))
                    break;
            }
            if(j == k)
                backtract(k+1,n);
        }
    }
};