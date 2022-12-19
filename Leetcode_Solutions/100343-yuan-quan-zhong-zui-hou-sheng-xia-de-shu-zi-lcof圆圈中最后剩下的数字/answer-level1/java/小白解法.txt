### 解题思路
本质就是约瑟夫环

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if(n<1||m<1){
            return -1;
        }
        ArrayList<Integer> list=new ArrayList<>();
        for(int i=0;i<n;i++){
            list.add(i);
        }
        int b=0;
        while(list.size()>1){
            b=(b+m-1)%list.size();
            list.remove(b);
        }
        return list.get(0);
    }
}
```