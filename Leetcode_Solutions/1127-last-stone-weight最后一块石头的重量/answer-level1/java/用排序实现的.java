按自己的理解写的`int result = 0;
        if (stones==null){
            return result;
        }
        if (stones.length<2){
            return stones[0];
        }
        Arrays.sort(stones);
        do {
            if (stones[stones.length - 2] == stones[stones.length - 1]) {
                stones[stones.length - 2] = 0;
                stones[stones.length - 1] = 0;
            } else if (stones[stones.length - 2] < stones[stones.length - 1]) {
                stones[stones.length - 1] = stones[stones.length - 1] - stones[stones.length - 2];
                stones[stones.length - 2] = 0;
            }
            Arrays.sort(stones);
        }
        while (!(stones[stones.length - 2] <= 0));
        result = stones[stones.length - 1];
        return result;`
