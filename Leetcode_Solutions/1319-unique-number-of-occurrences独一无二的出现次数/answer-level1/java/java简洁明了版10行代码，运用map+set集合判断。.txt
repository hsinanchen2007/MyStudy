### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> map=new HashMap();
        HashSet<Integer> set=new HashSet();
        for(int i=0;i<arr.length;i++){
            map.put(arr[i],(map.get(arr[i]))!=null?(map.get(arr[i])+1):1);  //存储每个数字的次数
        }
        for(Integer v:map.values()){
            if(!set.add(v)){            //通过set判断是否有重复
                return false;
            }
        }
        return true;
    }
}
```