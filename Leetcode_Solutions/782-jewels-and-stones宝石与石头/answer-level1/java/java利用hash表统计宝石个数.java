### 解题思路
利用hashmap的key的唯一性；

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int count=0;
        HashMap<Character,Integer> hashMap=new HashMap<>();
        for(int i=0;i<J.length();i++){
            hashMap.put(J.charAt(i),i);
        }
        int size=hashMap.size();
        for(int i=0;i<S.length();i++){            
            hashMap.put(S.charAt(i),i);
            if(hashMap.size()>size){
                hashMap.remove(S.charAt(i));
            }else{
                count++;
            
            }
        }

        return count;
    } 
}
```