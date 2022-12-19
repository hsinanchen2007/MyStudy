```
class Solution {
    public int maximumSwap(int num) {
        // 准备两个数组，chars1 是排序后的数组，chars2 是原来顺序
        char[] chars1 = String.valueOf(num).toCharArray();
        char[] chars2 = chars1.clone();
        Arrays.sort(chars1);
        
        for (int i = 0; i < chars1.length; i++) {
            // 始终选择最大的数字放第一位，第二大的放第二位，以此类推
            // 如果对应位置上的数字不是按大小顺序对应的数字
            if (chars2[i] != chars1[chars1.length - i - 1]) {
                // 交换此时 chars2[i] 与原本应该在这个位置上的值
                for (int j = chars1.length - 1; j > i; j--) {
                    // 从后往前遍历，找到第一个原本应该出现在该位置上的值
                    if (chars2[j] == chars1[chars1.length - i - 1]) {
                        // 将两个位置上的值交换下，结束循环
                        chars2[j] = chars2[i];
                        chars2[i] = chars1[chars1.length - i - 1];
                        break;
                    }
                }
                break;
            }
        }

        return Integer.parseInt(new String(chars2));
    }
}
```
