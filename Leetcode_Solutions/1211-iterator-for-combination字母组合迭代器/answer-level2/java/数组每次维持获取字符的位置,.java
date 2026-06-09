### 解题思路
此处撰写解题思路

***用一个长度为 combinationLength 的数组去维持是否能获取下一个下一个字符串***

- 用一个数组去记录,只需要记录下一次获取字符串的位置,当获取调用next()时就对数组进行更新操作

![数组.jpg](https://pic.leetcode-cn.com/083fdf640680e252aa4a791850833b8bf8d127262ad78c54587bf48ae34b54ab-%E6%95%B0%E7%BB%84.jpg)


### 代码

```java
class CombinationIterator {
        // 数组维持选取字符的位置
        int[] arr;
        String characters;

        public CombinationIterator(String characters, int combinationLength) {
            arr = new int[combinationLength];
            for (int i = 0; i < combinationLength; i++) {
                arr[i] = i;
            }
            this.characters = characters;
        }

        public String next() {
            String sing = "";
            for (int o : arr) {
                sing += characters.charAt(o);
            }
            // 数组, 处理的位置, 字符串长度(计算数组取值是否越界)  
            comp(arr, arr.length - 1, characters.length());
            return sing;
        }

        //递归修改数组的值
         private void comp(int[] arr, int len, int var) {
                //目标位置已经到最大值,递归处理上一位值
            if (arr[len] + 1 >= var || arr[len] + 1 >= var - (arr.length - len -1)) {
                if (len == 0) {
                    arr[len] = characters.length() + 1;
                    return;
                }
                comp(arr, len - 1, var);
                arr[len] = arr[len - 1] + 1;
            } else {
                arr[len] = arr[len] + 1;
            }
        }

        public boolean hasNext() {
                if (arr[0] > characters.length() - arr.length) {
                    return false;
                }
            return true;
        }
    }
```


![WX20191215-041847@2x.png](https://pic.leetcode-cn.com/fda154b4d5322699e4b83cc31cdb717493828fe6355e43465cdba8ca66ca037f-WX20191215-041847@2x.png)