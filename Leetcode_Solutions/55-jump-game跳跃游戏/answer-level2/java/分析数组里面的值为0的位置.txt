思路：我想到的方法是分析数组里面的0的位置，因为数组里面的数据为非负，只要把所有的数据为0的位置跨过那么就一定可以从头走到尾，因此只分析0。先把数组扫一遍记录下所有为0的坐标，针对每一个为零的坐标再从右向左扫面，只要有一个可以跨过该位置的0，那么进入下一个0位置。所有零位置都可以跨过之后就返回true。另外如果0位置在最后一个，则不用“跨过”，只需要可以到达该点即可。
```
public class JumpGame {
    private boolean overZero(int [] nums,int index){
            if (index==nums.length-1){
                for (int i=0;i<index;i++)if (nums[i]+i>=index)return true;
            }
            else {
                for (int i=0;i<index;i++)if (nums[i]+i>index)return true;
            }
            return false;
        }
    public boolean canJump(int[] nums) {
        ArrayList<Integer> zerosIndex=new ArrayList<>();
        if (nums.length==1) return true;
        for (int i=0;i<nums.length;i++) {
            if (nums[i]==0)zerosIndex.add(i);
        }
        for (int z:zerosIndex) {
            if (!overZero(nums,z))return false;
        }
        return true;
    }
}
```

