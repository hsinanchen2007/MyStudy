### 解题思路
先获取每个元素出现的次数，x必定小于数组长度，遍历每个元素出现的次数，如果能整除x，就说明有分组

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck.length<2) return false;
       Map<Integer,Integer> map=new HashMap();
       for(int i=0;i<deck.length;i++){
      if( map.get(deck[i])!=null){
              map.put(deck[i],map.get(deck[i])+1);
           }else{
               map.put(deck[i],1);
           }
       }
        Set<Integer> keyset=map.keySet();
           Iterator<Integer> it=keyset.iterator();
            List<Integer> list=new ArrayList();
            while (it.hasNext()) {
                Integer key=it.next();
                Integer value=map.get(key);
                list.add(value);
            }
          for(int x=2;x<=deck.length;x++ ){
              int count=list.size();
              for(int j=0;j<list.size();j++){
                if(list.get(j)%x==0){
                    count--;
                }
            } 
            if(count==0) return true;
          }
        return false;
    }
}
```