思路：
先对数组排序
定义一个Point结构 保存 当前点的最大整除子集的个数和前一个点的索引值
然后定义dp数组，dp[0]的最大整除子集的个数 = 1  因为该子集只有它本身  dp[0]的前一个点的索引值 = -1
开始循环，查找 当前点之前的点中 能被当前点整除，而且最大整除子集的个数+1大于 当前点的最大整除子集的个数  ，找到就记录
根据dp中找到的最大整除子集的个数的索引值，一个一个放到list中，return list

代码：
    public class Point {
        public int dis;
        public int preIndex;
        Point() {
            dis = 1;
            preIndex = -1;
        }
    }

    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums == null || nums.length <= 0) {
            return Collections.emptyList();
        }
        if (nums.length == 1) {
            List<Integer> res = new ArrayList<>();
            res.add(nums[0]);
            return res;
        }

        Arrays.sort(nums);

        Point[] dp = new Point[nums.length];
        dp[0] = new Point();

        int maxIndex = 0;

        for (int i = 1; i < nums.length; i++) {
            dp[i] = new Point();
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[i] % nums[j] == 0) && (dp[j].dis + 1 > dp[i].dis)) {
                    dp[i].dis = 1 + dp[j].dis;
                    dp[i].preIndex = j;
                }
            }
            if (dp[i].dis > dp[maxIndex].dis) {
                maxIndex = i;
            }
        }

        List<Integer> res = new ArrayList<>();
        while (dp[maxIndex].preIndex != -1) {
            res.add(nums[maxIndex]);
            maxIndex = dp[maxIndex].preIndex;
        }
        res.add(nums[maxIndex]);
        Collections.reverse(res);
        return res;
    }