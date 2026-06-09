### 解题思路
此处撰写解题思路

    //1、数组得排序，选择由小到大排序
    //2、将数组分组，分成负数、正数或0 2组数
    //3、判断k 的与负数数组比较，这里逻辑比较多，当k<=size时，把所有负数转正即可，当k>size时，需要比较最大负数和最小的正数绝对值（因为这个数是要用来扣减的），如果负数小于正数，那么负数要扣减2次，因为前面已经把这个负数变正累加了
### 代码

```java
class Solution {
   
    public int largestSumAfterKNegations(int[] A, int k) {
          sort(A);
          //小于0
          List<Integer> negA = new ArrayList<Integer>();
          //大于等于0
          List<Integer> regA = new ArrayList<Integer>();
          for(int i=0;i<A.length;i++){
              if(A[i]<0){
                negA.add(A[i]);  
              }else{
                 regA.add(A[i]);
              }
          } 
          int sum=0;
          int negASize = negA.size();
          int regSize = regA.size();
          if(negASize>0){
              if(negASize >= k){
                  for(int i=0;i<negASize;i++){
                      if(i<k){
                          sum=sum-negA.get(i);
                      }else{
                          sum=sum+negA.get(i);
                      }
                  }
                   for(int j=0;j<regSize;j++){
                             sum=sum+regA.get(j);
                        }
              }else{
                   for(int i=0;i<negASize;i++){
                          sum=sum-negA.get(i);
                  }
                  //不能被2整除，需要考虑最大的负数同最小的正绝对值哪个大
                  if((k-negASize)%2==1){
                      if(Math.abs(negA.get(negASize-1))>regA.get(0)){
                         for(int i=1;i<regSize;i++){
                             sum=sum+regA.get(i);
                         }
                        sum=sum-regA.get(0);
                        
                      }else{
                           for(int i=0;i<regSize;i++){
                             sum=sum+regA.get(i);
                            }
                            //第一次转正数时不应该加，所以这里再多减一次
                            sum=sum+(2*negA.get(negASize-1));
                      }
                  }else{
                       for(int j=0;j<regSize;j++){
                             sum=sum+regA.get(j);
                         }
                  }
              }

          }else{
            if(k%2==1){
                for(int i=1;i<A.length;i++){ 
                    sum=sum+A[i];
                }
                  sum=sum-A[0];
            }else{
                for(int i=0;i<A.length;i++){ 
                    sum=sum+A[i];
                }
            }
          }
        return sum;
    }
    //冒泡排,将数组由小到大排序
    void sort(int[] A){
        int n= A.length;
        for(int j=0; j<n-1; j++){
            for(int i=0;i<n-j-1;i++){
                if(A[i]>A[i+1]){
                    swap(A,i,i+1);
                }
                
            }
        }
    }

    //冒泡排序置换相邻元素
    void swap(int[] A,int i, int j){
        int temp = A[i];
            A[i]=A[j];
            A[j]=temp;
    }
}
```