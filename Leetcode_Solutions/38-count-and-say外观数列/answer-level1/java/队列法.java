用队列的方式，压第一个元素，然后进行取出对比，进行尾插法，最后有2种情况 一种是 最后一个元素和前一个一样，一种是 最后元素与前一个不同，只需要重新尾插一次，更新count
```
import java.util.LinkedList;
class Solution {
    public String countAndSay(int n) {
         if (n==1){
            return "1";
        }
        LinkedList<Integer> queue = new LinkedList<>();
        // 计数
        int count = 0;
        // 标记
        int temp;
        queue.addLast(1);
        for (int i = 0; i < n-1; i++) {
            temp = queue.getFirst();
            int len = queue.size();
            for (int j = 0; j < len; j++) {
                // 取出一个元素
                Integer poll = queue.poll();
                if (poll != temp){
                    queue.addLast(count);
                    queue.addLast(temp);
                    temp = poll;
                    // 因为已经取了一个,count自动加1
                    count=1;
                }else{
                    count++;
                }
            }
            queue.addLast(count);
            queue.addLast(temp);
            count=0;
        }

        StringBuilder sb = new StringBuilder();
        for (Integer integer:
             queue) {
            sb.append(integer);
        }

        return sb.toString();
    }
}
```
