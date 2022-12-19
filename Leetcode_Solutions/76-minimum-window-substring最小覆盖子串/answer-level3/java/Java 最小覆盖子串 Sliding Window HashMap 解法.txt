
### 代码

```java
class Solution {
    HashMap<Character,Integer> map = new HashMap<>() ;
    int size , count ;
    public String minWindow(String s, String t) {
        initiateMap(t) ;
        size = map.size() ;
        char[] ss = s.toCharArray() ;
        int left = getFirstIndex(ss,0) ;
        if(left == -1){
            return "" ;
        }
        String ans = "" ;
        int right = left , n = ss.length , min = Integer.MAX_VALUE ;
        for(int k = right ; k < n ; k++){
            if(map.containsKey(ss[k])){
                map.put(ss[k],map.get(ss[k])-1) ;
                if(map.get(ss[k]) == 0){
                    count++ ;
                    while(count == size){
                        if(min > k - left + 1){
                            ans = s.substring(left,k+1) ;
                            min = k - left + 1 ;
                        }
                        map.put(ss[left],map.get(ss[left])+1) ;
                        if(map.get(ss[left]) == 1){
                            count-- ;
                        }
                        left = getFirstIndex(ss,left+1) ;
                      //  right += 1 ;
                    }
                }
            }
        }
        return ans ;
    }
    public void initiateMap(String t){
        for(char c:t.toCharArray()){
            map.put(c,map.getOrDefault(c,0)+1) ;
        }
    }
    public int getFirstIndex(char[] ss,int start){
        for(int i = start ; i < ss.length ; i++){
            if(map.containsKey(ss[i])){
                return i ;
            }
        }
        return -1 ;
    }
}
```