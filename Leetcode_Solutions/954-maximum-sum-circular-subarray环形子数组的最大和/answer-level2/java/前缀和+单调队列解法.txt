首先需要有非环形数组求最大和的基础。这个不详细说了。
1.针对环形数组，如果采用边界判断+取模运算会相对而言复杂一些，这里采用扩容方法，将数组A进行扩容复制。构造出前缀和数组sum。
2.环形子数组的最大和即剔除数组中的负数部分（该题目可以扩展为求子序列的最大和）对于以 i结尾的子数组，可以通过sum[i]-min(sum[j]) i-n<=j<i得到。
3.上述过程可以通过单调队列得到。维护一个单调递增队列(这里的单调递增是针对前缀和而言的单调递增)，队头对应的元素最小。每次循环时，首选将不满足条件的队头出队。（队列大小必须维护在len之内）
4.入队时，检查当前队尾元素与sum[i]的关系，如果sum[i]小于等于当前队尾元素前缀和，则将当前队尾出队，将i入队。
```Java
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        //个人思路：先拼接构造成环形数组所有元素,再利用前缀和+单调队列实现具体操作
        if(A==null||A.length==0){
            return 0;
        }
        Deque<Integer>q=new LinkedList<>();
        int len=A.length;
        int ans=A[0];
        int newa[]=new int[2*len+1];
        for(int i=1;i<=2*len;i++){
            newa[i]=0;
        }
        for(int i=1;i<=2*len;i++){//求出前缀和
            if(i<=len){
                newa[i]=newa[i-1]+A[i-1];
            }else{
                newa[i]=newa[i-1]+A[i-1-len];
            }
        }
        q.offer(0);
        for(int i=1;i<=2*len;i++){
            while(!q.isEmpty()&&q.peek()<i-len){//维持队列大小
                q.pollFirst();
            }
            ans=Math.max(ans,newa[i]-newa[q.peek()]);//总和减去最小和
            while(!q.isEmpty()&&newa[q.peekLast()]>=newa[i]){
                q.pollLast();
            }
            q.offer(i);
        }
        return ans;
    }
}
```
