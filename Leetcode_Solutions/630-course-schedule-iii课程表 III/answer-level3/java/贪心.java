```
class Solution {
    public int scheduleCourse(int[][] courses) {
        //根据课程结束时间升序排列
        Arrays.sort(courses,(a,b) -> (a[1]-b[1]));
        //课程用时的大根优先级队列
        Queue<Integer> queue = new PriorityQueue<>((a,b) -> (b-a));
        int times = 0;
        for (int i=0;i<courses.length;i++){
            //如果此课程可以学习，则学习，总用时增加，此课程用时入堆
            if (times+courses[i][0]<=courses[i][1]){
                times += courses[i][0];
                queue.add(courses[i][0]);
            //如果不能学习此课程，因为此课程结束时间比之前所有的都晚，存在两种情况：
            //1.此课程用时比之前某个课程少：则学习此课程，放弃之前用时最长的课程
            //2.此课程用时比之前所有课程多：则不学习此课程，可以理解为学习此课程，同时放弃之前用时最长的课程（此课程）
            //则此种情况，学习此课程并放弃之前用时最长的课程（总用时减去大根堆堆顶）
            }else{
                queue.add(courses[i][0]);
                times = times + courses[i][0] - queue.poll();
            }
        }
        return queue.size();
    }
}
```
