```
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses,(int []a,int []b)->{
            if(a[1]==b[1]){
                return a[0]-b[0];
            }
            return a[1]-b[1];
        });
        int cur =0;
        PriorityQueue<Integer> Q = new PriorityQueue<>((a,b)->b-a);
        for(int [] c:courses){
            if(cur+c[0]<=c[1]){//当前所用时间+课程的需要时间<=课程结束时间
                cur+=c[0];
                Q.add(c[0]);//将课程需要时间放入大顶堆

            }else if(!Q.isEmpty() && Q.peek()>c[0]){//队列中【最大的课程时间】比当前课程的时间大
                cur+=c[0]-Q.remove();//可以将最大课程时间取出，腾出【最大课程时间-当前课程时间】的空白时间给学生
                Q.add(c[0]);//c[0]-Q.remove()是一个负数
            }
        }
        return Q.size();

    }
}
```