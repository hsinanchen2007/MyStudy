给定一个数组 *nums*，有一个大小为 *k* 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口 *k* 内的数字。滑动窗口每次只向右移动一位。

返回滑动窗口最大值。

**示例:**

```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**注意：**

你可以假设 *k* 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。

**进阶：**

你能在线性时间复杂度内解决此题吗？

```java
//time:o(n)
//space:o(k)
//https://www.youtube.com/watch?v=2SXqBsTR6a8
//jianzhi offer 书上，291，59题
class MyQueue{
Deque<Integer> data = new ArrayDeque<>();
//push an element on the queue
//will pop all elements smaller than e
public void offer(Integer e){
		while(!data.isEmpty()&&data.peekLast()<e){
			data.pollLast();
		}
		data.offerLast(e);
	}
//pop the max element
public void poll(){
		data.pollFirst();
	}
//get the max element
public Integer max(){
		return data.peekFirst();
	}
};
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0){
            return new int[0];
        }
        MyQueue q = new MyQueue();
        int[] res = new int[nums.length-k+1];        
        for(int i=0; i<nums.length; i++){
            //把元素放入dequeue中
            q.offer(nums[i]);
            //滑窗的左边界下标为 i-k+1，右边界下标为i
            if(i-k+1>=0){
                //i-k+1也就是每个滑窗的下标，它的值为dequeue的最大值，也就是队列的顶端
                res[i-k+1] = q.max();
                //如果滑动窗口的最大值在窗口的最左边，那么下次滑动的时候，左边的值需要弹出去
                if(nums[i-k+1] == q.max()){
                    q.poll();
                }
            }
        }
        return res;
    }
}
```

```c++
//time:o(n)
//space:o(k)
//https://www.youtube.com/watch?v=2SXqBsTR6a8
//***，291，59题
class MyQueue{
public:
  //push an element on the queue
  //will pop all elements smaller than e
	void push(int e){
		while(!data.empty()&&data.back()<e){
			data.pop_back();
		}
		data.push_back(e);
	}
  //pop the max element
	void pop(){
		data.pop_front();
	}
  //get the max element
	int max(){
		return data.front();
	}
private:
	deque<int> data;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
        	q.push(nums[i]);
        	if(i-k+1>=0){
        		res.push_back(q.max());
                //for example: 4 2 1 3 ,window size =3 
        		if(nums[i-k+1]==q.max()){
        			q.pop();
        		}
        	}
        }
        return res;
    }
};
```


