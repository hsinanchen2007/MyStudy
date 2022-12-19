### 解题思路
模拟循环链表和迭代以及递归
### 代码
第一种模拟链表解法
```java
class Solution {
    public int lastRemaining(int n, int m) {
        if(n<1 || m<1){
            return -1;
        }
        List<Integer> list = new ArrayList();
        for(int i =0;i<n;i++){
            list.add(i);
        }
        int index = (m-1)%n;
        while(list.size()!=1){
            list.remove(index);
            index = (index+m-1)%list.size();
        }
        return list.get(0);
        

    }
}
```

第二种，迭代也就是动态规划，没太看懂
class Solution {
    public int lastRemaining(int n, int m) {
        if(n<1 || m<1){
            return -1;
        }
        int last = 0;
        for(int i =2;i<=n;i++){
            last = (last+m)%i;
        }
        return last;
    }
}
第三种 递归
class Solution {
    public int lastRemaining(int n, int m) {
        if(n<1 || m<1){
            return -1;
        }
        if(n ==1){
            return 0;
        }


        return (lastRemaining(n-1,m)+m)%n;
    }
}