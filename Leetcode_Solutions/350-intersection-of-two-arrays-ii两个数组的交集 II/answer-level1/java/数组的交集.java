```
public int[] intersect(int[] nums1, int[] nums2) {
    int len1 = nums1.length;
    int len2 = nums2.length;

    int[] outer = len1-len2>=0?nums2:nums1;
    int[] inner = len1-len2>=0?nums1:nums2;

    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < outer.length; i++) {
        if (map.containsKey(outer[i])) {
            map.compute(outer[i], (k, v) -> v + 1);
        }else {
            map.put(outer[i], 1);
        }
    }

    List<Integer> list = new ArrayList<>();
    for (int i = 0; i < inner.length; i++) {
        if (map.containsKey(inner[i])) {
            if (map.get(inner[i]) >= 1) {
                list.add(inner[i]);
                map.compute(inner[i], (k, v) -> v - 1);
            }
        }
    }
    int[] res = new int[list.size()];
    for (int i = 0; i < list.size(); i++) {
        res[i] = list.get(i);
    }
    return res;
}
```

一开始也想着用map,但是考虑到是算法嘛，怎么能用jdk自带的类库的，结果绞尽脑汁，最后*^O^*map真香！

我为什么要判断两个数组的长度呢？减少map存储空间，算不算优化呢？哈哈(o^^o)

算法里用了map的compute方法，主要是为了解决多值问题。（数组里有重复值呀(＞人＜;) ）
