### 解题思路
执行用时 :15 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :40.6 MB, 在所有 Java 提交中击败了100.00%的用户

用两个变量max和size判断堆是否放满了。
如果堆未满，则新元素置入末尾，并自底向上堆化，每次与其父节点比较大小，比父节点小则相互交换，比父节点大则堆化结束。
如果堆满了，当前元素小于堆顶则返回堆顶元素；当前元素大于堆顶则将其赋值给堆顶元素，并自顶向下堆化，然后返回堆顶元素。
注意：自顶向下堆化，每次与左右子节点中比当前元素小且最小的那个交换，直到无法再次交换。

### 代码

```java
class KthLargest {
    //小顶堆，堆顶是第K大元素
    int[] datas;
    //堆中最多放几个元素
    int max;
    //堆中目前有几个元素
    int size;
    public KthLargest(int k, int[] nums) {
        datas = new int[k];
        max = k;
        for(int i = 0; i < nums.length; i ++){
            add(nums[i]);
        }
    }
    
    public int add(int val) {
        if(size < max){
            int cur = size;
            datas[cur] = val;
            while(cur > 0){
                if(datas[cur] < datas[(cur-1)/2]){
                    int tmp = datas[(cur-1)/2];
                    datas[(cur-1)/2] = datas[cur];
                    datas[cur] = tmp;
                    cur = (cur-1)/2;
                }else{
                    break;
                }
            }
            size ++;
            return datas[0];
        }else {
        //如果当前元素小于堆顶则返回堆顶元素
        //如果当前元素大于堆顶则删除堆顶元素，并自顶向下堆化，然后返回堆顶元素
            if(val < datas[0]){
                return datas[0];
            }else {
                datas[0] = val;
                int cur = 0;
                while(true){
                	int minPos = cur;
                    if((cur*2 + 1) < size && datas[cur] > datas[cur*2 + 1]){
                        minPos = cur*2+ 1;
                    }
                    if((cur*2 + 2) < size && datas[minPos] > datas[cur*2 + 2]){
                        minPos = cur*2+ 2;
                    }
                    if(minPos == cur) {
                    	break;
                    }
                    int tmp = datas[cur];
                    datas[cur] = datas[minPos];
                    datas[minPos] = tmp;
                    cur = minPos;
                }
                return datas[0];
            }
        }
        
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```