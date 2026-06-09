### 解题思路
应该是没了

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
         boolean res=true;
        Map<String,Integer> map=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(map.get(String.valueOf(arr[i]))==null){
                map.put(String.valueOf(arr[i]),new Integer(1));
            }else{
                int v=map.get(String.valueOf(arr[i])).intValue()+1;
                map.put(String.valueOf(arr[i]),v);
            }
        }
        
          Set<Map.Entry<String,Integer>> entrySet = map.entrySet();
        //遍历Set集合
        Iterator<Map.Entry<String,Integer>> it1 =entrySet.iterator();
        Map.Entry<String,Integer> entry = it1.next();
        //通过每一对对应关系获取对应的value
        Integer value = entry.getValue();
        ArrayList<Integer> forward=new ArrayList<>();
        forward.add(new Integer(value));

      k:  while(it1.hasNext()){
            //得到每一对对应关系
             entry = it1.next();
             for(Integer f:forward) {


                 if (f.intValue() == entry.getValue().intValue()) {
                     res = false;
                     break k;
                 }

             }
             forward.add(new Integer(entry.getValue().intValue()));
        }





        return res;
        
    }
}
```