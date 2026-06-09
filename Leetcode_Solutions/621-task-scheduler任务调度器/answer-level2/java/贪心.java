```
class Solution {
    public int leastInterval(char[] tasks, int n) {
        Map<Character,Integer> map = new HashMap<>();
        for(int i =0 ; i<tasks.length; ++i){
            Integer v = map.get(tasks[i]);
            if(v == null){
                map.put(tasks[i],1);
            }else{
                map.put(tasks[i],v+1);
            }
        }
        // 找到最大值的key
        int max = 0;
        for(int i : map.values()){
            if(i>max){
                max = i;
            }
        }
        int c = (max-1)*(n+1);
        for(int i : map.values()){
            if(i-(max-1)>0){
                c += (i-max+1);
            }
        }    
        if(map.size() <= n){
            return c;
        }else{
            return (c>tasks.length)?c:tasks.length;
        }
    }
}
```
