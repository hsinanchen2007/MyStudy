### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length<2)return 0;
        Arrays.sort(A);
        List<Integer> list=new ArrayList<>();
        for(int i:A){
            list.add(i);
        }
        int res=0;
        for(int i=1;i<list.size();i++){
            int count=0;
            if(list.get(i)<=list.get(i-1)){
                count=list.get(i-1)+1-list.get(i);
                res=res+count;
                list.set(i,list.get(i-1)+1);
            }
        }
        return res;
    }
}
```