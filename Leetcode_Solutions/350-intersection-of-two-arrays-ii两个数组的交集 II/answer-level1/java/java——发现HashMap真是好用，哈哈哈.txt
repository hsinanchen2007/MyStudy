//先用Hashmap记录第一个数组中的元素【放在key】，和出现的次数【放在value】。然后再遍历第二个数组，如果找到对用元素&&对应HashMap中的value不为0，则添加这个元素到list中等下放到数组中，同时，HashMap中的value值减一，表示已经找到一个相同的了。最后的话，将list中的值取出来，放到数组中返回
```
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        //先遍历第一个数组，并初始化map
        for(int i = 0; i < nums1.length; i++){
            if(map.containsKey(nums1[i]))
                map.put(nums1[i], map.get(nums1[i]) + 1);
            else
               map.put(nums1[i], 1); 
        }
        
        //再遍历第二个数组，将于map中找到的key放入list中
        LinkedList<Integer> list = new LinkedList<Integer>();
        for(int j = 0; j < nums2.length; j++){
            if(map.containsKey(nums2[j]) && map.get(nums2[j]) > 0){
                list.add(nums2[j]); //添加到list中
                map.put(nums2[j], map.get(nums2[j]) - 1);
            }
        }
        
        //最后，将list中的值放入数组中
        int count = list.size();
        int[] aux = new int[count];
        for(int i = 0; i < count; i++){
            aux[i] = list.poll();
        }
        return aux;
    }
}
```