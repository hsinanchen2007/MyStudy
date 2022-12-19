### 解题思路
等差数列，具体代码已经注释

### 代码

```java
class Solution {
    private int n ;//总人数
    private int times;//分发次数，不足分发这一次的全部，也算1次
    private int last;//最后分配到的那个人（糖果数量足够），也就是left变量是last的下一个分配对象
    private int candies;
    private int left;//最后要分配糖果数不够（不比前一次发出的糖果多））
    public int[] distributeCandies(int candies, int num_people) {
        this.n = num_people;
        this.candies = candies;
        int[] res = new int[n];
        init();
        //对每一个人分配糖果
        for (int index = 0; index < n; index++) {
            if(index <= last)
                 res[index] = ((index+1)*times)+(times*times-times) * n /2;
            else {
                res[index] = ((index + 1) * (times-1)) + ((times-1) * (times-1) - (times-1)) * n / 2;
            }
        }
        //最后把糖果数不足的分配出去
        res[(last+1)%n] += left;
        return res;
    }

    private void init(){
        int times = 1;
        while(candies > 0){
            candies -= oneSum(n,times);
            times++;
        }
        times-=1;
        candies +=oneSum(n,times);
        int last = 0;
        while (candies >= (times-1)*n+last+1){
            candies -= (times-1)*n+last+1;
            last++;
        }
        this.left = candies;
        this.times = times;
        this.last  = last-1;
    }

    /**
     * @param num_people
     * @param times 能分配的次数
     * @return 需要分配出去的糖果数量
     */
    private int oneSum(int num_people,int times){
        return (1+n) * num_people / 2  + (times-1) * n * n;//等差数列求和
    }

}
```