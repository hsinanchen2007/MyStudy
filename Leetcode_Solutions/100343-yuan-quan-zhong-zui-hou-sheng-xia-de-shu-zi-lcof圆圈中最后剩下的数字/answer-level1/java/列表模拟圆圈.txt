### 解题思路
1.用列表模拟，先将数字都加入列表，然后每格m个删除一次，知道列表只剩下一个元素

2.数学法，不是十分理解

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++){
            list.add(i);
        }
        int idx = 0;
        while(n > 1){
            idx = (idx + m - 1) % n;
            list.remove(idx);
            n--;
        }
        return list.get(0);

        // int ans = 0;
        // // 最后一轮剩下2个人，所以从2开始反推
        // for (int i = 2; i <= n; i++) {
        //     ans = (ans + m) % i;
        // }
        // return ans;
    }
}
```