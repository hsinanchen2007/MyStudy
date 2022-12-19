### 解题思路
利用最小堆来解决这道问题，最小堆最上方为最早结束的时间。如果当前要插入的会议的开始时间小于最上方的结束时间，那么代表要开辟新的房间；否则，更新最上方的会议室的结束时间即可。

最后返回栈的大小即为所用的房间总数。

### 代码

```java
class Solution {
    Stack<Integer> rooms; // available rooms, store end time
    
    // Initialization
    public void init(){
        rooms = new Stack();
    }

    // insert new meeting
    // case 1: at beginning, start a new room
    // case 2: if room available (end_time of the stack's top is less than start_time)
    // case 3: if no room available (end_time of the stack's top is more than start_time)
    public void newMeeting(int start_time, int end_time){
        if (rooms.isEmpty()){
            insert(end_time);
        } else if (rooms.peek() <= start_time){ // room available
            update(end_time);
        } else { // need new room
            insert(end_time);
        }
    }

    // insert end_time into appropriate place
    public void insert(int end_time){
        Stack<Integer> temp = new Stack();
        while(!rooms.isEmpty() && rooms.peek() < end_time){
            temp.add(rooms.pop());
        }
        rooms.push(end_time);
        while(!temp.isEmpty()){
            rooms.push(temp.pop());
        }
    }

    // update the top room 
    public void update(int end_time){
        rooms.pop();
        insert(end_time);
    }

    public int minMeetingRooms(int[][] intervals) {
        init();
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0] - b[0];
            }
        });
        for (int i = 0; i < intervals.length; i++){
            newMeeting(intervals[i][0], intervals[i][1]);
        }
        return rooms.size();
    }

}
```