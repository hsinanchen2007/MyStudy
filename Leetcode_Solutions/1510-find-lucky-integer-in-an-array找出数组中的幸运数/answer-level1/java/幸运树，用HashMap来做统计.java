### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer,Integer> resultMap = new HashMap<>();
        for(int i =0;i<arr.length;i++){
            if(!resultMap.containsKey(arr[i])){ //当不包含这个key值的时候，就是第一次出现，数量就是1
                resultMap.put(arr[i],1);
            }else{                              //包含这个KEY的时候
                int count = resultMap.get(arr[i]); 
                count++;
                resultMap.replace(arr[i],count);  //更新键值用replace
            }
        }
        int target = -1;
        Set keyset = resultMap.keySet();
        for(Object obj:keyset){   //键值key是Object类型的对象
            int a = Integer.parseInt(String.valueOf(obj));
            if(a == resultMap.get(a) && a>=target){

                target = a;
            }
        }
        return target;
    }
}
```