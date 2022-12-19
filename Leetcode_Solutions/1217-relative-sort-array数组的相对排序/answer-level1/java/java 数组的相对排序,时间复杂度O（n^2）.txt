### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
         Map<Integer,Integer> map = new LinkedHashMap<>();
        //初始化
        for (int i : arr2) {
            map.put(i,0);
        }
        //遍历arr2,用map存arr1的次数，和相对顺序
        for (int i = 0; i < arr2.length; i++) {
            for (int j = 0; j < arr1.length; j++) {
                if(arr2[i]==arr1[j]){
                    Integer count = map.get(arr2[i]);
                    map.put(arr2[i],++count);
                    //标记位
                    arr1[j] = -1;
                }
            }
        }

        List<Integer> list = new ArrayList<>();
        //遍历map,放在res中
        Set<Integer> keySet = map.keySet();
        Iterator<Integer> iterator = keySet.iterator();
        while(iterator.hasNext()){
            Integer key = iterator.next();
            Integer value = map.get(key);
            for(int i=0;i<value;i++){
                list.add(key);
            }
        }
         //对arr1升序排列
        Arrays.sort(arr1);
        //处理arr1剩下的元素，不在arr2下的元素
        for (int i : arr1) {
            if(i!=-1){
                list.add(i);
            }
        }
        //list转数组
        int[] res = new int[arr1.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = list.get(i);
        }
        return res;
    }
}
```
关键点：用map的key保存arr2的元素，用value保存arr2元素出现的次数。但这里要保留相对位置，所以需要用有顺序的LinkedHashMap。