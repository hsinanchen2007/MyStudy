```java []
    public int jump(int[] nums) {
        if(nums.length == 1) return 0; //特殊情况，一步不走就到终点
        int last = 0; //上上一步可达的最远距离
        int next = nums[0]; //上一步可达的最远距离
        int furthest = nums[0]; //这一步可达的最远距离
        int step = 1; //计步
        //计算步数，每一次while循环代表走出了一步
        while(furthest < nums.length-1){
            //推算这一步可达的最远距离，从next到furhtest，都是这一步可以走到的位置
            //而具体走到哪一位置应该是根据，走到哪一位置，可以让下一步走得更远来确定的
            //所以，这个循环里，最后一次使furthest更新的i就是上一步走到的位置
            for(int i = last+1; i <= next; ++i){
                if(i + nums[i] > furthest){
                    furthest = i + nums[i];
                }
            }
            //更新参数
            step++;
            last = next;
            next = furthest;
        }
        //循环结束则说明，这一步可以到达终点了，返回步数即可
        return step;
    }
```
