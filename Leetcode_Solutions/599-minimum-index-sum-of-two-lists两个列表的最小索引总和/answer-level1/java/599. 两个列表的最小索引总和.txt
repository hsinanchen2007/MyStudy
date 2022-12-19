/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/26
 *
 * 解题思路: 使用hashMap 存储list1<数值,索引>, 然后遍历list2 并判断相同的名称的索引值大小,取最小的集合装进Arrays
 */
```
 public String[] findRestaurant(String[] list1, String[] list2) {
    ArrayList<String> arrays = new ArrayList<String>();
    HashMap<String,Integer> hashMap = new HashMap();
    int index_sum = Integer.MAX_VALUE;
    for(int i = 0;i < list1.length;i++){
        hashMap.put(list1[i],i);
    }

    for(int i = 0;i < list2.length;i++){
        if(hashMap.containsKey(list2[i])){
            if(i + hashMap.get(list2[i]) < index_sum){
                index_sum = i + hashMap.get(list2[i]);
                arrays.clear();
                arrays.add(list2[i]);
            }else if(i + hashMap.get(list2[i]) == index_sum){
                arrays.add(list2[i]);
            }
        }
    }
    return arrays.toArray(new String[arrays.size()]);
}
```