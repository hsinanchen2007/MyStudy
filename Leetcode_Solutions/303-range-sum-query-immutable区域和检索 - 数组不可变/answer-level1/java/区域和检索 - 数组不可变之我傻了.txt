解法一：

这是从动态规划里切进来的一道题，刚看到此题，我还有点疑惑，暴力解法的时间复杂度也没多高啊， O(N) 的时间复杂度，很快的嘛！于是就直接暴力莽了一发：

    class NumArray {
        int[] nums;
        public NumArray(int[] nums) {
            this.nums = nums.clone();
        }
        
        public int sumRange(int i, int j) {
            int sum = 0;
            while (i <= j) {
                sum += nums[i++];
            }
            return sum;
        }
    }

然后 275s ，我傻了！

解法二：

多次调用 sumRange 方法果然够狠！然后想了想，动规的思想不就是存储中间值吗？得，先搞个表，到时候直接返回岂不是美滋滋？

    class NumArray {
        int[][] ret;
        public NumArray(int[] nums) {
            ret = new int[nums.length][nums.length];
            for (int m = 0; m < nums.length; m++) {
                for (int n = m; n < nums.length; n++) {
                    if (m == n) ret[m][n] = nums[m];
                    else
                        ret[m][n] = ret[m][n-1] + nums[n];
                }
            }
        }
        
        public int sumRange(int i, int j) {        
            return ret[i][j];
        }
    }

然后 超出内存限制 ，我又傻了！

解法三：

我可以的，我决定利用 hashmap 进行存储，这样就能少一半空间了啊！但是思来想去，也没想出怎么让 hashmap 有一对 key，于是我决定看看官方题解：

    class NumArray {
        private Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();
    
        public NumArray(int[] nums) {
            for (int i = 0; i < nums.length; i++) {
                int sum = 0;
                for (int j = i; j < nums.length; j++) {
                    sum += nums[j];
                    map.put(Pair.create(i, j), sum);
                }
            }
        }
    
        public int sumRange(int i, int j) {
            return map.get(Pair.create(i, j));
        }
    }

不愧是官方题解，还能这么写？Ctrl+c 然后 Ctrl+v ，运行之后竟然直接编译错误，我觉得自己就像个傻子。。。

解法四：

我的小脑瓜疯狂运转，妄图搞出一个最佳答案，奈何一片空！于是，我又看了官方题解，妙啊！不愧是官方题解！这才是动态规划的终极形态啊！

    class NumArray {
        int[] sum;
        public NumArray(int[] nums) {
            sum = new int[nums.length+1];
            for (int i = 0; i < nums.length; i++) {
                sum[i+1] = sum[i] + nums[i];
            }
        }
        
        public int sumRange(int i, int j) {
            return sum[j+1] - sum[i];
        }
    }

我真傻，真的！

后记：

- 搜了好多，也没找到类似官方的那种写法，不知道是不是伪码。
- 后两种的解法思路源于官方题解。
