1.优先队列
```
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int size = nums.size();
        PriorityQueue<Node> queue = new PriorityQueue<>(new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return nums.get(a.i).get(a.j) - nums.get(b.i).get(b.j);
            }
        });
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int gap = Integer.MAX_VALUE;
        for (int i = 0; i < size; i++) {
            queue.offer(new Node(i, 0));
            min = Math.min(min, nums.get(i).get(0));
            max = Math.max(max, nums.get(i).get(0));
        }
        int[] ret = new int[2];
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            min = nums.get(cur.i).get(cur.j);
            if (max - min < gap) {
                gap = max - min;
                ret[0] = min;
                ret[1] = max;
            }
            if (cur.j == nums.get(cur.i).size() - 1) {
                break;
            }
            max = Math.max(max, nums.get(cur.i).get(cur.j + 1));
            queue.offer(new Node(cur.i,cur.j + 1));
        }
        return ret;
    }

    class Node {
        int i;
        int j;
        Node(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
}
```
2.暴力（超时）
```
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        List<Integer> list = new ArrayList<>();
        for (List<Integer> item : nums) {
            for (int i : item) {
                list.add(i);
            }
        }
        Collections.sort(list);
        int[] ret = new int[2];
        ret[0] = list.get(0);
        ret[1] = list.get(list.size() - 1);
        for (int i : list) {
            int[] tmp = new int[2];
            tmp[0] = i;
            tmp[1] = i;
            boolean flag = true;
            for (List<Integer> item : nums) {
                int index = item.indexOf(i);
                if(index == -1) {
                    int k =  get(item, i);
                    if (k != -1) {
                        tmp[1] = Math.max(tmp[1], k);
                        continue;
                    }
                    flag = false;
                }
            }
            if (!flag) {
                continue;
            }

            if (ret[1] - ret[0] > tmp[1] - tmp[0] || (ret[1] - ret[0] == tmp[1] - tmp[0] && tmp[0] < ret[0])) {
                ret = tmp;
            }
        }

        return ret;
    }

    public int get(List<Integer> item, int i) {
        for (int k : item) {
            if (k > i) {
                return k;
            }
        }
        return -1;
    }
}
```

