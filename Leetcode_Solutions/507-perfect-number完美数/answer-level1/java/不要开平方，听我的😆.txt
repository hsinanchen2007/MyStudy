![image.png](https://pic.leetcode-cn.com/26a6c42c4c75dc866bde2f89b0e188504ab6b2f17c5f281a199533a29c134a57-image.png)

```java
class Solution {
    public boolean checkPerfectNumber(int num) {
        /*
        1.奇数肯定不是完美数
        2.对于数字28，可以判断2-28/2范围内的可以整除的数，然后加起来看是否和28相等
        上面的方法逐个判断有冗余，因为28%2=0，28%14=0，判断了2次，我们可以减少为一次判断
        具体的，当我们知道28%2=0之后，将28/2=14的结果也保存下来，这样就不用在判断是否可以被14整除了。
         for(int i = 2; i < num / i; i++) 当i=2时，i<28/2=14，这样就排除了14
         以这种方式每次将区间的范围缩小为 i~num/i,时间O(logn)
        */
        if(num % 2 != 0) return false;
        
        int tmp = 1;
        for(int i = 2; i < num / i; i++){
            if(num % i == 0){
                tmp += i + num / i;
            }
        }
        
        return tmp == num;
    }
}
```
我不要你觉得，我要我觉得：这代码真的短🐶