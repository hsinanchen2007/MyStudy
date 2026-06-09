### 解题思路
方法一逻辑可行，但是会超时
方法二随着remove的元素越来越多。list的大小也在缩小

### 代码
解法一：超时
```java
class Solution {
    public int lastRemaining(int n, int m) {
        int[] a = new int[n];
        int count = n;
        int index = -1;
        for(int i=0;i<a.length;i++){
            a[i] = i;
        }
        while(count > 0){
            int step = m;
            //往后找第m个且没有被去除的数字
            while(step > 0){
                index = (index + 1) % a.length;
                if(a[index] != -1){
                    if(count == 1){
                        return a[index];
                    }
                    step--;
                }
            }
            a[index] = -1;
            count--;
        }
        return -1;
    }
}
```
解法二：随着问题的不断缩小，list的大小也在缩小
```java
class Solution {
    public int lastRemaining(int n, int m) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        int index = 0;
        while (n > 1) {
            index = (index + m - 1) % n;
            list.remove(index);
            n--;
        }
        return list.get(0);
    }
}
```