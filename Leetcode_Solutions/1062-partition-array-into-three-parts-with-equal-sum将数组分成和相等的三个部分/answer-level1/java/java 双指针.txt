左右双指针，去找左边的终点和右边的起点，保持从[0,i)和(j,A.length-1]都为sum/3，之后再去判断[i,j]。

**记住在寻找时，不要因为这段和大于sum/3，就停止寻找**。
同时不要投机取巧尝试记录数组中加和等于sum/3的次数。

时间复杂度O(2N)两次O（N），空间复杂度O(1)。
```
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        //左右双指针，保持从[0,i)和(j,A.length-1]都为sum/3，之后再去判断[i,j]
        if(A==null||A.length==0)
            return false;
        int i = 0;
        int j = A.length-1; 
        int sum = 0;
        for(int a:A)
        {
            sum+=a;
        }
        int leftsum = 0;
        int rightsum = 0;
        //找左边[0，i),其实这里也可以写i<j-1,至少要把j-1和j分别留给后面两段
        while(i<j){
            leftsum+=A[i++];
            if(leftsum==sum/3)
                break;
        }
        //是否找到右边
        if(leftsum!=sum/3)
            return false;
        //找右边(j,A.length-1],注意这里不能是i<=j，因为至少要把i的值留给中间那段。
        while(i<j)
        {
            rightsum+=A[j--];
            if(rightsum==sum/3)
                break;
        }
        if(rightsum!=sum/3)
            return false;
        //找到了左边和右边的，现在去找中间的，因为上面i和j再加上最后一位之后又右移和左移了，所以中间这段应该是[i,j]
        int midsum = 0;
        while(i<=j){
            midsum+=A[i++];
        }
        if(midsum==sum/3)
            return true;
        else
            return false;
        
        
    }
}
```
