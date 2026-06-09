![}M~}M)3DH6SE\[\]XW}X5{TSP.png](https://pic.leetcode-cn.com/c2d8c34500c2854f07f749e7bef4f1885c48ae83377b39060bb029ba2a3e995f-%7DM~%7DM\)3DH6SE%5B%5DXW%7DX5%7BTSP.png)
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum=0;
        for(int a:A)
            sum+=a;
        if(sum%3!=0)
            return false;
        sum=sum/3;
        int a1=0;
        int k=0;
        int j=0;
        for(int i=0;i<A.length;i++)
        {
            a1+=A[i];
            if(a1==sum&&(j<=1||i==A.length-1))
            {
                j++;
                a1=0;
                continue;
            }    
            k++;
        }
        if(k==A.length-3)
            return true;
        return false;


    }
}