### 解题思路
java大根堆实现

(leetcode官方)我们用一个大根堆实时维护数组的前 k 小值。首先将前 k 个数插入大根堆中，随后从第 k+1个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，再插入当前遍历到的数。最后将大根堆里的数存入数组返回即可。


### 代码

```java
//获取最大的k个值  小根堆
//获取最小的k个值  大根堆
class Solution {
    public int[] getLeastNumbers(int[] arr, int k){  
        if(k == 0)  return new int[0];

        Queue<Integer> q = new PriorityQueue<>(k, new Comparator<Integer>() {
            public int compare(Integer i1, Integer i2) {
                    return i2-i1;
                }
            });

        for (int i = 0; i < k; i++)  q.add(arr[i]);
        for (int i = k; i < arr.length; i++) {
            if(arr[i] < q.peek()){
                q.poll();
                q.add(arr[i]);
            }
        }

        Object[] resTmp = q.toArray();
        int[] res = new int[k];
        for(int i = 0; i < k; i++){
            res[i] = (Integer)resTmp[i];
        }

        return res;
    }
}
//[3,2,1,1]   k=2   输出:[1,1]
```