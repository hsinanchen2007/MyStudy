### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
       int[] arrList=arr;
      //先用一个冒泡排序

      for(int i=0;i<arrList.Length-1;i++)
      {
          for(int j=i;j<arrList.Length;j++)
          {
              if(arrList[i]>arrList[j])
              {
                  int temp=arrList[i];
                  arrList[i]=arrList[j];
                  arrList[j]=temp;
              }
          }
      }


     int[] return_K=new int[k];

      for(int i=0;i<return_K.Length;i++)
      {
          return_K[i]=arrList[i];
      }

      return return_K;

    }
}
```