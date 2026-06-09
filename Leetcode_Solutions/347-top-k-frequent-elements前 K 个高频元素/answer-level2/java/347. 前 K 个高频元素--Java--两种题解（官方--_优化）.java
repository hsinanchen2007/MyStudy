[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_347_topKFrequent.java)

```java
    /**
     * 解题思路：
     * 1.遍历count使用HashMap进行保存
     * 2.从遍历的count中找到最K大的数字，此时使用了PriorityQueue进行保存，队列顶部就是最小的
     * 3.将PriorityQueue结果转换为List返回
     *
     * 执行用时 :104 ms, 在所有 Java 提交中击败了16.20%的用户
     * 内存消耗 :45.8 MB, 在所有 Java 提交中击败了57.61%的用户
     *
     * 时间复杂度O(NLogN)
     *
     * 更优解法：{@link _347_topKFrequent#topKFrequent1(int[], int)}
     *
     * @param nums
     * @param k
     * @return
     */
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        PriorityQueue<Integer> heap = new PriorityQueue<Integer>((n1, n2) -> map.get(n1) - map.get(n2));
        for (int n : map.keySet()) {
            heap.add(n);
            if (heap.size() > k)
                heap.poll();
        }
        List<Integer> retList = new LinkedList();
        while (!heap.isEmpty())
            retList.add(heap.poll());
        Collections.reverse(retList);
        return retList;
    }


    /**
     * 更优解法，优化了建堆和排序的消耗
     *
     * 执行用时 :28 ms, 在所有 Java 提交中击败了89.78%的用户
     * 内存消耗 :46.8 MB, 在所有 Java 提交中击败了41.99%的用户
     *
     * 时间复杂度O(N)
     *
     * @param nums
     * @param k
     * @return
     */
    public List<Integer> topKFrequent1(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        List<Integer>[] count = new ArrayList[nums.length + 1];
        for (int key : map.keySet()) {
            int freq = map.get(key);
            if (count[freq] == null) {
                count[freq] = new ArrayList<>();
            }
            count[freq].add(key);
        }

        List<Integer> result = new ArrayList<>(k);
        int remain = k;

        for (int i = nums.length; i > 0 && remain > 0; i--) {
            if (count[i] != null) {
                if (remain > count[i].size()) {
                    result.addAll(count[i]);
                    remain -= count[i].size();
                } else {
                    result.addAll(count[i].subList(0, remain));
                    remain = 0;
                }
            }
        }

        return result;
    }
```