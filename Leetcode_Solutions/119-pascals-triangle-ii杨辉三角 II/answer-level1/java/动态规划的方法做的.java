### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> pre = new ArrayList<> ();
        List<Integer> cur = new ArrayList<> ();
        if(rowIndex==0){
            cur.add(1);
            return cur;
        }
        if(rowIndex==1){
            cur.add(1);
            cur.add(1);
            return cur;
        }
        pre.add(1);
        pre.add(1);
        for(int i=2;i<=rowIndex+1;i++){
            cur.clear();
            cur.add(1);
            for(int j=1;j<=i-2;j++){
                cur.add(pre.get(j-1)+pre.get(j));
            }
            cur.add(1);
            pre.clear();
            pre.addAll(cur);
        }
        return pre;
    }
}
```