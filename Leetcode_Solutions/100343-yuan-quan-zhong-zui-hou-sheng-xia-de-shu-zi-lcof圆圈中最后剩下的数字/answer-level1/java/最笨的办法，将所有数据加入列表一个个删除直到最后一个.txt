### 解题思路
这个是最笨的办法了
将0至n-1放入ArrayList，然后按照题目要求一个一个的remove最后剩下的那个就是答案。

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        ArrayList<Integer> arr = new ArrayList(n);
        for(int i=0;i<n;i++){
            arr.add(i);
        }
        int index=0;
        while(n>1){
            index = (m+index-1)%n;
            if(index <0){
                index = n-2;
            }
            arr.remove(index);
            n--;
        }
        return arr.get(0);
    }
}
```