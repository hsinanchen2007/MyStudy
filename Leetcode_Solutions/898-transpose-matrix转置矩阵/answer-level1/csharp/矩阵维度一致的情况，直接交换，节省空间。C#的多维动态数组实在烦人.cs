### 解题思路
矩阵维度一致的情况，直接交换，节省空间。C#的多维动态数组实在烦人

### 代码

```csharp
public class Solution {
    public int[][] Transpose(int[][] A) {  
        int width = A[0].Length;
        int hegith = A.Length;
        if(width == hegith){
            for (int i = 0; i < width; i++){                
                for (int j = 0; j < hegith; j++){
                    if(i < j){   
                        int temp = A[i][j];                 
                        A[i][j] = A[j][i];
                        A[j][i] = temp;
                    }
                }
            }
            return  A;
        }else{
            int[][] B=new int[A[0].Length][];
            for(int i = 0;i<A[0].Length;i++)
            {
                B[i]=new int[A.Length];
                for(int j=0;j<A.Length;j++)
                {
                    B[i][j]=A[j][i];
                }
            }
            return B;
        }           
    }
}
```