这道题的意思是，k个数组，找到一个最小的区间，使得每个数组最少有一个数落在区间内。
最直观的思路当然是暴力法，遍历所有数组，每一个数组都取一个数，然后找到这k个数的最大值和最小值，从而构成一个区间，最后找到最小的那个区间即可。注意到题目有个很重要的线索，那就是k个数组都是升序的。
我们知道，一个区间如果想要缩小，要么提高下限，要么是降低上限。而我们遍历的时候是从左往右遍历的，也就是区间的上限一直都是提高的，所以要找到最小的区间，在遍历的时候就要先遍历区间下限所在的数组，也就是不断提高下限，这样才能保证区间一直都是缩小的。最后当下限已经到数组尽头了，说明下限已经是该数组最大的数了，此时就可以停止遍历了。
在遍历过程中，当前区间的下限是一直变化的，如果我们每次都需要遍历k个数字，找到当前的下限，那么时间复杂度是 O(k)。因此我们用一个优先队列来保存当前遍历的k个数，队头就是最小值，也就是当前区间的下限，优先队列的插入时间复杂度是 O(logk)，获取队头的复杂度是O(1)，因此我们最终的时间复杂度是 O(Mlogk+k)，M是最长数组长度
```
public int[] smallestRange(List<List<Integer>> nums) {
        if(nums == null || nums.size() == 0)
            return null;
        int len = nums.size();
        PriorityQueue<Pair> queue = new PriorityQueue<>(Comparator.comparingInt(p -> p.num));
        int[] res = new int[2];
        res[1] = Integer.MAX_VALUE;
        //maxNum 记录每一次遍历中k个数组的最大值
        int maxNum = Integer.MIN_VALUE;
        //初始化优先队列，将k个数组的第一个数字入队
        for(int i = 0;i<len;i++){
            int num = nums.get(i).get(0);
            maxNum = Math.max(maxNum,num);
            queue.add(new Pair(i,0,num));
        }
        //这里的循环退出条件是队列为空，也可以写成双层循环遍历数组
        while(!queue.isEmpty()){
            //每次遍历，先从队列中取出当前最小值
            Pair pair = queue.poll();
            int num = pair.num;
            //如果（当前最小值，当前最大值）的区间范围更小，则修改res数组
            if(res[1] - res[0] > maxNum - num){
                res[0] = num;
                res[1] = maxNum;
            }
            int row = pair.row;
            //右移
            int col = pair.col + 1;
            //如果右移后超出数组长度，此时退出循环，即已经找到最小的区间了
            if(nums.get(row).size() == col){
                break;
            }
            //下一个数，是当前数右边的数
            int nextNum = nums.get(row).get(col);
            //下一个数继续入队列
            queue.add(new Pair(row,col,nextNum));
            //更新当前最大值
            maxNum = Math.max(maxNum,nextNum);
        }
        return res;
    }
    //定义一个类，用来记录遍历过程中，每个数字所在的行、列和数字对应的值
    class Pair{
        public Integer row;
        public Integer col;
        public Integer num;
        public Pair(Integer row,Integer col,Integer num){
            this.row = row;
            this.col = col;
            this.num = num;
        }
    }
```
