### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        //2*n+ 2-1
        //3*n+3
        //4*n+3+4-1
        //5*n+10
        //6*n + 10+6-1
        //.....
        //k为奇数: k*(n+(k-1)/2)    可为奇数或偶数      
        //k为偶数 : k*(n+(k-2)/2) +k-1      只能为奇数
        //等差公式和： k*(n+n+k-1)/2
        //化简一下:偶数 k*n+k*k/2-2*k + k -1 = k*k/2 + k*(n-1) - 1
        //最多的序列数：(k*(k+1))/2 = target   k = 
        
        
        int MaxNumSize = 0 ; 
        for(int i =  1 ; i <=target ; i++){
            int sum = i*(i+1)/2;
            if(sum > target){
                MaxNumSize = i-1;
                break;
            }else if(sum == target){
                MaxNumSize = i;
                break;
            }
        }
        int[][] ans = new int[MaxNumSize-1][];
        boolean isOdd = false;
        int k = MaxNumSize ; //k表示有几个数相加
        int numsIndex = 0;
        if(target%2 == 1)
        isOdd = true;
        

        while(k>1){
        for(int i =1  ;i <= (target-1)/k ; i++){
            if( k*(i+i+k-1)/2 == target){
                int temp = k;
                ans[numsIndex] = new int[k];
                for(int j = 0 ; j <k ; j++)
                ans[numsIndex][j] = i+j;

                numsIndex++;
                k--;
                break;
            }
            
            if(i == (target-1)/k){
                k--;
                break;
            }
        }
        }
        //将多申请的空间去掉
        //fuck
        int[][] realAns = new int[numsIndex][];
        for(int i = 0 ; i < numsIndex ; i++){
            realAns[i] = ans[i];
        }
        return realAns;
    }
}
```