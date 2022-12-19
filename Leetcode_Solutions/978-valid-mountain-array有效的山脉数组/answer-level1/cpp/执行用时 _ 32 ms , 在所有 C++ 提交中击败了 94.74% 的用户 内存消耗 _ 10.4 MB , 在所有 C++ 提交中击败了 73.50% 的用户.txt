 看好像没人这么考虑，可以找到最大峰，以及保证没有底峰或者底平底，就可以认为是山脉数组了
bool validMountainArray(vector<int>& A) {
        int L=A.size(),count=0,count2=0,count3=0;
        if(L<3)
            return false;
        for(int i=1;i<L-1;i++)
        {
             if(A[i]>A[i-1]&&A[i]>A[i+1])
             {
                 count++;
             }
            else if(A[i]<=A[i-1]&&A[i]<=A[i+1])
                count2++;
                
        } 
        if(count==1&&count2==0)
            return true;
        else
            return false;
    }