//矩形旋转
//本方法是对点进行旋转，例如7-1-3-9-7这样进行点的旋转
class Solution {
    public void rotate(int[][] matrix) {
        
      int n = matrix.length;
            
      for(int i=0;i<n;i++)
      {
        for(int j=n-1-i;j>=i+1;j--)
        {//只需要对二维数组中有限个点，进行旋转，例如对给出的例1中，只需对7,4两个点进行矩形旋转
          int temp = matrix[j][i];//找到要旋转的点
          //这里需要发现，对于matrix[j][i]这个点来说，它旋转后的位置为matrix[i][n-j-1]
          //然后开始递归就行
          
          recur(j,i,matrix,temp,0);//进行递归
          
          //matrix[i][n-j-1]
        }
      }
      
      
    }
  
  public void recur(int j,int i,int[][] matrix,int temp,int count)
  {//count的作用是进行计数，每一个点只需旋转四次即可
    
    int n = matrix.length;
    
    if(count==4)
    {
      
    }
    else
    {
      count++;
      int t = matrix[i][n-j-1];//保留被替代点的值，进行递归
      matrix[i][n-j-1] = temp;
      recur(i,n-j-1,matrix,t,count);
    }
    
  }
}