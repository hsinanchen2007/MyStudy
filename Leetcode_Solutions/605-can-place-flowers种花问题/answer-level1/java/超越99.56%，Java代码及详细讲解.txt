### 简单一次循环高效解决问题
**解题思路**：遍历flowerbed[]数组，依次判断各位置是否适合种花，**判断的标准**是当前位置为0，且前一位置为0或其下标为-1，且后一位置为0或其下标为flowerbed.length。若判断为真，则修改flowerbed[]数组当前位置为1，n--。最后若n<=0,则能种下所有花。
```java
public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0 
            && (i - 1 == -1 || flowerbed[i - 1] == 0) 
            && (i + 1 == flowerbed.length || flowerbed[i + 1] == 0)) {
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }

```