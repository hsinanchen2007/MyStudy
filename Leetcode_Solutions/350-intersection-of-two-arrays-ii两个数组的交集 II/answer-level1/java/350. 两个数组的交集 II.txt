
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 *
 * 解题思路: 使用hashmap 记录个数
 */
```
public int[] intersect(int[] nums1, int[] nums2) {
    int[] res ;
    if(nums1.length == 0 || nums2.length == 0){
        return new int[0];
    }

    ArrayList<Integer> arrayList = new ArrayList();

    HashMap<Integer, Integer> hashMap = new HashMap<>();

    for(int i = 0;i < nums1.length;i++){
        if(!hashMap.containsKey(nums1[i])){
            hashMap.put(nums1[i],1);
        }else{
            hashMap.put(nums1[i],hashMap.get(nums1[i]) + 1);
        }
    }

    for(int i = 0,j = 0; i < nums2.length;i++){
        if(hashMap.containsKey(nums2[i]) && hashMap.get(nums2[i]) > 0){
            arrayList.add(nums2[i]);
            hashMap.put(nums2[i],hashMap.get(nums2[i]) - 1);
        }
    }

    res = new int[arrayList.size()];

    for(int i = 0; i < arrayList.size();i++){
        res[i] = arrayList.get(i);
    }
    return res;
}

```