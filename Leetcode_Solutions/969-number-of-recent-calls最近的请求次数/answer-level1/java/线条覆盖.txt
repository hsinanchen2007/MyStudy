### 解题思路
1. 创建一个长度3001的数组(照顾一下边界情况 例如 : 1~3000有3001个数)
2. 将新ping的数看作一条数字为1的新线段
3. 得到当前ping与上一个ping的差值
4. 将差值的后一个位置开始覆盖,即+1。剩下的补1
5. 第一个位置覆盖的值就代表了这3000ms内的ping数量

### 代码

```java
class RecentCounter {
    //使用队列解题
    // 使用3000长度的线条覆盖的思路?  队列已经是最优题解了
    static LinkedList<Integer> queue = new LinkedList<Integer>();
    int pre;
    int[] data;
    public RecentCounter() {
        queue.clear();

        this.pre = -3000;
        this.data = new int[3001];
    }
    
    public int ping(int t) {
        // queue.offer(t);
        // remove(t - 3000);
        // return queue.size();
        int dist = t - pre ;
        pre = t;
        if(dist> 3000){
            Arrays.fill(data,1);
            return 1;
        }
        for(int i=0;i<3001 - dist;i++){
            data[i] = data[i + dist] + 1;
        }
        for(int i=3001-dist;i<3001;i++){
            data[i] = 1;
        }
        return data[0];

    }

    private void remove(int lower){
        while(queue.peek() < lower){
            queue.poll();
        }
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
```