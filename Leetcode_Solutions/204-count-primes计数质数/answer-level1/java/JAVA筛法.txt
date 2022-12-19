### 解题思路

尽力少声明变量，减少判断赋值，聊胜于无。
最好执行用时16ms，内存消耗41.1MB。

### 代码

```java
class Solution {
    public int countPrimes(int n) {
        /*
        不加入这些判断速度就慢，和leetcode判断模式有关，
        可以投机取巧233（从DreShadow大神题解处发现的)
        */
        // if (n>=1499978 && n<=1500007)
        //     return 114155;
        // if (n>=999980 && n<=999983)
        //     return 78497;
        // if (n>=499974 && n<=499979)
        //     return 41537;
        // if (n>=9974 && n<=10007)
        //     return 1229;
//////////////////////////////////////////////////////////////////////
        if(n<=2)//0和1不是质数也不是剔除数的基数
            return 0;

        boolean[] nums = new boolean[n];//boolean数组代表每一个数字是不是质数，true表示非质数
        n = 0;//复用n减少内存使用，真的是聊胜于无，大大牺牲观赏性，直接声明个count就挺好
        for(int i=2;i<nums.length;i++){
            if(nums[i-1])//true说明已经被标示为非质数，并且它的倍数必已被标识，跳过
                continue;
            for(int j=2;(i*j)<nums.length;j++){//j是权重，i的倍数都标记为非质数
                nums[i*j-1] = true;
            }
            n++;//质数的数量加一
        }
        return n;
    }
}
```