### 解题思路
使用hashset去重
使用优先队列排序，拿出子元素
时间复杂度是O(nlogn):优先队列插入的复杂度
2
3
5
2 * 2 =4
2 * 3 =6
2 * 5 =10
此时队列里是3，4，5，6，10
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        if(n == 0){
            return 0;
        }
        Queue<Long> Q = new PriorityQueue<Long>();
        HashSet<Long> inQ = new HashSet<Long>();
        Long[] primes = new Long[3];
        primes[0] = Long.valueOf(2);
        primes[1] = Long.valueOf(3);
        primes[2] = Long.valueOf(5);
        for(int i = 0; i < 3; i++){
            Q.add(primes[i]);
            inQ.add(primes[i]);
        }
        
        Long number = Long.valueOf(1);
        for(int i = 1; i < n; i++){
            number = Q.poll();
            for(int j = 0; j < 3; j++){
                //hashset里面已经有的不要放入优先队列里面
                if(!inQ.contains(primes[j] * number)){
                    Q.add(number * primes[j]);
                    inQ.add(number * primes[j]);
                }
            }
        }
        return number.intValue();
    }
}
```