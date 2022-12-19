### 解题思路
### 找到target的平均数 然后将平均数和前一个数入队列，
### 若队列中首尾连加大于target 则出队
###                 小于target 则队尾前一个数进队
###				    等于target 则保存并且出队

### 代码

```java
    import java.util.List;
    import java.util.ArrayList;
    import java.util.Arrays;
    import java.util.Queue;
    import java.util.LinkedList;
class Solution {

    public static int sumFtoR(int front, int rear) {
		return (front+rear)*(front-rear+1)/2;
	}
	public static ArrayList<Integer> fillFtoR(int front, int rear){
		ArrayList<Integer> a = new ArrayList<>();
		for(int i = rear; i <= front;i++) {
			a.add(i);
		}
		return a;
	}
    public int[][] findContinuousSequence(int target) {
        ArrayList<List<Integer>> a = new ArrayList<>();
		Queue<Integer> queue = new LinkedList<Integer>();
		int middle = target/2 + 1;
		int front = middle;
		int rear = middle -1;
		queue.offer(front);
		queue.offer(rear);
		while(!queue.isEmpty() && rear > 0) {
			if(sumFtoR(front,rear) > target) {
				queue.poll();
				front = queue.peek();
				rear--;
				queue.offer(rear);
			}
			else if(sumFtoR(front,rear) < target) {
				rear--;
				queue.offer(rear);
			}
			else {
				a.add(fillFtoR(front,rear));
				queue.poll();
				front = queue.peek();
				rear--;
				queue.offer(rear);
			}
			
		}
		int row = a.size();
		int[][] result = new int[row][];
		for(int i =0; i <row;i++) {
			int nRow = row-1-i;
			int inLength = a.get(i).size();
			result[nRow] = new int[inLength];
			for(int j =0; j<inLength ;j++) {
				result[nRow][j] = a.get(i).get(j);
			}
		}
		System.out.println(result);
		return result;
    }
    
}
```