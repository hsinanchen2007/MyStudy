### 解题思路一
直接模拟整个过程，运行大概1s多一些，ArrayList可以通过，LinkedList不可以

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            list.add(i);
        }
        int index = (m-1) % n;
        while(list.size() != 1) {
            list.remove(index);
            n--;
            index = (index + m - 1) % n; 
        }
        return list.get(0);
    }

}
```


### 解题思路二
其实根据上述的代码也能看出，递推式就是f(n) = (f(n-1) + m) % n

### 代码

```
    public int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
```