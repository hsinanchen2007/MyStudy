运用的知识点：
1.for强循环
2.Map<key,value>
3.Set.不能含有重复的数值
思路：
1.把数组中重复的数字的次数赋予到map中
2.在将map中的数值赋予到set中，验证是否能成功赋值。失败则说明有重复值

```
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        Set<Integer> set = new HashSet<Integer>();
        for(int data:arr){
            if(map.get(data)==null){
                map.put(data,1);
            }else{
                map.put(data,map.get(data)+1);
                    
            }
        }
        for(int i:map.values()){
            if(!set.add(i)){
                return false;
            }
        }
       return true;
    }
}
```
