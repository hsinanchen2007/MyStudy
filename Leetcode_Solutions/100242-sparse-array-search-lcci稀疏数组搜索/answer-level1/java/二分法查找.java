### 解题思路

![image.png](https://pic.leetcode-cn.com/42e21bc5fb14b24881309c428ce565f9f1b6532f51918b2e3ddd9af95e7030f1-image.png)

1. 通过字符串长度可以得出，哈希表会超出指定内存
2. 只能使用二分法进行查找，但是如果words[mid] == ""的话，需要在不越界的情况左右移动找出最近的有效值作为mid
3. 需要使用字符串的比较大小，使用默认的比较即可
4. 最终左右指针结束后返回-1


### 代码

```java
class Solution {
    public int findString(String[] words, String s) {
        int start = 0;
        int end = words.length - 1;
        while (start <= end) {
            // 临时中间节点
            int tempMid = start + ((end - start) >> 1);
            int mid = -1;
            if (!isNotNull(words[tempMid])) {
                // 一直向后查找
                int org = tempMid;
                while (true) {
                    boolean endIsDone = false;
                    if (tempMid <= end) {
                        if (!isNotNull(words[tempMid])) {
                            tempMid++;
                        } else {
                            mid = tempMid;
                            break;
                        }
                    } else {
                        endIsDone = true;
                    }
                    if (org >= start) {
                        if (!isNotNull(words[org])) {
                            org--;
                        } else {
                            mid = org;
                            break;
                        }
                    } else {
                        if (endIsDone) {
                            // 前后都没有合适的字符串
                            return -1;
                        }
                    }

                }
            } else {
                // 有效位
                mid = tempMid;
            }
            // 没有找到有效值
            if (mid == -1) {
                return -1;
            }
            String v = words[mid];
            int i = s.compareTo(v);
            if (i == 0) {
                return mid;
            } else if (i > 0) {
                start = mid + 1;
            } else if (i < 0) {
                end = mid - 1;
            }
        }
        return -1;
    }

     /**
     * 判断字符串有效
     * @param s
     * @return
     */
    private boolean isNotNull(String s) {
        return !"".equals(s);
    }
}
```