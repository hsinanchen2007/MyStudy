### 总结第k小和第k大
可与题目703对比。
题目703求的是第k大，本题求的是前k小，其实思路的本质是一样的，使用优先队列。
703的题解已经手撕过小顶堆，本题就直接使用PriorityQueue。
除此之外，还需要弄清楚本题与703的一个区别：
703求的是第k大，相当于在一个小顶堆里维护前k大的数，堆顶就是前k大里的最小元素，即第k大。因此不管数据流有多大，只需要更新堆顶元素即可，如果有更大的，就把前k大里最小的换掉，重新组成前k大的元素，并在堆顶放置第k大。
本题需要最小的k个数，相当于在一个大顶堆里维护前k小的数，堆顶就是前k小里最大的，即第k小。通过更换堆顶（如果有更小的），就可以让堆中存储的元素总是为前k小的，若有更小的，则把最大的堆顶元素换掉即可。

总结：
第k大，即前k大里最小的，使用小顶堆。
第k小，即前k小里最大的，使用大顶堆。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if(k == 0)  return new int[0];
        PriorityQueue<Integer> maxpq = new PriorityQueue<Integer>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        for(int i = 0; i < k; i++)
            maxpq.offer(arr[i]);
        for(int i = k; i < arr.length; i++)
        {
            if(arr[i] < maxpq.peek())
            {
                maxpq.poll();
                maxpq.offer(arr[i]);
            }
        }   
        int[] ans = new int[k];
        int cnt = 0;
        for(int n : maxpq.toArray(new Integer[k]))
            ans[cnt++] = n;
        return ans;
    }
}
```