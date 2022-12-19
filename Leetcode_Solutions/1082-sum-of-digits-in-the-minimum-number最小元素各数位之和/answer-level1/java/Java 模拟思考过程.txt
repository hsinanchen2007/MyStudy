过程清晰，用list存储每一位数字，求和判断
class Solution 
{
    public int sumOfDigits(int[] A)
    {
        Arrays.sort(A);
        int x =A[0];
        List<Integer> list = new ArrayList();
        while(x/10!=0)
        {
            list.add(x%10);
            x=x/10;
            
        }
        for(int i=0;i<list.size();i++)
        {
            x+=list.get(i);
        }
        if(x%2==0)
            return 1;
        return 0;
    }
}