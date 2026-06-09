### 解题思路
先用hashmap计数，然后对出现次数进行桶排序，最后倒序打印即可

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        if(s.length()<=2){
            return s;
        }
        Map<Character,Integer> counter = new HashMap<>( s.length() );
        int max = 1;
        char[] chars = s.toCharArray();
        for (char c : chars) {
            if(counter.containsKey( c )){
                int val = counter.get( c )+1;
                counter.put( c,val );
                if(val>max){
                    max = val;
                }
            }else{
                counter.put( c,1 );
            }
        }
        if(max==1){
            return s;
        }
        String[] ch = new String[max+1];
        Iterator<Character> iterator = counter.keySet().iterator();
        while(iterator.hasNext()){
            Character key = iterator.next();
            Integer val = counter.get( key );
            StringBuffer sb = null;
            if(null==ch[val]){
                sb = new StringBuffer(  );
            }else{
                sb = new StringBuffer( ch[val] );
            }
            for(int i=0;i<val;i++){
                sb.append( key );
            }
            ch[val] = sb.toString();
        }
        StringBuffer sb = new StringBuffer(  );
        for (int i = ch.length - 1; i >= 0; i--) {
            if(null!=ch[i]){
                sb.append( ch[i] );
            }

        }

        return sb.toString();
    }
}
```