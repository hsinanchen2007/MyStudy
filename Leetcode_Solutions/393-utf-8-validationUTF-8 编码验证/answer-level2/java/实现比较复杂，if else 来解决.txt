### 解题思路
实现比较复杂，if else 来解决

### 代码

```实现比较复杂，if else 来解决
class Solution {
    public boolean validUtf8(int[] data) {
            
         if (data == null || data.length == 0) {
            return false;
        }

        if (data.length == 1) {
            String curStr = Integer.toBinaryString(data[0]);
            if (curStr.startsWith("1") && curStr.length() == 8) {
                return false;
            }
        }

        int i = 0;
        for (; i < data.length; i++) {
            // 整型转换为二进制
            String curStr = Integer.toBinaryString(data[i]);
            
            if (curStr.length() < 8) {// 说明首位是0，例如  “100”
                continue;
            }

            if (curStr.startsWith("10")) {
                return false;
            }

            int count = 0;
            if (curStr.startsWith("1")) {
                for (int j = 0; j < curStr.length(); j++) {
                    if (curStr.charAt(j) == '1') {
                        count++;
                    } else {
                        break;
                    }
                }

                if (count > 4) {
                    return false;
                }

                // 接下来的count-1 个字节以 10打头
                int t = 1;
                while (t < count) {
                    if (i + t > data.length - 1) {
                        return false;
                    }
                    String nextStr = Integer.toBinaryString(data[i + t]);
                    if (!nextStr.startsWith("10") || nextStr.length() != 8) {
                        return false;
                    }
                    t++;
                }
                i += count - 1; //处理到最后一个元素的下标

                if (i >= data.length) {
                    return false;
                }
            }
        }
        if (i >= data.length) {
            return true;
        }
        return false;
    }
}
```