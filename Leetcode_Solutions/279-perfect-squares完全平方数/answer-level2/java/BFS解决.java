```
class Solution {
    public int numSquares(int n) {
        // 用于存放组成n的，平方数
        Queue<Integer> queue = new LinkedList<>();
        queue.add(n);
        // 用于判断那些平方数已经放入队列
        boolean record[] = new boolean[n];
        int step = 0;
        while(!queue.isEmpty()){         
            int size = queue.size();
            step++;
            while(size-- > 0){
                int val = queue.poll();

                for(int i=1; val-i*i>=0; i++){
                    int nextVal = val - i * i;
                    // 组成数值都已经分为子数
                    if(nextVal == 0)
                        return step;
                    // 假如当前组成平方数的数字已经存放到record中， 当前组成数字一定大于之前的那种情况
                    if(!record[nextVal]){
                        queue.add(nextVal);
                        record[nextVal] = true;
                    }
                }
            }
        }
        return -1;
    }
}
```
