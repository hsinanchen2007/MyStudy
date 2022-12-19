先看示例，找规律。
示例 1：
输入：n = 2, start = 3
输出：[3,2,0,1]
解释：这个排列的二进制表示是 (11,10,00,01)
从 0开始的二进制排列是 [0,1,3,2] (00,01,11,10)

示例 2：
输出：n = 3, start = 2
输出：[2,6,7,5,4,0,1,3]
从 0开始的二进制排列是 
[0,1,3,2,6,7,5,4] 
(000,001,011,010,110,111,101,100)

发现n=3的的从0开始的前四位与n=2的数值相同，后4位为镜像+4（首位为1，<000 : 100>,<001 : 101>）
那么 n=4的时候，前8位与n=3时相同，后8位，为镜像+8。

那么就可以写个递归函数：
```
private List<Integer> build(int n){
        if(n==1) {
            List<Integer> list = new ArrayList<>();
            list.add(0);
            list.add(1);
            return list;
        }
        List<Integer> old = build(n-1);
        int size = old.size();
        List<Integer> res = new ArrayList<>(size * 2);
        int m = 1;
        while(n-->1) {
            m*=2;
        }
        res.addAll(old);

        for(int i=1;i<=old.size();i++) {
            res.add(res.get(size-i)+m);
        }
        return res;
    }
```
build(n) 得到以0为开开始的数组，再以值为start进行反转数组即可。

```
class Solution {
    // 代码的写法还可以优化，思路如此：
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> list = build(n);
        List<Integer> res = new ArrayList<>(list.size());
        int i = 0;
        for(;i<list.size();i++) {
            if(list.get(i).equals(start)) {
                break;
            }
        }
        res.addAll(list.subList(i, list.size()));
        res.addAll(list.subList(0, i));
        return res;
    }

    private List<Integer> build(int n){
        if(n==1) {
            List<Integer> list = new ArrayList<>();
            list.add(0);
            list.add(1);
            return list;
        }
        List<Integer> old = build(n-1);
        int size = old.size();
        List<Integer> res = new ArrayList<>(size * 2);
        int m = 1;
        while(n-->1) {
            m*=2;
        }
        res.addAll(old);

        for(int i=1;i<=old.size();i++) {
            res.add(res.get(size-i)+m);
        }
        return res;
    }
}
```
