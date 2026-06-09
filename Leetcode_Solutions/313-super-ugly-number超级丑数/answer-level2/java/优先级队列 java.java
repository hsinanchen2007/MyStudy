### 解题思路
### 代码

```java
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {//优先队列
        Queue<Long> q = new PriorityQueue<>();
        long result=1;
        q.add(result);
        int count = 0;
        
        while(!q.isEmpty()&&count<n)
        {
            result=q.poll();
            while(!q.isEmpty()&&q.peek()==result)//有重复元素，先出队
            {
                q.poll();
            }
            for(int j=0;j<primes.length;j++)//将所有结果入队列
            {
                q.add(result*primes[j]);
            }
            count++;
        }
        return (int)result;
    }
}
```