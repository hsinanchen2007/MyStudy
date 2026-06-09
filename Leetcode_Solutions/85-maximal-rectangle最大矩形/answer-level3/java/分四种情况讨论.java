class Solution {
    public int maximalRectangle(char[][] matrix) {
        
        int n1 = matrix.length;
        if(n1 == 0)
        {
            return 0;
        }
        int n2 = matrix[0].length;
        
        int temp = 0;
        int result = 0;
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(matrix[i][j]=='1')
                {
                    temp = 1;
                    result = Math.max(countArea(i,j,matrix,n1,n2,temp),result);
                }
            }
        }
        return result;
    }
    
    public int countArea(int i,int j,char[][] matrix,int n1,int n2,int temp)
    {
        if((i+1<n1 && matrix[i+1][j]=='0') || i+1==n1)
        {
            while(j+1<n2 && matrix[i][j+1]=='1')
            {
                j++;
                temp++;
            }
        }
        else if((j+1<n2 && matrix[i][j+1]=='0') || j+1==n2)
        {
            while(i+1<n1 && matrix[i+1][j]=='1')
            {
                i++;
                temp++;
            }
        }
        else if(i+1<n1 && j+1<n2 && matrix[i+1][j+1]=='0')
        {
            int p = temp;
            int p1 = i;
            int p2 = j;
            while(j+1<n2 && matrix[p1][j+1]=='1')
            {
                j++;
                p++;
            }
            while(i+1<n1 && matrix[i+1][p2]=='1')
            {
                i++;
                temp++;
            }
            temp = Math.max(temp,p);
        }
        else if(i+1<n1 && j+1<n2 && matrix[i+1][j+1]=='1')
        {
            int temp1 = 4;
            int temp2 = 4;
            int temp3 = 0;
            
            int k1 = i+2;
            int k2 = j+2;
            while(k1<n1 && matrix[k1][j]=='1' && matrix[k1][j+1]=='1')
            {
                k1++;
                temp1 = temp1 +2;
            }
            while(k2<n2 && matrix[i][k2]=='1' && matrix[i+1][k2]=='1')
            {
                k2++;
                temp2 = temp2 +2;
            }
            
            for(int m1=i+2;m1<k1;m1++)
            {
                for(int m2=j+2;m2<k2;m2++)
                {
                    if(matrix[m1][m2]=='1')
                    {
                        temp3 = Math.max((m1-i+1)*(m2-j+1),temp3);
                    }
                    else
                    {
                        k2=m2;
                    }
                }
            }
            temp = Math.max(Math.max(temp1,temp2),temp3);
        }
        return temp;
    }
}