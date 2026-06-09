不知道怎么回事，本地可以运行，到这边就运行异常
```
public static boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(map.containsKey(arr[i])){
                //只需要数量++
                map.put(arr[i],map.get(arr[i])+1);
            }else{
                map.put(arr[i],1);
            }
        }
        //得到所有的值
        Collection<Integer> values = map.values();
        Set<Integer> set = new HashSet<>();
        set.addAll(values);
        if(set.size() == values.size()){//无重复
            return true;
        }
        return false;
    }
```
