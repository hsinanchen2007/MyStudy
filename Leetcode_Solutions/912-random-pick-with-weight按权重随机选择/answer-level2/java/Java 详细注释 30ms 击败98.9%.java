```
class Solution {

    int[] addUps;
    Random random = new Random();

    public Solution(int[] w) {

        addUps = new int[w.length]; //千万不要对数组w进行排序，否则就打乱了原有数据的概率分布

        addUps[0] = w[0];
        for(int i = 0; i < w.length-1; i++) { //累积和 放入数组addUps
            addUps[i+1] = addUps[i] + w[i+1];
        }

    }

    public int pickIndex() {
        int maxBound = addUps[addUps.length-1];

        int x = random.nextInt(maxBound); //生成的随机数，范围为[0, maxBound)

        return binarySearch(x); //二分查找
    }

    private int binarySearch(int x) { //返回第一个大于x的下标
        int low = 0;
        int high = addUps.length-1;

        while (low <= high) {
            int mid = low + ((high - low)>>1); //右移1位，相当于除以2。即 low + (high-low)/2，即相当于(high+low)/2

            if(addUps[mid] > x) {
                if(mid == 0 || addUps[mid-1] <= x) { //返回第一个大于x的下标
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return -1; //没有查找到
    }
}
```
