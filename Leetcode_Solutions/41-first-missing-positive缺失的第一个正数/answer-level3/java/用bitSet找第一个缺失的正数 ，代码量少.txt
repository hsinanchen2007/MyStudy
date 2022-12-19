```
public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        BitSet bitSet = new BitSet(len+1);

        for(int i:nums){
            if(i>0){
                if(i>len){  //改进一下，不用一个len限制，数组如果只包含一个Integer.MAX_VALUE，会超出内存限制
                    continue;
                }else{
                    bitSet.set(i);
                }
            }
        }
        return bitSet.nextClearBit(1);
    }
```
