```
class Solution {
    class Pair{
        int index;
        int v;
        public Pair(int i, int vv){
            index = i;
            v = vv;
        }
    }
    class SlidingWindow{
        PriorityQueue<Pair> q;
        HashSet<Integer> removedIndex;

        SlidingWindow(){
            q = new PriorityQueue<Pair>((p1, p2) -> p2.v - p1.v);
            removedIndex = new HashSet<>();
        }
        void add(int index, int v){
            q.add(new Pair(index, v));
        }
        void reomve(int index, int v){
            removedIndex.add(index);
            while (removedIndex.contains(q.peek().index)){
                q.poll();
            }
        }
        int getMax(){
            return q.peek().v;
        }
    }
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(k == 1 || nums.length == 0)
            return Arrays.copyOf(nums, nums.length);

        int[] result = new int[nums.length - k + 1];
        SlidingWindow sw2 = new SlidingWindow();
        for (int i = 0; i < k; i++) {
            sw2.add(i, nums[i]);
        }

        int left = 0, right=k;
        int resp = 0;
        while(right < nums.length){
            result[resp++] = sw2.getMax();
            sw2.reomve(left, nums[left]);
            left ++;
            sw2.add(right, nums[right]);
            right ++;
        }
        result[resp] = sw2.getMax();

        return result;
    }
}
```
SlidingWindow维护一个堆（优先队列太长了就写堆吧）q，堆顶是最大值，为了让堆顶最大值是没有被删除过的，SlidingWindow会记录被删除过的元素，然后 while堆顶元素是被删除过的元素：把该元素移出堆。
