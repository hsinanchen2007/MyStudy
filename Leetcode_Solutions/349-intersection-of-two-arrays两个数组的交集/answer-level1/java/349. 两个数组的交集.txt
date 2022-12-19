/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 * 
 * 解题思路: 使用hashset 辅助来做 注意：一个空的数组 new int[0]
 */
```
public int[] intersection(int[] nums1, int[] nums2) {

    int[] res ;
    if(nums1.length == 0 || nums2.length == 0){
        return new int[0];
    }

    ArrayList<Integer> arrayList = new ArrayList();

    HashSet<Integer> hashSet = new HashSet<>();

    for(int i = 0;i < nums1.length;i++){
        hashSet.add(nums1[i]);
    }

    for(int i = 0,j = 0; i < nums2.length;i++){
        if(hashSet.contains(nums2[i])){
            arrayList.add(nums2[i]);
            hashSet.remove(nums2[i]);
        }
    }

    res = new int[arrayList.size()];

    for(int i = 0; i < arrayList.size();i++){
        res[i] = arrayList.get(i);
    }
    return res;
}

```