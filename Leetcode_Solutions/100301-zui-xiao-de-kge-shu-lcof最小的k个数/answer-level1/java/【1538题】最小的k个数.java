**方法一：数组排序**
```
class Solution {
    /**
    * 思路：
    * 对数组排序后前k个数就是数组中最小的k个数。
    * (1) 对数组进行排序；
    * (2) 截取数组前k个数。
    */
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }else if(k >= arr.length){
            return arr;
		}
        Arrays.sort(arr);
        return Arrays.copyOf(arr,k);
    }
}
```

**方法二：快速排序思路**
```
class Solution {
    /**
    * 思路：
    * 根据快速排序思想，选定一个基准点数找出它最终排序后的位置，
    *   并且小于它的数都在左边，其余数都在它的右边。
    * (1) 查找原数组第一位数在排序后的位置，
    *   如果小于k-1则递归往后找，反之往前找，直到找到k-1位置的数；
    * (2) 截取k-1位置及之前的数。
    */
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }else if(k >= arr.length){
            return arr;
		}
        // 最后一个参数表示我们要找的是下标为k-1的数
        return quickSearch(arr, 0, arr.length - 1, k - 1);
    }

    private int[] quickSearch(int[] arr, int low, int high, int target) {
        // 每快排切分1次，找到排序后下标为p的元素，如果p恰好等于target就返回p以及p左边所有的数。
        int p = getPosition(arr, low, high);
        if (p == target) {
            return Arrays.copyOf(arr, p + 1);
        }
        // 否则根据下标p与target的大小关系来决定继续切分p左段还是p右段。
        return p > target ? quickSearch(arr, low, p - 1, target) : quickSearch(arr, p + 1, high, target);
    }

    // 快排切分，返回下标j，使得比nums[low]小的数都在j的左边，比nums[low]大的数都在j的右边。
    private int getPosition(int[] arr, int low, int high) {
        int temp = arr[low];
		while(low < high){
			while(low < high && arr[high] >= temp){
				high--;
			}
			arr[low] = arr[high];
			while(low < high && arr[low] <= temp){
				low++;
			}
			arr[high] = arr[low];
		}
        arr[low] = temp;
        return low;
    }
}
```

**方法三：堆排序思路**
```
class Solution {
    /**
    * 思路：
    * 保持堆的大小为K，然后遍历数组中的数字，遍历的时候做如下判断：
    * (1) 若目前堆的大小小于K，将当前数字放入堆中；
    * (2) 否则判断当前数字与大根堆堆顶元素的大小关系，
    *   如果当前数字比大根堆堆顶还大，这个数就直接跳过，
    *   反之如果当前数字比大根堆堆顶小，先poll掉堆顶，再将该数字放入堆中。
    */
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        // 默认是小根堆，实现大根堆需要重写一下比较器。
        Queue<Integer> pq = new PriorityQueue<>((v1, v2) -> v2 - v1);
        for (int num: arr) {
            if (pq.size() < k) {
                pq.offer(num);
            } else if (num < pq.peek()) {
                pq.poll();
                pq.offer(num);
            }
        }
        
        // 返回堆中的元素
        int[] res = new int[pq.size()];
        int idx = 0;
        for(int num: pq) {
            res[idx++] = num;
        }
        return res;
    }
}
```


**方法四：二叉搜索树**
```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k >= arr.length) {
            return arr;
        }
        // TreeMap的key是数字, value是该数字的个数。
        // cnt表示当前map总共存了多少个数字。
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int cnt = 0;
        for (int num: arr) {
            // 1. 遍历数组，若当前map中的数字个数小于k，则map中当前数字对应个数+1
            if (cnt < k) {
                map.put(num, map.getOrDefault(num, 0) + 1);
                cnt++;
                continue;
            } 
            // 2. 否则，取出map中最大的Key（即最大的数字), 判断当前数字与map中最大数字的大小关系：
            //    若当前数字比map中最大的数字还大，就直接忽略；
            //    若当前数字比map中最大的数字小，则将当前数字加入map中，并将map中的最大数字的个数-1。
            Map.Entry<Integer, Integer> entry = map.lastEntry();
            if (entry.getKey() > num) {
                map.put(num, map.getOrDefault(num, 0) + 1);
                if (entry.getValue() == 1) {
                    map.pollLastEntry();
                } else {
                    map.put(entry.getKey(), entry.getValue() - 1);
                }
            }
            
        }

        // 最后返回map中的元素
        int[] res = new int[k];
        int idx = 0;
        for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
            int freq = entry.getValue();
            while (freq-- > 0) {
                res[idx++] = entry.getKey();
            }
        }
        return res;
    }
}
```
