## 思路一：排序

非递减排序，然后顺序遍历同时记录出现过的最大值curMax。

如果A[i]大于curMax因为是排序过的数组则A[i]是[0,i]区间内唯一的不需要move；如果A[i]小于等于curMax则需要move增加至大于curMax才能确保A[i]在[0,i]区间内是唯一的。

```java
public int minIncrementForUnique(int[] A) {
    if (A.length<2)return 0;
    //排序
    Arrays.sort(A);
    int ans=0,curMax=A[0];
    //遍历
    for (int i = 1; i < A.length; i++) {
        //A[i]小于等于curMax,需要增加到大于curMax
        if (A[i]<=curMax){
            ans+=curMax-A[i]+1;
            A[i]=curMax+1;
        }
        //更新curMax
        curMax=Math.max(curMax,A[i]);
    }
    return ans;
}
```

## 思路二：计数法

有点像计数排序的感觉。计数数组大小为40000*2防止最坏情况40000个39999。

先统计所有数出现的个数。

然后遍历计数数组，如果A[i]个数大于1则将多出来的元素各进行一次move保证A[i]唯一，并将进行move的多余元素个数计入counter[A[i]+1]。

```java
public int minIncrementForUnique(int[] A) {
    if (A.length<2)return 0;
    int ans=0;
    //统计数量
    int[] counter=new int[80000];
    for (int i : A) {
        counter[i]++;
    }
    for (int i = 0; i < counter.length; i++) {
        //如果当前元素数量大于1，则将多余元素都分别move后都计入增加后的位置
        if (counter[i] > 1) {
            ans+=counter[i]-1;
            counter[i+1]+=counter[i]-1;
        }
    }
    return ans;
}
```
---

计数方法应该是可以用Map实现的，用C++完成了，但是没想好Java怎么解决Map遍历时新增的键值对不会被遍历到这个麻烦，API还是不熟悉。
半成品扔这里了：

```java
public int minIncrementForUnique(int[] A) {
    if (A.length<2)return 0;
    int ans=0;
    Map<Integer,Integer> map=new ConcurrentHashMap<>();
    for (int i = 0; i < A.length; i++) {
        map.put(A[i],map.getOrDefault(A[i],0)+1);
    }
    Set<Map.Entry<Integer, Integer>> entries = map.entrySet();
    for (Map.Entry<Integer, Integer> entry : entries) {
        if (entry.getValue()>1){
            ans+=entry.getValue()-1;
            map.put(entry.getKey()+1,map.getOrDefault(entry.getKey()+1,0)+entry.getValue()-1);
            entries=map.entrySet();
        }
    }
    return ans;
}
```

can you help help me?