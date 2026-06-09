### 解题思路
史上最垃圾代码。还不如我网速击败的人多。
就两个队列实现，一个队列保留当前的，另一个队列保留上一次的


### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n == 1)return("1");
        if(n == 2)return("11");
        Queue<Integer> queue = new LinkedList<>();
        int i;
        queue.offer(1);
        queue.offer(1);
 
        int tmp;
        int times=0,tmp_last;

        for(i=0;i<n-2;i++){
            //System.out.print(i);
            tmp_last = 11;
            Queue<Integer> queue_next = new LinkedList<>();
            while(true){
                if(queue.peek() == null)break;
                tmp = queue.poll();
                if(tmp == tmp_last)times+=1;
                else if(tmp_last != 11){
                    queue_next.offer(times);
                    queue_next.offer(tmp_last);
                    tmp_last = tmp;
                    times = 1;
                }
                else{
                    tmp_last = tmp;
                    times = 1;
                }
            }
            queue_next.offer(times);
            queue_next.offer(tmp_last);
            times = 1;
            queue = queue_next;

        }
        String ans = "";
        for(int q : queue){
            ans+=String.valueOf(q);
            //System.out.print(q);
        }
        return ans;
    }
}
```