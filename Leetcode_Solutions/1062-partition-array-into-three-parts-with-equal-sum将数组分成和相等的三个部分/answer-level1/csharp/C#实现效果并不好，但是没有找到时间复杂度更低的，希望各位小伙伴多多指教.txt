### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool CanThreePartsEqualSum(int[] A) 
    {
      int sum=0;

      for(int i=0;i<A.Length;i++)//输入数组的总和
      {
          sum+=A[i];
      }
      if(sum%3!=0)//如果target*3不等于sum说明不能被整除
      {
          return false;
      }
      int target=sum/3;
      int part=0;
      int a=0;
       for(int i=0;i<A.Length;i++)
       {     
       part+=A[i];   
       if(part==target) 
       {
           part=0;
           a++;      
       }    
       }   
       if(a>=3)//表明将数组分为三个部分即输出正确
       {
        return true; 
       }
       else
       {
           return false;
       } 
       
    }
     
}
```