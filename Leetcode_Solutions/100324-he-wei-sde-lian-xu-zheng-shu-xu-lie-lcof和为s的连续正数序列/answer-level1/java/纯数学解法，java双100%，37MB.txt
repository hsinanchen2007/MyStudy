### 解题思路
1.该题要求解的是一组连续的整数，那么这组整数[m,m+1,m+2...]有两个特征，一是数字的起始位置m，二是数字的个数n，那这组数的和S=m+m+1+m+2+...=n*m+(1+2+3+...+n-1)=n*m+n(n-1)/2,其中2<=n<Math.sqrt(2target)(下界为2即最少有两个整数，最大根据解不等式Σ(1,k)<=target所得)，该问题就转化为当S=target时，式子S可变形为m=(target-n(n-1)/2)/n,求是否存在正整数m，代码存在瑕疵，内存可以优化更好，太懒了没修改。

### 代码

```java
class Solution {
    
    public int[][] findContinuousSequence(int target) {
        int m=0;//正整数起点
        int count=0;//结果个数
        int r=(int)Math.sqrt(2*target);//循环上界
        int [][]result=new int[r][];
        for(int n=2;n<Math.sqrt(2*target);n++){
            int judge=target-n*(n-1)/2;
            if(judge%n==0){
                m=judge/n;
                int[]temp=new int[n];
                for(int i=0;i<n;i++){
                    temp[i]=m+i;
                }
                result[count++]=temp;
            }
        }
        int[][]arr=Arrays.copyOf(result,count);
        int[][]temp=Arrays.copyOf(arr,count);
        int hi=count-1;
        for(int i=0;i<count;i++){
            arr[i]=temp[hi--];
        }//反转数组
        return arr;
    }
   


}
```