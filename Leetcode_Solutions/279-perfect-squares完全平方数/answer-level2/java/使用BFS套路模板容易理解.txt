和BFS很像，往队列加入n-i*i
比如最接近12的平方数有9,4,1,因而将3,8,11加入队列看成是12的子节点，继续遍历
发现中间有重复，需要剪枝比如上面的11已经大于9，说明继续分解11的话又遇到9所以1没必要加入到队列中
```
class Solution {
    public int numSquares(int n) {
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        int steps = 0;
        while(!q.isEmpty()){
            steps++;
            for(int i=q.size();i>0;i--){
                int num = q.poll();
                
                List<Integer> squares = getSquares(num);
                for(int i1:  squares){
                    if(num-i1==0) return steps;
                    q.offer(num-i1);
                }
            }

        }
        return  0;
    }
//用来求解 平方和树 小于 num 的集合
//需要剪枝
    private List<Integer> getSquares(int num){
        List<Integer> res = new LinkedList<>();
        int count = (int)Math.sqrt(num);
        int base = count*count;
        res.add(base);
        for(int i=count-1; i>0; i--){
            int cur = i*i;
            if(num-cur < base)
                res.add(cur);
            else
                break;
        }
        return res;
    }
}
```
