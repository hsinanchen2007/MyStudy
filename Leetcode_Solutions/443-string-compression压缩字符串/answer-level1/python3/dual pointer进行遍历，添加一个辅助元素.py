**算法思路：**
**本题隐含的条件是：压缩后的字符数组长度恒小于等于压缩前的字符数组长度，可放心使用原地算法。**

**For py solution:**
1. 先为了把全部元素都进行原地修改，添加`一个辅助元素`
2. 设置一个`指针pos`用于指向`原地修改的位置`，设置一个`指针i`指向`当前的元素`；`计数器count`计算每次元素`重复次数`；
3. 依次把`当前的元素`和`后面的元素`比较:
    - `在不相同情况下`
        - 不相同就把`后面的元素加入`到这个表里面，`pos + 1`；
        - 然后判断这时候的`count是否大于1`，`如果大于1`把count`转化`成字符串加入进去，同时`修改pos指针`，`使其大小等于修改后的表长`；
        注意：这时候`不需要`对`count等于1`进行处理（如题目`示例2`）
    - `在相同情况下`
        - 直接`移动指针i`即可,count进行累加
4. 最终返回表长，即`pos指向的位置`，完成算法。

**For JAVA solution:（比较推荐，有必要记录一下）**
使用快慢指针，两者的值进行比较，相同就直接前移快指针，直到不同（或者全部遍历完成，这个条件放在前面）。不同时候，重复次数可用j-i求出。
```python []
class Solution:
    def compress(self, chars: List[str]) -> int:
        # 仅一个元素返回列表的长度
        if len(chars) == 1: return len(chars)
        # 增加一个辅助元素，把原始数组全部添加到新的表里面；pos指向的是新表要添加元素的位置（而且表示表长）
        chars.append('')
        count, pos = 1, 0
        for i in range(1,len(chars)):
            if chars[i] != chars[i-1]:
                chars[pos] = chars[i-1]
                pos += 1
                if count > 1:
                    for j in range(len(str(count))):
                        chars[pos + j] = str(count)[j]
                    pos += len(str(count))
                count = 1
            else:
                count += 1
        return pos # 返回最终的表长
```
```Java []
class Solution {
    public int compress(char[] chars) {
        int pos = 0;
        int i = 0;
        while (i < chars.length) {
            int j = i + 1;
            chars[pos++] = chars[i]; 
            // 防止溢出，第一个条件必须在前
            while (j < chars.length && chars[i] == chars[j]) {
                j++;
            }
            // 次数大于1，加入相应字符
            if (j - i > 1) {
                for (char c : String.valueOf(j-i).toCharArray()) {
                    chars[pos++] = c;
                }
            }
            // 直接移动i到j的位置
            i = j;
        }
        return pos;
    }
}


