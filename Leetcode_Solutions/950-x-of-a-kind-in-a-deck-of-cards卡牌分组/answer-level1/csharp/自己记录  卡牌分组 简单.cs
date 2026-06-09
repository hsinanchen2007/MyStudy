### 解题思路

此题是求每个数字出现次数的最大公约数
先统计出各数都出现过几次 然后
### 代码

```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        
        int[] ct = new int [10000];             //统计每个数字出现过多少次
        for (int i=0; i<deck.Length;i++)
        {
            ct[deck[i]]+=1; 
        }                                               
            var query = from n in ct
                        where  n > 0
                        orderby n descending  
                        select n;
          int[] arr=  query.ToArray();       //将数组ct中非零的index筛选出装进新的数组arr
          int x=arr[0];
          
           foreach (int ele in arr)        //开始计算最大公约数 欧几里得法                                 
            {
                int max=Math.Max(x,ele);
                int min=Math.Min(x,ele);
                while (max%min!=0)
                {
                    x=max%min;
                    max=min;
                     max=Math.Max(x,max);
                     min=Math.Min(x,max);
                }
                 x=min;
                
                if (x==1){return false;}  // 如果最大公约数是1 则为false
            }
            
            return true;
            
    }
}
```