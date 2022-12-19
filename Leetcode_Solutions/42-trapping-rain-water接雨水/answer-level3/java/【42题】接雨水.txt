**题意分析：**
(1) 只有能组成容器的两个柱子之间才可以接雨水，就是指长度至少为 3 且中间部分低于边界柱子。
(2) 每个可以接雨水区间的接水量取决于构成容器的短板。
*** 可以根据哈希表、动态规划和栈三种思维考虑。

**方法一：哈希表**
思路：
(1) 从左向右遍历可以组成容器的区间。
(2) 根据哈希表记录剩余柱子中的最高点。
(3) 每个区间的节水量为根据边界短板和距离算出的总容量减去区间占用容量的矮柱子。
```
class Solution {	
	public int trap(int[] height) {
        int ans = 0;
        int len = height.length;
        if (len < 3) {
            return 0;
        }
        // 记录剩余部分的最高柱子。
        int maxRemain = 0;
        // 将所有柱子高度都存入哈希表。
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            if (height[i] > maxRemain) {
                maxRemain = height[i];
            }
            if (map.containsKey(height[i])){
                map.put(height[i],map.get(height[i]) + 1);
            } else  {
                map.put(height[i],1);
            }
        }
        int left = 0, right =  1;
        while (right < len) {
            int temp = 0;
            // 从哈希表中减去已经遍历过的位置。
            if (map.containsKey(height[left])) {
                map.put(height[left],map.get(height[left]) - 1);
            }
            // 找到剩余部分的最高柱子。
            while (!map.containsKey(maxRemain) || map.get(maxRemain) <= 0) {
                maxRemain -= 1;
            }
            // 如果指向的柱子高度小于左边界柱子且小于剩余最高柱子高度，则容器区间递增。
            while (height[right] < height[left] && height[right] < maxRemain) {
                // 从哈希表中减去已经遍历过的位置。
                map.put(height[right],map.get(height[right]) - 1);
                // 提前减去容器中占容量的柱子。
                temp += 0 - height[right];
                right++;
            }
            // 根据短板思维计算容器容量，计算完成后从右边界柱子开始继续遍历。
            ans += (right - left - 1) * Math.min(height[left],height[right]) + temp;
            left = right;
            right = left + 1;
        }
        return ans;
    }
}
```

**方法二：动态规划**
思路：
(1) 除了左右两边界以外所有柱子位置都有可能接到雨水。
(2) 将可能接到雨水的位置分成单独的一列一列分别计算接到的雨水量。
(3) 在每个位置左边的最高柱子和右边的最高柱子以及当前位置的高度决定了每个位置的接水量。
    如果平移左右两边最高柱子到最近两边可以组成容器则计算接水量，否则不能接水遍历下一个位置。
```
class Solution {	
	public int trap(int[] height) {
        int ans = 0;
        int len = height.length;
        if (len < 3) {
            return 0;
        }
        int max_left = 0;
        int[] max_right = new int[len];
        // 动态规划记录每个位置右边最高的柱子，除去边界。
        for (int i = len - 2; i > 0; i--) {
            max_right[i] = Math.max(max_right[i + 1], height[i + 1]);
        }
        // 除去边界，遍历每个位置，按短板思维计算雨水容量。
        for (int i = 1; i < len - 1; i++) {
            // 动态规划得到每个位置左边最高的柱子。
            max_left = Math.max(max_left, height[i - 1]);
            int min = Math.min(max_left, max_right[i]);
            if (min > height[i]) {
                ans = ans + (min - height[i]);
            }
        }
        return ans;
    }
}
```

**方法三：栈**
思路：
(1) 从低往高一层层计算。
(2) 利用栈记录可能构成容器的左边柱子的位置，通过出栈得到矩形容器的底。
*** 核心思想就是每个容器从低往高根据宽度和深度组成的矩形面积依次叠加。
```
class Solution {	
	public int trap(int[] height) {
        int ans = 0;
        int len = height.length;
        if (len < 3) {
            return 0;
        }
        // 存可能储水柱子左边的位置。
        Stack<Integer> stack = new Stack<>();
        int current = 0;
        while (current < len) {
            // 如果栈不空并且当前指向的高度大于栈顶高度就循环计算当栈顶位置为底每一层的接水量。
            while (!stack.empty() && height[current] > height[stack.peek()]) {
                // 取出要出栈的位置的高度。
                int high = height[stack.peek()];
                // 将栈顶的位置出栈。
                stack.pop();
                // 栈空说明前一位置的左边没有比自己高的柱子，跳出循环。
                if (stack.empty()) {
                    break; 
                }
                // 左边最高柱子到当前柱子之前的距离。
                int d = current - stack.peek() - 1;
                // 根据当前柱子和左边最高柱子中比较低的一边，配合栈顶取出的高度计算矩形容器接水量。
                int min = Math.min(height[stack.peek()], height[current]);。
                ans = ans + d * (min - high);
            }
            // 当前指向的柱子位置入栈。
            stack.push(current);
            // 指针后移。
            current++;
        }
        return ans;
    }
}
```
