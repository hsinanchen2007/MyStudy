class Solution
{
    public boolean isArmstrong(int N)
    {
        int count =N;
        int num =0;
        List<Integer> list =new ArrayList();
        while (count/10!=0)
        {
            list.add(count%10);
            count =count/10;
            num++;
        }
        
        list.add(count);
        int nums =0;
        for(int i=0;i<list.size();i++)
        {
            nums+=Math.pow(list.get(i),num+1);
        }
        if (nums==N)
            return true;
        else 
            return false;
        
    }
}
list储存每一位数字，同时计算出数字的位数K， 求K次幂的和即可， 注意while循环结束时，最后一位没有被加进K，在求幂时需要加一