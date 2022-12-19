嚯嚯嚯，第一个发布题解。
可以看到题目中的要求，素数和素数索引的数目是一定的，所以就是一个全排列，其他的合数也是一个全排列，两个全排列相乘就是我们想要求的结果啦。首先是求素数，可以用一个数的平方根来判断，比较快。然后求阶乘，long long 才行，int溢出了。需要注意的是模运算的性质，比如((a%n)*(b%n))%n = (a*b)%n,这里的n可以随便搬到括号外面，改变位置，结果是一样的，有兴趣可以自己证明

```
class Solution {
public:
    int numPrimeArrangements(int n) {
        int count=0;
        int flag = 1;
        if(n==1||n==2)return 1;
       
        
        for(int j=3;j<=n;j++){
            flag=1;
            for(int i=2;i*i<=j;i++){
                if(j%i==0){
                    flag = 0;
                    break;              
                }      
            }
             if(flag==1){
                count++;
            }
     }
    count+=1;
    int num = 0;
     num+=(Factorial(count)*Factorial(n-count))%(1000000000+7);
     return num;
    }
    long long Factorial(int n){
        long long sum = 1;
        for(int i=1;i<=n;i++){
            sum*=i;
            sum=sum%(1000000000+7);
        }
        return sum;
    }
};
```




