### 解题思路
该问题属于一一对应问题，可以采用map进行解决，
套路是：
集合A中的每个元素应与B中每个元素一一对应（A<->B）,但是map只能表示（A->B）,即一个A中每个元素
只能对应B中一个元素，但是B中一个元素可以对应A中多个元素（例如："a"->2,"b"->2）,故在建立A到B的映射
时除了用containsKey考虑A中元素是否已经建立映射外，还应该用containsValue保证B中元素也没有建立映射
，这样就保证了A和B中元素时一一映射的。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        //设s为集合A，t为集合B
        if(s.length()!=t.length()){
            return false;
        }
        HashMap<Character,Character> map=new HashMap<>();//关于A->B的映射
        for (int i = 0; i < s.length(); i++) {
            char sc=s.charAt(i);
            char tc=t.charAt(i);
            if(map.get(sc)==null){//保证A中当前元素未建立映射
                if(map.containsValue(tc)){//保证B中当前元素未建立映射
                    return false;
                }
                map.put(sc,tc);//建立A中当前元素与B中当前元素一一映射关系
            }else if(map.get(sc)!=tc){
                return false;
            }
        }
        return true;
    }
}
```