执行用时：48ms
内存消耗：14.1MB
```
public class Solution
{
    public int Reverse(int x)
    {  
        long result1 = 0;
        int result = 0;
        int length = 0; 
        //获取输入整数长度
        if(x == -2147483648)
        {
            length = 10;
        }else{
            length = Math.Abs(x).ToString().Length;
        }
        //根据长度创建合适的数组
        int[] num = new int[length];
        //反转取各位数
        for (int i = 0; i < length; i++)
        {
            num[i]= x % 10;
            x = x/10;
        }
        //用long做标，判断int是否溢出
        for (int i = 0; i < length; i++)
        {
            result =  10*result + num[i];
            result1 =  10*result1 + num[i];
        }
        //判断正负及溢出，输出合适的结果
        if (x == Math.Abs(x) && result == result1  ){
            return result;
        }
        else if(x == -Math.Abs(x) && result == result1  ){
            return -result;
        }else{
            return 0;
        }
    }
}
```
效率和调用c#库类似，但内容更基础，适合新手学习熟悉c#。
