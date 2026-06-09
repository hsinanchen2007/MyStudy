### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findLucky(int[] arr) {
    int res=-1;
        HashMap<Integer,Integer> hm=new HashMap<>();


        for (int i : arr) {
            if(hm.keySet().contains(i)){
                int v=hm.get(i);
                v+=1;
                hm.put(i,v);
            }else{
                hm.put(i,1);
            }
        }

        ArrayList<Integer> al=new ArrayList<>();

        for (Integer i : hm.keySet()) {
            if(i==hm.get(i)){
               al.add(i);
            }
        }

        if(al.size()==0){
            res=-1;
        }else{
            for (Integer i : al) {
                if(i>res) res=i;
            }
        }
        return res;    
    }
}
```