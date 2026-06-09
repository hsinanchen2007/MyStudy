```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        //queue存储用作判断是否符合条件，set存储用于去重
        //六种操作，装满A,倒空A，装满B,倒空B，A-->B(B满A余,B未满A空),B-->A(A满B余,A未满B空)
        if(x==z||y==z||x+y==z) return true;
        if(x+y<z) return false;

        Queue<List<Integer>> queue = new LinkedList<>();
        Set<List<Integer>> set = new HashSet<>();
        List<Integer> list = Arrays.asList(0,0);
        queue.offer(list);
        set.add(list);

        while(!queue.isEmpty()){
            List<Integer> poll = queue.poll();
            int cur_x = poll.get(0);
            int cur_y = poll.get(1);
            if(cur_x==z||cur_y==z||cur_x+cur_y==z) return true;

            //装满A
            List<Integer> fillA = Arrays.asList(x,cur_y);
            if(!set.contains(fillA)){
                set.add(fillA);
                queue.offer(fillA);
            }

            //倒空A
            List<Integer> pullA = Arrays.asList(0,cur_y);
            if(!set.contains(pullA)){
                set.add(pullA);
                queue.offer(pullA);
            }

            //装满B
            List<Integer> fillB = Arrays.asList(cur_x,y);
            if(!set.contains(fillB)){
                set.add(fillB);
                queue.offer(fillB);
            }
            //倒空B
            List<Integer> pullB = Arrays.asList(cur_x,0);
            if(!set.contains(pullB)){
                set.add(pullB);
                queue.offer(pullB);
            }
            //A-->B
            List<Integer> A_B = Arrays.asList(cur_x-Math.min(cur_x,y-cur_y),cur_y+Math.min(cur_x,y-cur_y));
            if(!set.contains(A_B)){
                set.add(A_B);
                queue.offer(A_B);
            }

            //B-->A
            List<Integer> B_A = Arrays.asList(cur_x+Math.min(x-cur_x,cur_y),cur_y-Math.min(x-cur_x,cur_y));
            if(!set.contains(B_A)){
                set.add(B_A);
                queue.offer(B_A);
            }
            
        }
        return false;
    }
}
```
