### 解题思路
1、首先分析题意
        对于任意一组任务，假设我们获得了每个任务及任务的出现次数
        假设任务为A,B,C,D
       每个任务出现的次数分别为3,2,1,1
        如果n=2
        那么我们可以推测出A  B C A B  D A 这样一组执行方式是最优的。即把重复数最多的任务优先排列。
        由于任务的运行时间都为单位时间，那么我们可以只存取每个任务出现的次数即可，每排列一次，次数减一

2、保存任务出现的次数（按照从大到小的方式保存)
         可以用PriorityQueue  注意java的优先级队列，默认是最小堆，所以我们需要指定排序为倒序。
          PriorityQueue<Integer>  queue = new PriorityQueue<Integer>(Collections.reverseOrder())

3、接下来我们对queue进行循环，这里用一个中间列表来保存重复次数>1的任务

       int time=0;
       while(!queue.isEmpty()){
               int i = 0;
               List<Integer> temp = new ArrayList<Integer>();
               //两个相同的任务之间必须间隔n个单位长度，也就是说一次可以安排n+1个任务作为一组
               while(i<=n){
                    if(!queue.isEmpty()){
                              if(queue.peek()>1){
                                    temp.add(queue.poll()-1);
                              }else{
                                   queue.poll();
                            }
                    }
                    //安排了一个任务
                    time++;
                     if(queue.isEmpty()&&temp.isEmpty()){
                             break;
                      }
                      i++;
               }
               //将次数大于1的任务重新加入到队列中
               for(Integer value:temp){
                          queue.add(value);
               }
       }
       return time;
       

### 代码

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
       int[] map = new int[26];
        for(char task:tasks){
            map[task-'A']++;
        }
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        for(int value:map){
            if(value>0){
                queue.add(value);
            }
        }
        int time = 0;
        while(!queue.isEmpty()){
            int i = 0;
            List<Integer> temp = new ArrayList<>();
            while(i<=n){
                 if(!queue.isEmpty()){
                    if(queue.peek()>1){
                        temp.add(queue.poll()-1);
                    }else{
                        queue.poll();
                    }
                }
                time++;
                if(queue.isEmpty()&&temp.isEmpty()){
                    break;
                }
                i++;
            }
            for(Integer value:temp){
                queue.add(value);
            }
        }
        return time;
    }
}
```