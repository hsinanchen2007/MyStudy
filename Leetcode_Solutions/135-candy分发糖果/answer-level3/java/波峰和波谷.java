### 解题思路
此处撰写解题思路
既然有趋势那就有波峰和波谷，
找到每一个递增和递减长度inr 和 dec；
然后每个递增sum往上加，但是注意波峰加了两次所以把波峰中小的那个去掉
当这个点的左右有变动的时候就要把i--免得跳过了一个点
### 代码

```java
class Solution {
    public int candy(int[] ratings) {
        //其实就是求递增的序列 每个都比前面大那就1，2，3，4加上去
        int sum=ratings.length;
        for(int i=1;i<ratings.length;i++){
            int inr = 0;
            while(i<ratings.length && ratings[i]>ratings[i-1]){
                inr++;
                sum+=inr;
                i++;
            }
            int dec = 0;
            while(i<ratings.length && ratings[i]<ratings[i-1]){
                dec++;
                sum+=dec;
                i++;
            }
            int min = Math.min(inr, dec);
            sum-=min;
            if(Math.max(inr, dec)>0){
                i--;
            }
        }
        return sum;
    }
}
```