![捕获leetcode347.JPG](https://pic.leetcode-cn.com/571eb15bc22f38ff1430a92f7c28a9503a0e016a0ce77f8d362d3708a8e88e3e-%E6%8D%95%E8%8E%B7leetcode347.JPG)


首先：将int数组排序，然后遍历一次计算数量后，插入堆中排序，排序是根据数字出现的频率来对比。最后返回前K个即可。
```
public class T347_TopKFrequent {

    class Node {
        int val;
        int cnt;

        Node(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }
    }

    public List<Integer> topKFrequent(int[] nums, int k) {
        PriorityQueue<Node> heap = new PriorityQueue<>(nums.length, (x, y) -> y.cnt - x.cnt);
        Arrays.sort(nums);

        Node tmp = null;
        for (int n: nums) {
            if (null == tmp) {
                tmp = new Node(n, 1);
            }else if (tmp.val == n) {
                tmp.cnt = tmp.cnt + 1;
            }else {
                heap.add(tmp);
                tmp = new Node(n, 1);
            }
        }
        heap.add(tmp);

        List<Integer> ret = new ArrayList<>(k);
        for(int i=0; i<k; ++i) {
           Node t = heap.poll();
           ret.add(t.val);
        }
        return ret;
    }

    public static void main(String args[]) {
        T347_TopKFrequent t = new T347_TopKFrequent();

        System.out.println(t.topKFrequent(new int[]{1,1,1,2,2,3}, 2));

        System.out.println(t.topKFrequent(new int[]{1}, 1));

    }

}
```
