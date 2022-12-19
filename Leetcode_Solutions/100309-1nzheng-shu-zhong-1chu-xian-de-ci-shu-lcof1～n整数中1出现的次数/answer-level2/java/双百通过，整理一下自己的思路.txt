### 解题思路
思路是基于连续数字这样一个特征：低位从1到9一个循环后会进一位，例如：
第0位：1,2,3……9,0 开始循环，循环长度为10，每个数字在循环中出现 1 次；
第1位：1……1, 2……2,……,9……9, 0……0 开始循环，循环长度为$10^2$，每个数字在循环中出现$10^1$次；
第2位：1……1, 2……2,……,9……9, 0……0 开始循环，循环长度为$10^3$， 每个数字在循环中出现$10^2$次；
第n位：1……1, 2……2,……,9……9, 0……0 开始循环，循环长度为$10^{n+1}$， 每个数字在循环中出现$10^n$次；
一般循环不会是完整的，假设有$circle$个循环，考虑有$tail$个余数情况：
第n位：1……1, 2……2,……, k…k,余数从$1$到$k-1$的每个数有$10^n$，第$k$个数出现$leaveTail$次；

这样可以得到各位 1 出现的次数为：
$$a[i] = {circle*10^i+10^i(k>=1) \atop circle*10^i+leaveTail(k<1)}$$
$circle = (n - 10^i +1)/10^{i+1}$
$tail = (n - 10^i +1)\%10^{i+1}$
$k = tail / 10^{i}$
$leaveTail = tail \% 10^{i}$

如果问题是求0-9分别出现的个数话，可以用相同方法直接计算。
面试时候就被问了个这题目，思路有了没写出来，结果凉凉，我真的太菜了。


### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        int count = 0, res = 0, tmp = n;
        while(tmp>0){
            count++;
            tmp/=10;
        }
        int factorCur = 1, factorNex = 10;
        for(int i=0; i<count; i++){
            int realCount = n-factorCur+1;
            int circle = realCount/factorNex;
            int tail = realCount%factorNex;
            int k = tail/factorCur;
            int leaveTail = tail%factorCur;
            res += circle*factorCur;
            if(k > 0) res += factorCur;
            else res += leaveTail;
            factorCur*=10;
            factorNex*=10;
        }
        return res;
    }
}
```