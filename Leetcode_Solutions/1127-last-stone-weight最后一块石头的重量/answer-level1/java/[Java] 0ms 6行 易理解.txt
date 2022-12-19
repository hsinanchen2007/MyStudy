# 解题思路：
- 问题规模比较小（stones.length < 30）,可以考虑使用排序
- 每排一次序，进行一次操作，操作窗口只是最后两个数组元素

```
public int lastStoneWeight(int[] stones) {
        if(stones.length == 1)
            return stones[0];

        int index = stones.length - 1;  //每次操作最大数的下标
        Arrays.sort(stones);
        while(stones[index-1] != 0){    //第二大数为0，说明已经完成
            int x = stones[index-1];
            int y = stones[index];
            if(x == y){
                stones[index] = stones[index-1] = 0;
            }else{
                stones[index-1] = 0;
                stones[index] = y - x;
            }
            Arrays.sort(stones);
        }
        return stones[stones.length-1];
    }
```

**代码越短，别人越容易看懂[大道至简]**  （所以对上面代码进行了优化）
```
public int lastStoneWeight(int[] stones) {
        int index = stones.length - 1;
        for(int i = 0; i < stones.length - 1; i++){     //通过stones.length来判断需要操作的次数。（不用将stones.length == 1的情况单独考虑）
            Arrays.sort(stones);                        //将sort放在循环体的开始。（避免在循环体外再写一次重复的sort（））
            stones[index] -= stones[index-1];           //两种不同情况使用同一表达式处理。（）
            stones[index-1] = 0;
        }
        return stones[stones.length-1];
    }
```

