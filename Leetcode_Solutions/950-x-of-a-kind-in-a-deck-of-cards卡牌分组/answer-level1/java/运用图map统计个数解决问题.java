### 解题思路
1 建立了两个集合，一个map用来统计牌的类型和数量，集合set用来确保map的关键字key不会重复
2 获得map后，再获取map的值中最小的那个数，作为未知量X的循环的上限（X即题目中的X）
3 通过遍历X，寻找是否满足题目要求的方式。
### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer,Integer> map=new HashMap<>();
        HashSet<Integer> set = new HashSet<>();
        int min=10000;
        for (int i = 0; i < deck.length; i++) {
            boolean flag=set.add(deck[i]);
            if(flag){
                map.put(deck[i],1);
            }
            else{
                int demo=map.get(deck[i]);
                map.put(deck[i],++demo);
            }
        }
        for(int set1:map.keySet()){
            if(min>map.get(set1)) min=map.get(set1);
        }
        for(int x=2;x<=min;x++){
            boolean flag=false;
            for(int set1:map.keySet()){
                if(map.get(set1)%x!=0){
                    flag=true;
                    break;
                }
            }
            if(!flag) return true;
        }

        return false;
        //System.out.println(map);
    }
}
```