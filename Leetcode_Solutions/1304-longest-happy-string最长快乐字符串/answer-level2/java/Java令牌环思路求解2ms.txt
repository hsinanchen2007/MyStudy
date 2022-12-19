![image.png](https://pic.leetcode-cn.com/e1a66cfe901b1c1878654dbcd6cf2473b7b2c5536f8971c33745baae08c17a73-image.png)

复杂度O(n)，可以推广至任意有限参数个数和有限重复次数

*总体思路是：设置一个令牌标记，如果该令牌有效，则添加至结果，否则为null，退出循环*

将所给参数a,b,c...视为不同种类的资源，其数值对应该资源的数目，当该资源数目大于0，且没有更高优先级资源抢占（此处更高优先级的意思是：存在其他资源数目大于或等于当前资源数），且已输出的资源数目不超过重复次数限制（此处为2），则令牌有效，反之，需要转移令牌，直至满足退出循环的条件

转移令牌前，需要清理前一个获得令牌资源的环境，即已输出的资源数目次数
转移令牌后，需要对当前资源的环境做处理

**代码如下**

    public String longestDiverseString(int a, int b, int c) {
        StringBuffer result = new StringBuffer();
        // 准备工作环境
        int[] nums = {a,b,c};
        Map<Character, Integer> tokenNumMap = new HashMap<>();
        tokenNumMap.put('a', 0);
        tokenNumMap.put('b', 0);
        tokenNumMap.put('c', 0);
        Map<Integer, Character> tokenMap = new HashMap<>();
        tokenMap.put(0, 'a');
        tokenMap.put(1, 'b');
        tokenMap.put(2, 'c');
        Map<Character, Integer> tokenIndex = new HashMap<>();
        tokenIndex.put('a', 0);
        tokenIndex.put('b', 1);
        tokenIndex.put('c', 2);
        // 找到最大值，作为初始化令牌获得者
        Character token = tokenMap.get(getMaxIndex(nums, -1));
        token = transferToken(nums, tokenNumMap, tokenIndex, tokenMap, token);
        while (token != null) {
            result.append(token);
            token = transferToken(nums, tokenNumMap, tokenIndex, tokenMap, token);
        }
        return new String(result);
    }

    private Character transferToken(int[] nums, Map<Character, Integer> tokenNumMap, Map<Character, Integer> tokenIndex, Map<Integer, Character> tokenMap, Character token) {
        // 发生令牌转移有两种情况，一种是本轮次数耗尽，另一种是有更高的优先级抢占
        int index = getMaxIndex(nums, -1);
        int count;
        if (index != tokenIndex.get(token)) {
            // 更高的优先级抢占，需清理被抢占的资源的使用次数，此时index即更高优先级资源的索引
            count = 0;
            tokenNumMap.put(token, count);
        } else if (tokenNumMap.get(token) >= 2) {
            // 次数耗尽，此时显然应该在当前token的index之外的剩下元素中寻找最大值，更新获得令牌的index，同样需清理被抢占的资源的使用次数
            index = getMaxIndex(nums, tokenIndex.get(token));
            count = 0;
            tokenNumMap.put(token, count);
        } else {
            // 令牌未转移，继续保持
        }
        if (nums[index] == 0) {
            // 此时表示获得令牌的资源，数目已经耗尽，可以退出循环
            return null;
        }
        // 处理获得令牌的资源
        token = tokenMap.get(index);
        nums[index]--;
        count = tokenNumMap.get(token);
        count++;
        tokenNumMap.put(token, count);
        return token;
    }

    private int getMaxIndex(int[] nums, int exclude) {
        int max = Integer.MIN_VALUE;
        int index = -1;
        for (int i = 0; i < nums.length; i++) {
            if (i != exclude && nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }