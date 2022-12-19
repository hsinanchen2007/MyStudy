### 解析
像这种题目关键在于理解题目的意思，寻找出等价的说法，就好理解了。

首先我们知道，所有的字符串都是由小写的英文字母组成的。

然后我们要找的是什么？

假设字母'a'在上面的字符串数组中的每个字符串中出现的次数为[a1, a2, a3...],其中最小值是min(a1, a2, a3...),那么我们最终返回的数组中应该包含min(a1, a2, a3...)个字母a。

同理，对于字母'b','c','d'是一样的。

所以我们自要找到每个字母在每个字符串中出现的次数的最小值，就行了。

在示例1中，
- 'a' 在每个字符串中出现的次数为[1,1,0],所以最终的结果中a出现的此物应该为0；
- 'b' 在每个字符串中出现的次数为[1,1,0],所以最终的结果中a出现的此物应该为0；
...
- 'e' 在每个字符串中出现的次数为[1,1,1],所以最终的结果中a出现的此物应该为1；
...
- 'l' 在每个字符串中出现的次数为[2,2,2],所以最终的结果中a出现的此物应该为2；
...

所以最终的结果中，e应该出现1次，l应该出现2次。然后就有了我们最终的结果["e","l","l"]了。

然后这个题目的标签中有`哈希表`这个标签。但是我们知道，如果一个哈希表的键的数量有限，我们是可以使用数组来代替它的，毕竟数组中每个元素的索引都可以看做是哈希表的键。所以这一题我们用数组来做，可以提高性能。

思路很明确：
- 统计每个英文字母在数组中的每个字符串中出现的次数
- 计算出最小值，这个最小值就是我们最终结果中该字母应该出现的次数
- 将上面的结果，转化成题目要求的字符串列表。

### 伪代码
// todo

### Java
首先我们定义一个二维数组
``` java
int[][] array = new int[26][A.length]
```
- 第一维度的长度为26，代表26个字母
- 第二维度的长度为A.length，代表当前字母在某个字符串中出现的次数
- array[1][2]表示字母b在第3个字符串中出现的次数。

```java
class Solution {
    public List<String> commonChars(String[] A) {
        int[][] arr = new int[26][A.length];

        // 双重循环来遍历数组中的每个字母
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length(); j++) {
                char currentChar = A[i].charAt(j);

                // 字母每出现一次，就在上面定义的arr的对应位置记录一下
                arr[currentChar - 97][i]++;
            }
        }

        // 这个数组存储每个字母出现的最小次数
        int[] charMinArray = new int[26];
        for (int i = 0; i < 26; i++) {
            charMinArray[i] = getMinValue(arr[i]);
        }

        return toStringList(charMinArray);
    }

    /**
     * 得到数组中元素的最小值
     * @param arr
     * @return
     */
    private int getMinValue(int[] arr){
        int minValue = arr[0];
        for (int i = 1; i < arr.length; i++) {
            minValue = arr[i] > minValue ? minValue : arr[i];
        }
        return minValue;
    }

    /**
     * 将int数组转化为list
     * [1, 2] --> ["a", "b", "b"]
     * [0,1,0,1] --> ["b", "d"]
     * @param arr: 长度固定位26
     * @return: 字符数组
     */
    private List<String> toStringList(int[] arr){
        List<String> list = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i]; j++) {
                // 将int类型转换为对应的char类型
                char c = (char)(i + 97);

                list.add(String.valueOf(c));
            }
        }
        return list;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] strings = new String[3];
        strings[0] = "cool";
        strings[1] = "lock";
        strings[2] = "cook";

        System.out.println(solution.commonChars(strings));
    }
}
```

https://github.com/fish-stack/AlgoMath/issues/7