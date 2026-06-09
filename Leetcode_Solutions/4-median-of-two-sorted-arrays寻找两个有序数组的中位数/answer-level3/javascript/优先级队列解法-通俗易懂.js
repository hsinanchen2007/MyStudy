看看题目的特殊性，两个数组都是有序的，相当于只要找出最中间的数就行，这里我们先创建一个大根堆和一个小根堆，先将所有数据都导入到大根堆里面，再将大根堆里面一半的数据导入到小根堆里面，那么两个堆的栈顶元素就是我们需要的元素，里面只需要判断总元素个数是偶数个还是奇数个就行。
```
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        PriorityQueue<Integer> maxqueue = new PriorityQueue<Integer>(new MaxComparator());
        PriorityQueue<Integer> minqueue = new PriorityQueue<Integer>(new MinComparator());

        //判断加不加
        boolean flag;
        int p1 = 0;
        int p2 = 0;

        while(p1 < nums1.length || p2 < nums2.length){
            flag = (p1 < nums1.length ) ? true: false;
            if(flag){
                maxqueue.add(nums1[p1++]);
            }
            flag = (p2 < nums2.length ) ? true:false;
            if(flag){
                maxqueue.add(nums2[p2++]);
            }
        }

        while((maxqueue.size() - minqueue.size()) > 1){
            minqueue.add(maxqueue.poll());
        }

        flag = (maxqueue.size() == minqueue.size()) ? true : false;

        return flag ? (maxqueue.poll() + minqueue.poll()) / 2.0 : maxqueue.poll();

    }

    public static class MaxComparator implements Comparator<Integer>{
        public int compare(Integer o1 , Integer o2){
            return o2 - o1;
        }
    }
    public static class MinComparator implements Comparator<Integer>{
        public int compare(Integer o1 , Integer o2){
            return o1 - o2;
        }
    }
    
}

```
