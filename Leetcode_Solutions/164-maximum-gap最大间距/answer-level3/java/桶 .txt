```
class Solution {
        public int maximumGap(int[] nums) {

        if (nums.length<2){
            return 0;
        }

        long min = nums[0];
        long max = nums[0];
        for (int i = 1;i < nums.length;i ++) {
            long cur = nums[i];
            if (min > cur) min = cur;
            if (max < cur) max = cur;
        }

        if (max == min) {
            return 0;
        }

        long pailSize = Long.max(1,(max - min) / (nums.length-1)) ;
        long pailCount = (max - min)/pailSize + 1;

        
        ArrayList<Pail> pailPool = new ArrayList<>();
        for (int i = 0; i < pailCount;i ++) {
            pailPool.add(new Pail());
        }

        for (int i = 0;i < nums.length;i ++) {
            long cur = nums[i];
            int index = (int)( (cur - min)/pailSize );

            Pail cp = pailPool.get(index);
            if (cp.max == -1) {
                cp.max = cur;
                cp.min = cur;
            } else {
                if (cp.max < cur) {
                    cp.max = cur;
                } else if (cp.min > cur){
                    cp.min = cur;
                }
            }
//            System.out.println(pailPool.toString());
        }

//        System.out.println(pailPool.toString());

        long distance = pailSize;

        Pail lastPail = pailPool.get(0);
        for (int i =1;i < pailPool.size(); i ++) {
            Pail curP = pailPool.get(i);
            if (curP.max == -1) {
                continue;
            } else {
                long dd = curP.min - lastPail.max;
                if (dd > distance ) {
                    distance = dd;
                }
                lastPail = curP;
            }
        }

        return (int)distance;
    }

    class Pail{
        long max = -1;
        long min = -1;

        @Override
        public String toString() {
            return "[max="+max+"][min="+min+"]";
        }
    }
}
```
