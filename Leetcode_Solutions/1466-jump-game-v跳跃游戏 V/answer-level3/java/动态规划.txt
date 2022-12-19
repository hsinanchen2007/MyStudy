思路：用数组dp[]记录每个位置所能跳的次数，dp[i]的值等于区间[i-d,i+d]中的可跳区域[beg,end](beg>=i-d,end<=i+d)中的最大值再加一dp[i] = dp[index]+1,beg<=index<=end;

将原来的数组里的值从小到大不重复排序（使用优先队列和hashmap），在hashmap中记录数组里数字的下标
HashMap<Integer, LinkedList<Integer>>

依次遍历优先队列中的元素的下标index，用区间[beg,end]记录[index-d,index+d]之间的可跳区间，区间[beg,end]满足数组arr在这个区间中使任何一个值都小于arr[index](下标为index除外)，当beg=end时，dp[index]=1，此时index两侧的数都大于该数

```
class Solution {
    static int ans = 0;
    public int maxJumps(int[] arr, int d) {
        ans = 0;
         int length = arr.length;
        int count = 0;
        int[] dp = new int[length];
        PriorityQueue<Integer> p = new PriorityQueue<Integer>();
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<Integer, LinkedList<Integer>>();
        for(int i = 0;i < length;i++) {
        	if(!map.containsKey(arr[i])) {
        		p.add(arr[i]);
        		count++;
        	}
        	LinkedList<Integer> list = map.getOrDefault(arr[i], new LinkedList<Integer>());
        	list.add(i);
        	map.put(arr[i],list);
        }
        for(int i = 0;i < count;i++) {
        	
        	int num = p.poll();
        	LinkedList<Integer> list = map.get(num);
        	list.forEach(index->{ 
        		                                          //num是当前值，index是当前值的位置
        		int max1 = 0,beg = index-d,end = index+d;
        		boolean flag = false;
        		for(int j = index-1;j >= index-d;j--) {
        			if(j >= 0 && arr[j] >= arr[index]) {
        				beg = j+1;
        				break;
        			}
        		}
        		if(beg < 0) beg = 0;
        		for(int j = index+1;j <= index+d;j++) {
        			if(j < length && arr[j] >= arr[index]) {
        				end = j-1;
        				break;
        			}
        			if(j == length-1) end = j;
        		}
        		if(end >= length)end = length-1;
        		for(int j = beg;j <= end;j++) {
        			if(beg == end) {
            			dp[index] = 1;
            			flag = true;
            			break;
            		}
        			if(max1 < dp[j]) {
        				max1 = dp[j];
        			}
        		}
        		if(!flag) {
        			dp[index] = max1+1;
        		}
        		if(dp[index] > ans) ans = dp[index];
        	});
        }
        return ans;
    }
}
```
