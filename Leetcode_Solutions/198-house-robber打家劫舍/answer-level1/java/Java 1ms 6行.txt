#### 每次 max(截至上上家的最高金额 + 这家， 当前的最高金额) ，代码如下，
```java []
public int rob(int[] nums) {
    int pre = 0, now = 0;
    for (int i : nums){
        int tmp = now;
        now = Math.max(pre + i, now);
        pre = tmp;   // 这一步很关键，pre是 i 的前一个数之前的最高金额
    }
    return now;
}
```
```python []
def rob(self, nums: List[int]) -> int:
    last, now = 0, 0
    for i in nums:
        last, now = now, max(last + i, now)
    return now
```

#### 很多人可能想不明白，我直接拿两个例子用最原始的办法让你看明白
* [1, 7, 1, 1, 8, 1] 你看一眼就知道答案是15，下面程序走一波：

i|pre|pre+i|now|tmp
--|--|--|--|--
\ |0|\ |0|\
1|0|1|0|0
7|1|7|7|0
1|7|2|7|7
1|7|8|8|7
8|8|15|15|8
1|15|9|15|15


* [1, 7, 8, 1, 1, 1] 这个可能需要两眼，答案是10(最后两家抢谁的都一样)，继续程序走一波：

i|pre|pre+i|now|tmp
--|--|--|--|--
\ |0|\ |0|\
1|0|1|1|0
7|1|7|7|1
8|7|9|9|7
1|9|8|9|9
1|9|10|10|9
1|10|10|10|10