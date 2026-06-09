## Solution
###  将开始结束时间拆开来看
- 本题可以看成车上同时最多有多少个乘客
- 每次上车(cur++)都看下是否有乘客已经下车了,下车几个,(cur减几个)
```java
​class Solution {
    public int minMeetingRooms(int[][] intervals) {
    	if(intervals==null||intervals.length==0) return 0;
    	int[]begin=new int[intervals.length];
    	int[]end=new int[intervals.length];
    	for(int i=0;i!=intervals.length;i++) {
    		begin[i]=intervals[i][0];
    		end[i]=intervals[i][1];
    	}
    	Arrays.sort(begin);
    	Arrays.sort(end);
    	int res=0;
    	// 看成上下车, 每次上车都看下是否有乘客已经下车了,下车几个
    	// 本题可以看成车上同时最多有多少个乘客
    	for(int i=0,j=0,cur=0;i!=intervals.length&&j!=intervals.length;) {
    		if(begin[i]<end[j]) { //还没有乘客下车
    			cur++;i++; 
    		}else { //已经有乘客下车了
    			while(begin[i]>=end[j]) {
    				j++;cur--;
    			}
    		}
    		res=Math.max(res,cur);
    	}
    	return res;
    }
}
```
### 优先级队列解法
```java
class Solution {
    public int minMeetingRooms(int[][] intervals) {
    	if(intervals==null||intervals.length==0) return 0;
        // 按结束时间排序
    	PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
        // 按开始时间排序
    	Arrays.sort(intervals,(i,j)->i[0]-j[0]);
    	queue.add(intervals[0][1]);
    	for(int i=1;i!=intervals.length;i++) {
    		int last=queue.peek();//最早结束的
    		if(last<=intervals[i][0]) { // 最早结束的可以腾出会议室
    			queue.poll();
    		    queue.add(intervals[i][1]); //修改该会议室的结束时间
            }else{ //最早结束的都来不及腾出会议室
                queue.add(intervals[i][1]);// 需要一个新的会议室
            }
    	}
    	return queue.size();
    }
}
```