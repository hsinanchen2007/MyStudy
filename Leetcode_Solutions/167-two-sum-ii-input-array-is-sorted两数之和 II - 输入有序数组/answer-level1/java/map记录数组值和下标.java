执行结果：
通过
显示详情
执行用时 :
11 ms
, 在所有 Java 提交中击败了
13.97%
的用户
内存消耗 :
39.4 MB
, 在所有 Java 提交中击败了
17.30%
的用户
```
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        Map<Integer,Integer> dup = new HashMap<Integer,Integer>();
        int len = numbers.length;
        int[] res = new int[2];
        if(len==0)return res;
        for(int i=0; i<len; i++){
            if(map.get(numbers[i])==null){
                map.put(numbers[i],i+1);
            }else{
                dup.put(numbers[i],i+1);
            }
        }
        Iterator<Integer> it = map.keySet().iterator();
        while(it.hasNext()){
            Integer st = it.next();
            if(st!=target-st && map.get(target-st)!=null){
                int s = map.get(st);
                int e = map.get(target-st);
                if(s<e){
                    res[0]=s;
                    res[1]=e;
                }else{
                    res[0]=e;
                    res[1]=s;
                }
                break;
            }else if(st==target-st && dup.get(st)!=null){
                int s = map.get(st);
                int e = dup.get(st);
                if(s<e){
                    res[0]=s;
                    res[1]=e;
                }else{
                    res[0]=e;
                    res[1]=s;
                }
                break;
            }
        }
        return res;
        
    }
}
```
